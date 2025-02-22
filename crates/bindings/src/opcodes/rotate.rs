use num_enum::{IntoPrimitive, TryFromPrimitive};
use std::fmt;
/// RR r8
/// Rotate bits in register r8 right through carry.
/// RR [HL]
/// Rotate byte pointed to by HL right through carry.
/// RRA
/// Rotate register A right through carry.
///
/// C -> [7 -> 0] -> C

/// RRC r8
/// Rotate register r8 right.
/// RRC [HL]
/// Rotate byte pointed to by HL right.
/// RRCA
/// Rotate register A right.
///
/// C -> [7 -> 0] -> [7]

/// LR r8
/// Rotate bits in register r8 left through carry.
/// LR [HL]
/// Rotate byte pointed to by HL left through carry.
/// LRA
/// Rotate register A left through carry.
///
/// C <- [7 <- 0] <- C

/// LRC r8
/// Rotate register r8 left.
/// LRC [HL]
/// Rotate byte pointed to by HL left.
/// LRCA
/// Rotate register A left.
///
/// C <- [7 <- 0] <- [7]

/// Cycles: 8 | 16 for [HL]
///
/// Bytes: 2 | 4 for [HL]
///
/// Flags:
///
/// Z - Set if result is 0.
/// N - Unused
/// H - Unused
/// C - Set according to result.

#[derive(Eq, PartialEq, TryFromPrimitive, IntoPrimitive, Clone, Copy)]
#[repr(u8)]
#[allow(clippy::upper_case_acronyms)]
pub enum Rotate {
    LCB = 0x00,
    LCC = 0x01,
    LCD = 0x02,
    LCE = 0x03,
    LCH = 0x04,
    LCL = 0x05,
    LCHL = 0x06,
    LCA = 0x07,
    LB = 0x10,
    LC = 0x11,
    LD = 0x12,
    LE = 0x13,
    LH = 0x14,
    LL = 0x15,
    LHL = 0x16,
    LA = 0x17,
    RCB = 0x08,
    RCC = 0x09,
    RCD = 0x0A,
    RCE = 0x0B,
    RCH = 0x0C,
    RCL = 0x0D,
    RCHL = 0x0E,
    RCA = 0x0F,
    RB = 0x18,
    RC = 0x19,
    RD = 0x1A,
    RE = 0x1B,
    RH = 0x1C,
    RL = 0x1D,
    RHL = 0x1E,
    RA = 0x1F,
}

impl fmt::Display for Rotate {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Rotate::LCB => write!(f, "Rotate L B"),
            Rotate::LCC => write!(f, "Rotate L C"),
            Rotate::LCD => write!(f, "Rotate L D"),
            Rotate::LCE => write!(f, "Rotate L E"),
            Rotate::LCH => write!(f, "Rotate L H"),
            Rotate::LCL => write!(f, "Rotate L L"),
            Rotate::LCHL => write!(f, "Rotate L L"),
            Rotate::LCA => write!(f, "Rotate L A"),
            Rotate::LB => write!(f, "Rotate L (Carry) B"),
            Rotate::LC => write!(f, "Rotate L (Carry) C"),
            Rotate::LD => write!(f, "Rotate L (Carry) D"),
            Rotate::LE => write!(f, "Rotate L (Carry) E"),
            Rotate::LH => write!(f, "Rotate L (Carry) H"),
            Rotate::LL => write!(f, "Rotate L (Carry) L"),
            Rotate::LHL => write!(f, "Rotate L (Carry) [HL]"),
            Rotate::LA => write!(f, "Rotate L (Carry) A"),
            Rotate::RCB => write!(f, "Rotate R (Carry) B"),
            Rotate::RCC => write!(f, "Rotate R (Carry) C"),
            Rotate::RCD => write!(f, "Rotate R (Carry) D"),
            Rotate::RCE => write!(f, "Rotate R (Carry) E"),
            Rotate::RCH => write!(f, "Rotate R (Carry) H"),
            Rotate::RCL => write!(f, "Rotate R (Carry) L"),
            Rotate::RCHL => write!(f, "Rotate R (Carry) [HL]"),
            Rotate::RCA => write!(f, "Rotate R (Carry) A"),
            Rotate::RB => write!(f, "Rotate R B"),
            Rotate::RC => write!(f, "Rotate R C"),
            Rotate::RD => write!(f, "Rotate R D"),
            Rotate::RE => write!(f, "Rotate R E"),
            Rotate::RH => write!(f, "Rotate R H"),
            Rotate::RL => write!(f, "Rotate R L"),
            Rotate::RHL => write!(f, "Rotate R [HL]"),
            Rotate::RA => write!(f, "Rotate R A"),
        }
    }
}
