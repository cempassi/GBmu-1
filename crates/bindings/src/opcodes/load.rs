use num_enum::{IntoPrimitive, TryFromPrimitive};
use std::fmt;
/// 2. LD r1,r2
/// Description:
///  Put value r2 into r1.
/// Use with:
///  r1,r2 = A,B,C,D,E,H,L
/// Opcodes:
/// Instruction Parameters Opcode Cycles
/// [LD A,A    7F 4]   [LD B,B    40 4]     [LD C,B    48 4]  [LD D,B    50 4]   [LD E,B    58 4] [LD H,B    60 4]  [LD L,B    68 4]
/// [LD A,B    78 4]   [LD B,C    41 4]     [LD C,C    49 4]  [LD D,C    51 4]   [LD E,C    59 4] [LD H,C    61 4]  [LD L,C    69 4]
/// [LD A,C    79 4]   [LD B,D    42 4]     [LD C,D    4A 4]  [LD D,D    52 4]   [LD E,D    5A 4] [LD H,D    62 4]  [LD L,D    6A 4]
/// [LD A,D    7A 4]   [LD B,E    43 4]     [LD C,E    4B 4]  [LD D,E    53 4]   [LD E,E    5B 4] [LD H,E    63 4]  [LD L,E    6B 4]
/// [LD A,E    7B 4]   [LD B,H    44 4]     [LD C,H    4C 4]  [LD D,H    54 4]   [LD E,H    5C 4] [LD H,H    64 4]  [LD L,H    6C 4]
/// [LD A,H    7C 4]   [LD B,L    45 4]     [LD C,L    4D 4]  [LD D,L    55 4]   [LD E,L    5D 4] [LD H,L    65 4]  [LD L,L    6D 4]
/// [LD A,L    7D 4]

/// 1. LD nn,n
/// Description:
///  Put value n into nn.
/// Use with:
///  nn = B,C,D,E,H,L,A
///  n = 8 bit immediate value
/// Opcodes:
/// Instruction Parameters Opcode Cycles
/// LD          B,n        0x06   8
/// LD          C,n        0x0e   8
/// LD          D,n        0x16   8
/// LD          E,n        0x1e   8
/// LD          H,n        0x26   8
/// LD          L,n        0x2e   8
/// LD          A,n        0x3e   8

/// LD n, (HL)
/// Description:
///  Put value (HL) into n.
/// Use with:
///  n = B,C,D,E,H,L,A
/// Opcodes:
/// Instruction Parameters Opcode Cycles
/// LD          B,(HL)     0x46   8
/// LD          C,(HL)     0x4E   8
/// LD          D,(HL)     0x56   8
/// LD          E,(HL)     0x5E   8
/// LD          H,(HL)     0x66   8
/// LD          L,(HL)     0x6E   8
/// LD          A,(HL)     0x7E   8

/// LD (HL), n
/// Description:
///  Put value n into (HL).
/// Use with:
///  n = B,C,D,E,H,L,A
/// Opcodes:
/// Instruction Parameters Opcode Cycles
///  LD          (HL),B     0x70     8
///  LD          (HL),C     0x71     8
///  LD          (HL),D     0x72     8
///  LD          (HL),E     0x73     8
///  LD          (HL),H     0x74     8
///  LD          (HL),L     0x75     8
///  LD          (HL),A     0x77     8

/// 1. LD HL,n
/// Description:
///  Put value n into HL.
/// Use with:
///  n = 8 bit immediate value
/// Opcodes:
/// Instruction Parameters Opcode Cycles
/// LD          (HL),n     0x36     12

/// 1. LD [r16], A
/// Description:
/// Store value in register A into byte pointed to by register r16.
/// Opcodes:
/// Instruction Parameters Opcode Cycles
/// LD          (BC), A     0x02     8
/// LD          (DE), A     0x12     8

/// 1. LD A, [r16]
/// Description:
/// Store value in byte pointed to by register r16 in register A .
/// Opcodes:
/// Instruction Parameters Opcode Cycles
/// LD          A, (BC)     0x0A     8
/// LD          A, (DE)     0x1A     8

