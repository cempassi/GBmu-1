use num_enum::{IntoPrimitive, TryFromPrimitive};
use std::fmt;
/// RRA
/// Rotate register A right through carry.
///
/// C -> [7 -> 0] -> C

/// RRCA
/// Rotate register A right.
///
/// C -> [7 -> 0] -> [7]

/// LRA
/// Rotate register A left through carry.
///
/// C <- [7 <- 0] <- C

/// LRCA
/// Rotate register A left.
///
/// C <- [7 <- 0] <- [7]

/// AND n
/// Description:
///  Logically AND n with A, result in A.
/// Use with:
///  n = A,B,C,D,E,H,L,(HL),8b
/// Flags affected:
///  Z - Set if result is zero.
///  N - Reset.
///  H - Set.
///  C - Reset.
/// Opcodes:
/// Instruction Parameters Opcode Cycles |  Instruction Parameters Opcode Cycles
///  AND        A          0xa7   4         AND        E          0xa3   4
///  AND        B          0xa0   4         AND        H          0xa4   4
///  AND        C          0xa1   4         AND        L          0xa5   4
///  AND        D          0xa2   4         AND        (HL)       0xa6   8
///  AND        8b         0xe6   8

/// OR n
/// Description:
///  Logical OR n with register A, result in A.
/// Use with:
///  n = A,B,C,D,E,H,L,(HL),8b
/// Flags affected:
///  Z - Set if result is zero.
///  N - Reset.
///  H - Reset.
///  C - Reset.
/// Opcodes:
/// Instruction Parameters Opcode Cycles
/// OR          A          0xb7   4
/// OR          B          0xb0   4
/// OR          C          0xb1   4
/// OR          D          0xb2   4
/// OR          E          0xb3   4
/// OR          H          0xb4   4
/// OR          L          0xb5   4
/// OR          (HL)       0xb6   8
/// OR          8b         0xf6   8

/// XOR n
/// Description:
///  Logical exclusive OR n with register A, result in A.
/// Use with:
///  n = A,B,C,D,E,H,L,(HL),8b
/// Flags affected:
///  Z - Set if result is zero.
///  N - Reset.
///  H - Reset.
///  C - Reset.
/// Opcodes:
/// Instruction Parameters Opcode Cycles | Instruction Parameters Opcode Cycles
/// XOR         A          0xaf   4        XOR         E          0xab   4
/// XOR         B          0xa8   4        XOR         H          0xac   4
/// XOR         C          0xa9   4        XOR         L          0xad   4
/// XOR         D          0xaa   4        XOR         (HL)       0xae   8
/// XOR         8b         0xee   8

/// CP n
/// Description:
///  Compare A with n. This is basically an A - n
///  subtraction instruction but the results are thrown
///  away.
/// Use with:
///  n = A,B,C,D,E,H,L,(HL),#
/// Flags affected:
///  Z - Set if result is zero. (Set if A = n.)
///  N - Set.
///  H - Set if no borrow from bit 4.
///  C - Set for no borrow. (Set if A < n.)
/// Opcodes:
/// Instruction Parameters Opcode Cycles | Instruction Parameters Opcode Cycles
/// CP          A          0xbf   4        CP          E          0xbb   4
/// CP          B          0xb8   4        CP          H          0xbc   4
/// CP          C          0xb9   4        CP          L          0xbd   4
/// CP          D          0xba   4        CP          (HL)       0xbe   8
/// CP          8b         0xfe   8
#[derive(Eq, PartialEq, TryFromPrimitive, IntoPrimitive, Clone, Copy)]
#[repr(u8)]
#[allow(clippy::upper_case_acronyms)]
pub enum Logic {
    AndAA = 0xA7,
    AndAB = 0xA0,
    AndAC = 0xA1,
    AndAD = 0xA2,
    AndAE = 0xA3,
    AndAH = 0xA4,
    AndAL = 0xA5,
    AndAHL = 0xA6,
    AndA8b = 0xE6,
    OrAB = 0xB0,
    OrAC = 0xB1,
    OrAD = 0xB2,
    OrAE = 0xB3,
    OrAH = 0xB4,
    OrAL = 0xB5,
    OrAHL = 0xB6,
    OrAA = 0xB7,
    OrA8b = 0xF6,
    XorAA = 0xAF,
    XorAB = 0xA8,
    XorAC = 0xA9,
    XorAD = 0xAA,
    XorAE = 0xAB,
    XorAH = 0xAC,
    XorAL = 0xAD,
    XorAHL = 0xAE,
    XorA8b = 0xEE,
    CmpAA = 0xBF,
    CmpAB = 0xB8,
    CmpAC = 0xB9,
    CmpAD = 0xBA,
    CmpAE = 0xBB,
    CmpAH = 0xBC,
    CmpAL = 0xBD,
    CmpAHL = 0xBE,
    CmpA8b = 0xFE,
    RLCA = 0x07,
    RLA = 0x17,
    RRCA = 0x0F,
    RRA = 0x1F,
}

impl fmt::Display for Logic {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Logic::AndAA => write!(f, "And A A"),
            Logic::AndAB => write!(f, "And A B"),
            Logic::AndAC => write!(f, "And A C"),
            Logic::AndAD => write!(f, "And A D"),
            Logic::AndAE => write!(f, "And A E"),
            Logic::AndAH => write!(f, "And A H"),
            Logic::AndAL => write!(f, "And A L"),
            Logic::AndAHL => write!(f, "And A HL"),
            Logic::AndA8b => write!(f, "And A 8b"),
            Logic::OrAB => write!(f, "Or A B"),
            Logic::OrAC => write!(f, "Or A C"),
            Logic::OrAD => write!(f, "Or A D"),
            Logic::OrAE => write!(f, "Or A E"),
            Logic::OrAH => write!(f, "Or A H"),
            Logic::OrAL => write!(f, "Or A L"),
            Logic::OrAHL => write!(f, "Or A HL"),
            Logic::OrAA => write!(f, "Or A A"),
            Logic::OrA8b => write!(f, "Or A 8b"),
            Logic::XorAA => write!(f, "Xor A A"),
            Logic::XorAB => write!(f, "Xor A B"),
            Logic::XorAC => write!(f, "Xor A C"),
            Logic::XorAD => write!(f, "Xor A D"),
            Logic::XorAE => write!(f, "Xor A E"),
            Logic::XorAH => write!(f, "Xor A H"),
            Logic::XorAL => write!(f, "Xor A L"),
            Logic::XorAHL => write!(f, "Xor A HL"),
            Logic::XorA8b => write!(f, "Xor A 8b"),
            Logic::CmpAA => write!(f, "Cmp A A"),
            Logic::CmpAB => write!(f, "Cmp A B"),
            Logic::CmpAC => write!(f, "Cmp A C"),
            Logic::CmpAD => write!(f, "Cmp A D"),
            Logic::CmpAE => write!(f, "Cmp A E"),
            Logic::CmpAH => write!(f, "Cmp A H"),
            Logic::CmpAL => write!(f, "Cmp A L"),
            Logic::CmpAHL => write!(f, "Cmp A HL"),
            Logic::CmpA8b => write!(f, "Cmp A 8b"),
            Logic::RLCA => write!(f, "Rotate Left A"),
            Logic::RLA => write!(f, "Rotate Left Carry A"),
            Logic::RRCA => write!(f, "Rotate Right A"),
            Logic::RRA => write!(f, "Rotate Right Carry A"),
        }
    }
}
