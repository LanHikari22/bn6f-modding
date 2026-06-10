#![no_std]
#![no_main]
#![cfg_attr(test, feature(custom_test_frameworks))]
#![cfg_attr(test, reexport_test_harness_main = "test_main")]
#![cfg_attr(test, test_runner(_test_runner))]

pub mod direct;

fn _test_runner(_tests: &[()]) {
    // Will not use for now
}

#[panic_handler]
fn panic_handler(_ : &core::panic::PanicInfo) -> ! {
    loop {}
}

#[unsafe(no_mangle)]
extern "C" fn main() -> ! {
//     // General mutable data of the game. It needs to be explicitly passed in.
//     let mut mut_gctx = setup_game_context();
//     main_corresponding(&mut mut_gctx);

    loop {}
}