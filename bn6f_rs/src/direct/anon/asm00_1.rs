use crate::{direct::anon::asm00_0, direct::types::game_context::GameContext};

pub fn randomize_extra_toolkit_pointers(mut_gctx: &mut GameContext) {
    let new_seed = asm00_0::get_rng(&mut mut_gctx.nonstruct.primary_rng_seed);

    // guaranteed to be 0, erased in development-time for some reason.
    let r4_0 = new_seed & 0;
    let r3_1 = mut_gctx.nonstruct.unused_extra_toolkit_ptrs_offset & 0;

    mut_gctx.nonstruct.unused_extra_toolkit_ptrs_offset = r4_0;

    /* Then they do a no-op copy to GameState */

    /*
        r5_0 -> mut_gctx.nonstruct.unused_extra_toolkit_ptrs_offset
     */

    /* TODO: Does some currently inconsequential copy for toolkit  */
}