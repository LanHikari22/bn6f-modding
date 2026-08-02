//! Use flags customize the ROM being built. This can be used to disable features or replace them with mod modules.
//! Comment out flags to disable them.
//! Make sure to also review `use_flags.pp` for preprocessed ld_script.

    .include "constants/constants.inc"

    // Enable ROM modding
    .equiv USE_MOD, TRUE

    .equiv USE_MODULE_START_SCREEN, TRUE

    // USE_MODULE_START_SCREEN? (use-exactly-one-of USE_MODULE_START_SCREEN_ORIG USE_MODULE_START_SCREEN_ASM_MOD)
    //.equiv USE_MODULE_START_SCREEN_ORIG, TRUE
    .equiv USE_MODULE_START_SCREEN_ASM_MOD, TRUE
