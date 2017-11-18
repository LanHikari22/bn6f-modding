sub_080A0058 <fpRunChatbox>

[Description ---------------------]

[Memo ----------------------------]
This nicely starts the chat system! an NPC structure
is passed to it in register 5...

Objectives:
- Investigate the usage of the NPC structure within this function

[I/O -----------------------------]
input:
r5: <NPC>
r10: <ChiefStruct> 
output:

[Function Calls ------------------]
<> Does something interesting when called through R press
{} Crashes when called through R press
bl 0x0800117C {} <>
bl 0x08002DA4 {}
bl 0x080026A4 {}
bl 0x0803FD3C <> {}
bl 0x080A00F4 {}

[Backtrace -----------------------]
sub_080A0058 <- 0x080A003C

[Memory Accesses -----------------]
r5: <NPC> r10: <chiefStruct>
r5->RD[0x60, 0x28, 0x24, 0x60, 0x1C]
r5->WR[0xA]
r10->RD[0x18->[0x20]]

[Pointers Accesed ----------------]
r5_0205888 

#pragma region Algorithm
void sub_080A0058(r5_pNpc){
    global r10_cheifStruct;
    r0 = r5_pNpc->unk_60;
    if(r0 & r1:2){
        r7 = r10_chiefStruct->0x3C->0x18; // 0x02001B80->0x18
        r0 = r7->0x20;
        r2_y = r5_pNpc->y; // 0x28
        r0 -= r2_y;
        r1 = r7->0x1C;
        r2_x = r5_pNpc->x; // 0x24
        r1 -= r2_x;
        sub_800117C();
        r0 += 0x20;
        r1 += 0xC0;
        r0 = (r0&r1>>6) << 1 + 1;
        sub_08002DA4();
    }
    else{
        r2 = r5_pNpc->unk_60;
        if(r2 & r1:0x400){
            if(r2 & r1:0x800){
                r7 = r10_chiefStruct->0x2C;
                r1 = 0x90;
                r0 = r5_pNpc->r1:0x90;
                r7->0x4C = r0;
                sub_080A176();
                r7->0x54 = r0;
                r7->0x58 = r1;
                r5_pNpc->0x1C = r2; // u8
            }
            if(r3 != 8){
                r2 = 0x94;
                r0 = r5_pNpc->r2:0x94;
                r1 = r5_pNpc->0x1C; // u8
                sub_08040358();
            } 
            else if(r0 != 0x70) { /* r3 == 8 */
                // PUSH {R0, R1, R3-R7}
                sub_080010B6();
                r2 = r0; // r0 output?
                // POP {R0,R1, R3-R7}
                if(r2 != 0){
                    r2 = 0x94;
                    r0 = r5_pNpc->r2:0x94;
                    r1 = 0x78;
                    sub_08040358();
                }
            }
        }
        else { /* r2 & r1:0x400 == 0 */
            r0 = r5_pNpc->unk_1C; // LDRB
            sub_0803FD3C();
        }
        r0 = 4;
        r5_pNpc->unk_0A = r0; // u8
        sub_080A00F4();
    }
}
#pragma endregion Algorithm