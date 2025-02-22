use anyhow::Result;
use bindings::{gb, system::Mode};
use iced_wgpu::wgpu::Instance;
use iced_winit::winit::event::{Event, StartCause, WindowEvent};
use iced_winit::winit::event_loop::{ControlFlow, EventLoop};
use std::{cell::RefCell, sync::Arc};

use crate::{debugger, emulator};

#[derive(Debug, Default)]
pub struct System {
    mode: Arc<RefCell<Mode>>,
}

pub enum Process {
    Refresh,
    Pause,
    Idle,
    Exit,
}

struct Marker {}
impl Drop for Marker {
    fn drop(&mut self) {
        println!("Successfuly cleaning!");
        gb::cleanup();
    }
}

impl System {
    pub fn try_new(rom: String, mode: String) -> Result<Self> {
        let system = Self::default();
        match gb::init(rom, mode) {
            Ok(_) => println!("Successfull Load"),
            Err(_) => println!("Invalid Rom"),
        }
        Ok(system)
    }

    pub fn run(mut self) {
        let event_loop = EventLoop::new();
        let marker = Marker {};

        //let mut debugger = debugger::Debugger::new(&event_loop, &instance, soc.clone());
        let instance = Instance::new(iced_wgpu::wgpu::Backends::PRIMARY);
        let mut debugger = debugger::Debugger::new(&event_loop, &instance, self.mode.clone());
        let mut emulator = emulator::Emulator::new(&event_loop);
        debugger.update();
        event_loop.run(move |event, _, flow| {
            let _mark = &marker;
            // Handle Events
            match event {
                Event::NewEvents(StartCause::Init) => {}
                Event::WindowEvent {
                    event,
                    window_id: _,
                } if matches!(&event, WindowEvent::DroppedFile(_)) => {
                    if let WindowEvent::DroppedFile(rom) = event {
                        let file = rom.into_os_string().into_string().unwrap();
                        gb::cleanup();
                        match gb::init(file, "auto".to_string()) {
                            Ok(_) => println!("Rom loaded"),
                            Err(_) => println!("Invalid file"),
                        }
                        debugger.reload();
                        *self.mode.borrow_mut() = Mode::Run;
                    }
                },
                Event::WindowEvent { event, window_id } if window_id == debugger.id => {
                    debugger.process_event(event, flow);
                }
                Event::WindowEvent { event, window_id } if window_id == emulator.id => {
                    emulator.process_event(event, flow);
                }
                Event::MainEventsCleared => {
                    // Run Emulator here
                    match self.process() {
                        Process::Refresh => {
                            emulator.request_redraw();
                        }
                        Process::Idle => {}
                        Process::Exit => {
                            *flow = ControlFlow::Exit;
                        }
                        Process::Pause => {
                            debugger.refresh();
                        }
                    }
                    debugger.update();
                }
                Event::RedrawRequested(window_id) if window_id == debugger.id => {
                    debugger.redraw();
                }
                Event::RedrawRequested(window_id) if window_id == emulator.id => {
                    emulator.redraw(flow);
                }
                _ => (),
            };
        })
    }

    pub fn process(&mut self) -> Process {
        let mode = *self.mode.borrow();
        match mode {
            Mode::Instruction => {
                *self.mode.borrow_mut() = Mode::Pause;
                match bindings::gb::step() {
                    Ok(_) => Process::Refresh,
                    Err(_) => Process::Exit,
                }
            }
            Mode::Run => {
                if gb::frame() {
                    Process::Refresh
                } else {
                    Process::Exit
                }
            }
            Mode::Pause => {
                *self.mode.borrow_mut() = Mode::Idle;
                Process::Pause
            }
            Mode::Frame => {
                *self.mode.borrow_mut() = Mode::Pause;
                if gb::frame() {
                    Process::Refresh
                } else {
                    Process::Exit
                }
            }
            Mode::Idle => Process::Idle,
        }
    }
}
