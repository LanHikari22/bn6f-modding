#ifndef SCRIPTS_GREGAR_MISC
#define SCRIPTS_GREGAR_MISC

/**
 * This might be only for multiplayer. It might also do more.
 * TODO: investigate this function
 */
#define fpGenBattleStageAndBackgrounds ((void (*)())(0x081209DC+1))
/*
 * Modified first word in 0x02034880 to 0x00001400
 * Exits battles very nicely. If battling someone, a You-Lost scene plays too.
 */
#define fpEndBattleNoGM ((void (*)())(0x0800AABC+1))

#define apply_NCP_effect ((void (*)())(0x0801379F+1))

#define u8Arrayo_u32 ((void (*)())(0x080A0B3A+1))

#endif