// Games made using `agb` are no_std which means you don't have access to the standard
// rust library. This is because the game boy advance doesn't have an operating
// system, so most of the content of the standard library doesn't apply.
#![no_std]
// `agb` defines its own `main` function, so you must declare your game's main function
// using the #[agb::entry] proc macro. Failing to do so will cause failure in linking
// which won't be a particularly clear error message.
#![no_main]
// This is required to allow writing tests
#![cfg_attr(test, feature(custom_test_frameworks))]
#![cfg_attr(test, reexport_test_harness_main = "test_main")]
#![cfg_attr(test, test_runner(agb::test_runner::test_runner))]

use crate::types::{game_context::GameContext, nonstruct::Nonstruct, render_info::RenderInfo};

// By default no_std crates don't get alloc, so you won't be able to use things like Vec
// until you declare the extern crate. `agb` provides an allocator so it will all work
extern crate alloc;

pub mod anon;
pub mod types;


// The main function must take 1 arguments and never returns, and must be marked with
// the #[agb::entry] macro.
#[agb::entry]
fn main(gba: agb::Gba) -> ! {

    // General mutable data of the game. It needs to be explicitly passed in.
    let mut mut_gctx = setup_game_context();
    main_corresponding(&mut mut_gctx);

    agb::no_game(gba);
}

fn setup_game_context() -> GameContext {
    let nonstruct = Nonstruct {primary_rng_seed:0, unused_extra_toolkit_ptrs_offset: 0 };
    let render_info = RenderInfo { unk_00: 0, unk_02: 0, unk_0a: 0, unk_0c: 0, unk_0e: 0, unk_10: 0, unk_12: 0, unk_14: 0, unk_16: 0, unk_18: 0, unk_1a: 0 };
    let toolkit = types::toolkit::Toolkit { render_info: render_info };

    GameContext {nonstruct, toolkit: toolkit }
}

// Code that more directly corresponds to the disassembly
fn main_corresponding(mut_gctx: &mut GameContext) {
    main_init_toolkit_and_other_subsystems(mut_gctx);

}

fn main_init_toolkit_and_other_subsystems(mut_gctx: &mut GameContext) {
    // No need, we will expose a global data structure.
    // anon::asm00_1::set_primary_toolkit_pointers();

    anon::asm00_1::randomize_extra_toolkit_pointers(mut_gctx);

    let r0_1 = {
        if true { // likely erased in development
            0xC0
        } else {
            0x40
        }
    };

    anon::asm00_0::set_render_info_lcdcontrol(&mut mut_gctx.toolkit.render_info.unk_00, r0_1)
}
