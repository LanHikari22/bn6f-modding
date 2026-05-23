// Corresponds to GetRNG in the disassembly
pub fn get_rng(mut_primary_rng_seed: &mut u32) -> u32 {
    let rng_magic = 0x873ca9e5;
    let leftmost_bit = *mut_primary_rng_seed >> 31;

    let result = ((*mut_primary_rng_seed * 2) + leftmost_bit + 1) ^ rng_magic;

    *mut_primary_rng_seed = result;

    result
}

// Corresponds to SetRenderInfoLCDControl in the disassembly
pub fn set_render_info_lcdcontrol(render_info_unk_00 : &mut u16, a0: u16) {
    *render_info_unk_00 = a0;
}