//! Memory use in bn6f that isn't a dedicated struct or composite datatype. Like scattered variables in RAM.

pub struct Nonstruct {
    // Corresponds to ePrimaryRngSeed in the disassembly.
    pub primary_rng_seed: u32,

    // Unknown. Corresponds to eUnusedExtraToolkitPtrsOffset in the disassembly.
    pub unused_extra_toolkit_ptrs_offset: u32,
}