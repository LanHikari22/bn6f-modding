use crate::direct::anon::{asm00_0::seed_rng, asm03_1_1::{clear_e200ad04, incomp0_logo_screen_init_803d1a8}};

fn setup_game_context() -> super::types::game_context::GameContext {
    let nonstruct = super::types::nonstruct::Nonstruct {
        primary_rng_seed: 0,
        unused_extra_toolkit_ptrs_offset: 0,
        unk_word_200ad04: 0,
    };
    let render_info = super::types::render_info::RenderInfo {
        unk_00: 0,
        unk_02: 0,
        unk_0a: 0,
        unk_0c: 0,
        unk_0e: 0,
        unk_10: 0,
        unk_12: 0,
        unk_14: 0,
        unk_16: 0,
        unk_18: 0,
        unk_1a: 0,
    };
    let toolkit = super::types::toolkit::Toolkit {
        render_info: render_info,
    };
    let iwram_nonstruct = super::types::iwram::nonstruct::Nonstruct {
        palette_3001960: [0; _],
    };

    super::types::game_context::GameContext {
        nonstruct,
        toolkit,
        iwram_nonstruct,
    }
}

/// Corresponds to main_ in the disassembly
fn incomp1_main_() {
    let mut mut_gctx = setup_game_context();

    incomp1_main_init_toolkit_and_other_subsystems(&mut mut_gctx);
    seed_rng(&mut mut_gctx.nonstruct.primary_rng_seed);
    clear_e200ad04(&mut mut_gctx.nonstruct.unk_word_200ad04);
    incomp0_logo_screen_init_803d1a8();

    loop {
        incomp0_main_poll_general_lcd_status_stat_lyc();
        incomp0_main_await_frame();
    }
}

/// corresponding to main_initToolkitAndOtherSubsystems in the disassembly
fn incomp1_main_init_toolkit_and_other_subsystems(
    mut_gctx: &mut super::types::game_context::GameContext,
) {
    // No need, we will expose a global data structure.
    // anon::asm00_1::set_primary_toolkit_pointers();

    super::anon::asm00_1::incomp_randomize_extra_toolkit_pointers(mut_gctx);

    let r0_1 = {
        if true {
            // likely erased in development
            0xC0
        } else {
            0x40
        }
    };

    super::anon::asm00_0::set_render_info_lcdcontrol(
        &mut mut_gctx.toolkit.render_info.unk_00,
        r0_1,
    );

    super::anon::asm00_0::incomp_render_800172c(&mut_gctx);
}

/// Corresponds to main_pollGeneralLCDStatus_STAT_LYC_ in the disassembly.
fn incomp0_main_poll_general_lcd_status_stat_lyc() {

}

/// Corresponds to X in the disassembly.
fn incomp0_main_await_frame() {

}