/// 1. LD (HL+/-), A
/// Description:
/// Store value in register A into byte pointed to by register HL, then (increase/decrease) HL.
/// Opcodes:
/// Instruction Parameters Opcode Cycles
/// LD          (HL+), A     0x22     8
/// LD          (HL-), A     0x32     8

/// 1. LD A, (HL+/-)
/// Description:
/// Store value in byte pointed to by register (HL) in register A, then (increase/decrease) HL.
/// Opcodes:
/// Instruction Parameters Opcode Cycles
/// LD          A, (HL+)      0x2A     8
/// LD          A, (HL-)      0x3A     8
#[derive(Eq, PartialEq, TryFromPrimitive, IntoPrimitive)]
#[repr(u8)]
#[allow(clippy::upper_case_acronyms)]
pub enum Load {
    B8b = 0x06,
    C8b = 0x0e,
    D8b = 0x16,
    E8b = 0x1e,
    H8b = 0x26,
    L8b = 0x2e,
    A8b = 0x3e,
    AA = 0x7f,
    AB = 0x78,
    AC = 0x79,
    AD = 0x7a,
    AE = 0x7b,
    AH = 0x7c,
    AL = 0x7d,
    BB = 0x40,
    BC = 0x41,
    BD = 0x42,
    BE = 0x43,
    BH = 0x44,
    BL = 0x45,
    CB = 0x48,
    CC = 0x49,
    CD = 0x4a,
    CE = 0x4b,
    CH = 0x4c,
    CL = 0x4d,
    DB = 0x50,
    DC = 0x51,
    DD = 0x52,
    DE = 0x53,
    DH = 0x54,
    DL = 0x55,
    EB = 0x58,
    EC = 0x59,
    ED = 0x5A,
    EE = 0x5B,
    EH = 0x5C,
    EL = 0x5D,
    HB = 0x60,
    HC = 0x61,
    HD = 0x62,
    HE = 0x63,
    HH = 0x64,
    HL = 0x65,
    LB = 0x68,
    LC = 0x69,
    LD = 0x6A,
    LE = 0x6B,
    LH = 0x6C,
    LL = 0x6D,
    BHL = 0x46,
    CHL = 0x4E,
    DHL = 0x56,
    EHL = 0x5E,
    HHL = 0x66,
    LHL = 0x6E,
    AHL = 0x7E,
    HLB = 0x70,
    HLC = 0x71,
    HLD = 0x72,
    HLE = 0x73,
    HLH = 0x74,
    HLL = 0x75,
    HLA = 0x77,
    BA = 0x47,
    DA = 0x57,
    HA = 0x67,
    CA = 0x4F,
    EA = 0x5F,
    LA = 0x6F,
    HL8b = 0x36,
    BCA = 0x02,
    DEA = 0x12,
    ABC = 0x0A,
    ADE = 0x1A,
    HLPA = 0x22,
    HLMA = 0x32,
    AHLP = 0x2A,
    AHLM = 0x3A,
    ToIOC = 0xE2,
    IOC = 0xF2,
    ToIONext = 0xE0,
    IONext = 0xF0,
    AtNextA = 0xEA,
    AAtNext = 0xFA,
}

