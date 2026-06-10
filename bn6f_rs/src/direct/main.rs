fn setup_game_context() -> super::types::game_context::GameContext {
    let nonstruct = super::types::nonstruct::Nonstruct {primary_rng_seed:0, unused_extra_toolkit_ptrs_offset: 0 };
    let render_info = super::types::render_info::RenderInfo { unk_00: 0, unk_02: 0, unk_0a: 0, unk_0c: 0, unk_0e: 0, unk_10: 0, unk_12: 0, unk_14: 0, unk_16: 0, unk_18: 0, unk_1a: 0 };
    let toolkit = super::types::toolkit::Toolkit { render_info: render_info };
    let iwram_nonstruct = super::types::iwram::nonstruct::Nonstruct {
        palette_3001960: [0; _],
    };

    super::types::game_context::GameContext {
        nonstruct, 
        toolkit,
        iwram_nonstruct,
     }
}

// Code that more directly corresponds to the disassembly
fn main_corresponding(mut_gctx: &mut super::types::game_context::GameContext) {
    main_init_toolkit_and_other_subsystems(mut_gctx);

}

// corresponding to main_initToolkitAndOtherSubsystems in the disassembly
fn main_init_toolkit_and_other_subsystems(mut_gctx: &mut super::types::game_context::GameContext) {
    // No need, we will expose a global data structure.
    // anon::asm00_1::set_primary_toolkit_pointers();

    super::anon::asm00_1::randomize_extra_toolkit_pointers(mut_gctx);

    let r0_1 = {
        if true { // likely erased in development
            0xC0
        } else {
            0x40
        }
    };

    super::anon::asm00_0::set_render_info_lcdcontrol(&mut mut_gctx.toolkit.render_info.unk_00, r0_1);

    super::anon::asm00_0::render_800172c(&mut_gctx);
}