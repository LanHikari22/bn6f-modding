/**
 * intercept_test.s
 * Author: Lan
 * Date created: MM/DD/20XX
 * Description
 * This is used to intercept or simply change various functions in order to experiment with them
*/

.include "dependencies.s"

.thumb
.section .link__object_subtract_hp, "ax"


// int __fastcall object_subtract_hp(int amt)
object_subtract_hp:                     // CODE XREF: sub_8010230+30↓p
                                        // sub_801026A+2C↓p ...
.extern shoku_call
                PUSH            {R4,LR}
                LDRH            R1, [R5,#0x24]
                SUB             R1, R1, R0
                BGE             loc_800E2E2
                BL              object_add_hp

loc_800E2E2:                            // CODE XREF: object_subtract_hp+6↑j
                STRH            R1, [R5,#0x24]
                POP             {R4,PC}
// End of function object_subtract_hp