impl fmt::Display for Load {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Load::B8b => write!(f, "Load B (8b)"),
            Load::C8b => write!(f, "Load C (8b)"),
            Load::D8b => write!(f, "Load D (8b)"),
            Load::E8b => write!(f, "Load E (8b)"),
            Load::H8b => write!(f, "Load H (8b)"),
            Load::L8b => write!(f, "Load L (8b)"),
            Load::A8b => write!(f, "Load A (8b)"),
            Load::AA => write!(f, "Load A A"),
            Load::AB => write!(f, "Load A B"),
            Load::AC => write!(f, "Load A C"),
            Load::AD => write!(f, "Load A D"),
            Load::AE => write!(f, "Load A E"),
            Load::AH => write!(f, "Load A H"),
            Load::AL => write!(f, "Load A L"),
            Load::BB => write!(f, "Load B B"),
            Load::BC => write!(f, "Load B C"),
            Load::BD => write!(f, "Load B D"),
            Load::BE => write!(f, "Load B E"),
            Load::BH => write!(f, "Load B H"),
            Load::BL => write!(f, "Load B L"),
            Load::CB => write!(f, "Load C B"),
            Load::CC => write!(f, "Load C C"),
            Load::CD => write!(f, "Load C D"),
            Load::CE => write!(f, "Load C E"),
            Load::CH => write!(f, "Load C H"),
            Load::CL => write!(f, "Load C L"),
            Load::DB => write!(f, "Load D B"),
            Load::DC => write!(f, "Load D C"),
            Load::DD => write!(f, "Load D D"),
            Load::DE => write!(f, "Load D E"),
            Load::DH => write!(f, "Load D H"),
            Load::DL => write!(f, "Load D L"),
            Load::EB => write!(f, "Load E B"),
            Load::EC => write!(f, "Load E C"),
            Load::ED => write!(f, "Load E D"),
            Load::EE => write!(f, "Load E E"),
            Load::EH => write!(f, "Load E H"),
            Load::EL => write!(f, "Load E L"),
            Load::HB => write!(f, "Load H B"),
            Load::HC => write!(f, "Load H C"),
            Load::HD => write!(f, "Load H D"),
            Load::HE => write!(f, "Load H E"),
            Load::HH => write!(f, "Load H H"),
            Load::HL => write!(f, "Load H L"),
            Load::LB => write!(f, "Load L B"),
            Load::LC => write!(f, "Load L C"),
            Load::LD => write!(f, "Load L D"),
            Load::LE => write!(f, "Load L E"),
            Load::LH => write!(f, "Load L H"),
            Load::LL => write!(f, "Load L L"),
            Load::BA => write!(f, "Load B A"),
            Load::DA => write!(f, "Load D A"),
            Load::HA => write!(f, "Load H A"),
            Load::CA => write!(f, "Load C A"),
            Load::EA => write!(f, "Load E A"),
            Load::LA => write!(f, "Load L A"),
            Load::BHL => write!(f, "Load B [HL]"),
            Load::CHL => write!(f, "Load C [HL]"),
            Load::DHL => write!(f, "Load D [HL]"),
            Load::EHL => write!(f, "Load E [HL]"),
            Load::HHL => write!(f, "Load H [HL]"),
            Load::LHL => write!(f, "Load L [HL]"),
            Load::AHL => write!(f, "Load A [HL]"),
            Load::HLB => write!(f, "Load [HL] B"),
            Load::HLC => write!(f, "Load [HL] C"),
            Load::HLD => write!(f, "Load [HL] D"),
            Load::HLE => write!(f, "Load [HL] E"),
            Load::HLH => write!(f, "Load [HL] H"),
            Load::HLL => write!(f, "Load [HL] L"),
            Load::HLA => write!(f, "Load [HL] A"),
            Load::HL8b => write!(f, "Load [HL] (8b)"),
            Load::BCA => write!(f, "Load [BC] A"),
            Load::DEA => write!(f, "Load [DE] A"),
            Load::ABC => write!(f, "Load A [BC]"),
            Load::ADE => write!(f, "Load A [DE]"),
            Load::HLPA => write!(f, "Load [HL+] A"),
            Load::HLMA => write!(f, "Load [HL-] A"),
            Load::AHLP => write!(f, "Load A [HL+]"),
            Load::AHLM => write!(f, "Load A [HL-]"),
            Load::ToIOC => write!(f, "Load [C + $FF00] A"),
            Load::IOC => write!(f, "Load A [C + $FF00]"),
            Load::ToIONext => write!(f, "Load [8b + $FF00] A"),
            Load::IONext => write!(f, "Load A [8b + $FF00]"),
            Load::AtNextA => write!(f, "Load [16b] A"),
            Load::AAtNext => write!(f, "Load A [16b]"),
        }
    }
}
