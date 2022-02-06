use num_enum::{IntoPrimitive, TryFromPrimitive};
use std::fmt;
/// RESET n, r8 | [HL]
/// Set bit n in register r8 or at address [HL] to 0.
///
/// Cycles: 8 | 16
///
/// Bytes: 2
///
/// Flags: None affected.

#[derive(Eq, PartialEq, TryFromPrimitive, IntoPrimitive, Clone, Copy)]
#[repr(u8)]
#[allow(clippy::upper_case_acronyms)]
pub enum Reset {
    BBit0 = 0x80,
    BBit1 = 0x88,
    BBit2 = 0x90,
    BBit3 = 0x98,
    BBit4 = 0xA0,
    BBit5 = 0xA8,
    BBit6 = 0xB0,
    BBit7 = 0xB8,
    CBit0 = 0x81,
    CBit1 = 0x89,
    CBit2 = 0x91,
    CBit3 = 0x99,
    CBit4 = 0xA1,
    CBit5 = 0xA9,
    CBit6 = 0xB1,
    CBit7 = 0xB9,
    DBit0 = 0x82,
    DBit1 = 0x8A,
    DBit2 = 0x92,
    DBit3 = 0x9A,
    DBit4 = 0xA2,
    DBit5 = 0xAA,
    DBit6 = 0xB2,
    DBit7 = 0xBA,
    EBit0 = 0x83,
    EBit1 = 0x8B,
    EBit2 = 0x93,
    EBit3 = 0x9B,
    EBit4 = 0xA3,
    EBit5 = 0xAB,
    EBit6 = 0xB3,
    EBit7 = 0xBB,
    HBit0 = 0x84,
    HBit1 = 0x8C,
    HBit2 = 0x94,
    HBit3 = 0x9C,
    HBit4 = 0xA4,
    HBit5 = 0xAC,
    HBit6 = 0xB4,
    HBit7 = 0xBC,
    LBit0 = 0x85,
    LBit1 = 0x8D,
    LBit2 = 0x95,
    LBit3 = 0x9D,
    LBit4 = 0xA5,
    LBit5 = 0xAD,
    LBit6 = 0xB5,
    LBit7 = 0xBD,
    HLBit0 = 0x86,
    HLBit1 = 0x8E,
    HLBit2 = 0x96,
    HLBit3 = 0x9E,
    HLBit4 = 0xA6,
    HLBit5 = 0xAE,
    HLBit6 = 0xB6,
    HLBit7 = 0xBE,
    ABit0 = 0x87,
    ABit1 = 0x8F,
    ABit2 = 0x97,
    ABit3 = 0x9F,
    ABit4 = 0xA7,
    ABit5 = 0xAF,
    ABit6 = 0xB7,
    ABit7 = 0xBF,
}

impl fmt::Display for Reset {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Reset::BBit0 => write!(f, "RESET B, Bit 0"),
            Reset::BBit1 => write!(f, "RESET B, Bit 1"),
            Reset::BBit2 => write!(f, "RESET B, Bit 2"),
            Reset::BBit3 => write!(f, "RESET B, Bit 3"),
            Reset::BBit4 => write!(f, "RESET B, Bit 4"),
            Reset::BBit5 => write!(f, "RESET B, Bit 5"),
            Reset::BBit6 => write!(f, "RESET B, Bit 6"),
            Reset::BBit7 => write!(f, "RESET B, Bit 7"),
            Reset::CBit0 => write!(f, "RESET C, Bit 0"),
            Reset::CBit1 => write!(f, "RESET C, Bit 1"),
            Reset::CBit2 => write!(f, "RESET C, Bit 2"),
            Reset::CBit3 => write!(f, "RESET C, Bit 3"),
            Reset::CBit4 => write!(f, "RESET C, Bit 4"),
            Reset::CBit5 => write!(f, "RESET C, Bit 5"),
            Reset::CBit6 => write!(f, "RESET C, Bit 6"),
            Reset::CBit7 => write!(f, "RESET C, Bit 7"),
            Reset::DBit0 => write!(f, "RESET D, Bit 0"),
            Reset::DBit1 => write!(f, "RESET D, Bit 1"),
            Reset::DBit2 => write!(f, "RESET D, Bit 2"),
            Reset::DBit3 => write!(f, "RESET D, Bit 3"),
            Reset::DBit4 => write!(f, "RESET D, Bit 4"),
            Reset::DBit5 => write!(f, "RESET D, Bit 5"),
            Reset::DBit6 => write!(f, "RESET D, Bit 6"),
            Reset::DBit7 => write!(f, "RESET D, Bit 7"),
            Reset::EBit0 => write!(f, "RESET E, Bit 0"),
            Reset::EBit1 => write!(f, "RESET E, Bit 1"),
            Reset::EBit2 => write!(f, "RESET E, Bit 2"),
            Reset::EBit3 => write!(f, "RESET E, Bit 3"),
            Reset::EBit4 => write!(f, "RESET E, Bit 4"),
            Reset::EBit5 => write!(f, "RESET E, Bit 5"),
            Reset::EBit6 => write!(f, "RESET E, Bit 6"),
            Reset::EBit7 => write!(f, "RESET E, Bit 7"),
            Reset::HBit0 => write!(f, "RESET H, Bit 0"),
            Reset::HBit1 => write!(f, "RESET H, Bit 1"),
            Reset::HBit2 => write!(f, "RESET H, Bit 2"),
            Reset::HBit3 => write!(f, "RESET H, Bit 3"),
            Reset::HBit4 => write!(f, "RESET H, Bit 4"),
            Reset::HBit5 => write!(f, "RESET H, Bit 5"),
            Reset::HBit6 => write!(f, "RESET H, Bit 6"),
            Reset::HBit7 => write!(f, "RESET H, Bit 7"),
            Reset::LBit0 => write!(f, "RESET L, Bit 0"),
            Reset::LBit1 => write!(f, "RESET L, Bit 1"),
            Reset::LBit2 => write!(f, "RESET L, Bit 2"),
            Reset::LBit3 => write!(f, "RESET L, Bit 3"),
            Reset::LBit4 => write!(f, "RESET L, Bit 4"),
            Reset::LBit5 => write!(f, "RESET L, Bit 5"),
            Reset::LBit6 => write!(f, "RESET L, Bit 6"),
            Reset::LBit7 => write!(f, "RESET L, Bit 7"),
            Reset::HLBit0 => write!(f, "RESET [HL], Bit 0"),
            Reset::HLBit1 => write!(f, "RESET [HL], Bit 1"),
            Reset::HLBit2 => write!(f, "RESET [HL], Bit 2"),
            Reset::HLBit3 => write!(f, "RESET [HL], Bit 3"),
            Reset::HLBit4 => write!(f, "RESET [HL], Bit 4"),
            Reset::HLBit5 => write!(f, "RESET [HL], Bit 5"),
            Reset::HLBit6 => write!(f, "RESET [HL], Bit 6"),
            Reset::HLBit7 => write!(f, "RESET [HL], Bit 7"),
            Reset::ABit0 => write!(f, "RESET A, Bit 0"),
            Reset::ABit1 => write!(f, "RESET A, Bit 1"),
            Reset::ABit2 => write!(f, "RESET A, Bit 2"),
            Reset::ABit3 => write!(f, "RESET A, Bit 3"),
            Reset::ABit4 => write!(f, "RESET A, Bit 4"),
            Reset::ABit5 => write!(f, "RESET A, Bit 5"),
            Reset::ABit6 => write!(f, "RESET A, Bit 6"),
            Reset::ABit7 => write!(f, "RESET A, Bit 7"),
        }
    }
}
