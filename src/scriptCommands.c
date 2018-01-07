
#include <scriptCommands.h>
#include <TextGenerator.h>
#include <str.h>

void sc_init_script(sc_script *pScript){
    pScript->size = 0;
    pScript->content[0] = '\0';
}

void sc_script_write(sc_script *pScript, u8 *arr, u32 arrSize){
    memcpy(pScript->content + pScript->size, arr, arrSize);
    pScript->size += arrSize;
}

void sc_text(sc_script *pScript, const char* str){
    int strLen = strlen(str);
    char gameText[tg_max_str_len];
    tg_toGameText(str, gameText);
    memcpy(pScript->content + pScript->size, gameText, strLen);
    pScript->size += strLen;
}

// void sc_nop(sc_script *pScript);

/**
 * E6 = end
 * ends the current script and closes message box
 * @param pScript    script to append output of command on
 */
void sc_end(sc_script *pScript){
    pScript->content[pScript->size] = 0xE6;
    pScript->size++;
}

/**
 * E7 = buttonhalt
 * display an arrow at the lower right of the message box 
 * and stop processing until a button is pressed
 *  @param pScript script to append output of command on
 *  @param mode  00 = wait for A or B button, 01 = wait for any button
 */
void sc_buttonhalt(sc_script *pScript, u8 mode){
    u8 arr[2] = {0xE7, mode};
    memcpy(pScript->content + pScript->size, arr, 2);
    pScript->size += 2;
}

// E8
void sc_msgbox(sc_script *pScript, u8 type, u8 specialType, u8 arrowPos){
    if(type < 4 || type > 7){
        u8 arr[2] = {0xE8, type};
        memcpy(pScript->content + pScript->size, arr, 2);
        pScript->size += 2;
    }
    else {
        u8 arr[4] = {0xE8, type, specialType, arrowPos};
        memcpy(pScript->content + pScript->size, arr, 4);
        pScript->size += 4;
    }
}

/**
 * E9
 * moves the position for text writing to the next line
 */
void sc_newline(sc_script *pScript){
    pScript->content[pScript->size] = 0xE9;
    pScript->size++;
}

/**
 * EA
 * does various things with flags!
 */
// void sc_flag(sc_script *pScript, u8 function, u16 flag);

// // EB
// void sc_option(sc_script *pScript, u8 a1, u8 LR, u8 UD);

// // EC
// void sc_label(sc_script *pScript, u8 spacesMode, u8 spacesAmt);

// // ED
// void sc_select(sc_script *pScript, u8 a1, u8 a2, u8 a3);

// // EE
// void sc_pause(sc_script *pScript, u8 mode, u16 data);

/**
 * EF
 *  tests something and executes a specific script based on the result
 * Just feeling like writing some real weird code today. :P
 */
void sc_checkflag(sc_script *pScript, u8 func, u8 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6, u8 a7,
u8 a8, u8 a9, u8 a10, u8 a11, u8 a12, u8 a13){
    switch(func){
        case 0x16: case 0x17: case 0x18:
        case 0x19: case 0x1F: case 0x23:
        case 0x24: case 0x25: case 0x26:
        case 0x27: case 0x3C: case 0x2D:
        case 0x30: case 0x3A:
            ;u8 arr2[2] = {0xEF, func};
            sc_script_write(pScript, arr2, 2);
            break;
        case 0x29:
            ;u8 arr3[3] = {0xEF, func, a1};
            sc_script_write(pScript, arr3, 3);
            break;
        case 0x05: case 0x06: case 0x0C:
        case 0x2B: case 0x32: 
            ;u8 arr4[4] = {0xEF, func, a1, a2};
            sc_script_write(pScript, arr4, 4);
            break;
        case 0x1B: case 0x1C: case 0x1D:
        case 0x22:
            ;u8 arr5[5] = {0xEF, func, a1, a2, a3};
            sc_script_write(pScript, arr5, 5);
            break;
        case 0x00: case 0x01: case 0x02:
        case 0x03: case 0x04: case 0x10:
        case 0x1A: case 0x20: case 0x21:
        case 0x31: case 0x34: case 0x35:
        case 0x36: case 0x37: case 0x38:
        case 0x39:
            ;u8 arr6[6] = {0xEF, func, a1, a2, a3, a4};
            sc_script_write(pScript, arr6, 6);
            break;
        case 0x07: case 0x0A: case 0x0B:
        case 0x0D: case 0x28: case 0x33:
        case 0x3B:
            ;u8 arr7[7] = {0xEF, func, a1, a2, a3, a4, a5};
            sc_script_write(pScript, arr7, 7);
            break;
        case 0x1E: case 0x2A:
            ;u8 arr8[8] = {0xEF, func, a1, a2, a3, a4, a5, a6};
            sc_script_write(pScript, arr8, 8);
            break;
        case 0x08: case 0x09: case 0x0E:
        case 0x0F: case 0x11: case 0x12:
        case 0x13: case 0x14: case 0x15:
            ;u8 arr9[9] = {0xEF, func, a1, a2, a3, a4, a5, a6, a7};
            sc_script_write(pScript, arr9, 9);
            break;
        case 0x2F:
            ;u8 arr14[14] = {0xEF, func, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12};
            sc_script_write(pScript, arr14, 14);
            break;
        case 0x2E:
            ;u8 arr15[15] = {0xEF, func, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13};
            sc_script_write(pScript, arr15, 15);
            break;
    }
}

// F0
void sc_jump(sc_script *pScript, u8 func, u8 index){
    if (func != 0x00 && func != 0x02){
        u8 arr[3] = {0xF0, func, index};
        memcpy(pScript->content + pScript->size, arr, 3);
        pScript->size += 3;
    }
    else {
        u8 arr[2] = {0xF0, func};
        memcpy(pScript->content + pScript->size, arr, 2);
        pScript += 2;
    }
}

// // F1
// void sc_textspeed(sc_script *pScript, u8 a1, u8 speed);

// F2
void sc_clearmsgbox(sc_script *pScript){
    pScript->content[pScript->size] = 0xF2;
    pScript->size++;
}

// // F3
// void sc_control(sc_script *pScript, u8 func, u8 flag);

// // F4
// void sc_unkF4(sc_script *pScript, u8 func, u8 a1, u8 a2, u8 a3);

// F5
void sc_mugshot(sc_script *pScript, u8 mode, u8 value){
    u8 ctrlArr [3] = {0xF5, mode, value};
    memcpy(pScript->content + pScript->size, ctrlArr, 3);
    pScript->size += 3;
}

// // F6
// void sc_textcolor(sc_script *pScript, u8 mode, u8 index);

// // F7
// void sc_movebox(sc_script *pScript, u8 mode, u8 x, u8 y, u8 z);

// // F8
// void sc_playeranimation(sc_script *pScript, u8 mode, u8 index);

// // F9
// void sc_storebyte(sc_script *pScript, u8 mode, u8 a1, u8 a2);

// // FA
// void sc_print(sc_script *pScript, u8 mode, u8 a1, u8 a2);

// FB
void sc_special(sc_script *pScript, u8 mode, u16 a1){
    u8 a1H = (a1 & 0xFF00) >> 8;
    u8 a1L = (a1 & 0x00FF);
    switch(mode){
        case 0x00:
        case 0x01:
        case 0x05:
        case 0x06:
        case 0x0A:
        case 0x0B:
        case 0x0D:
        case 0x0E:
        case 0x0F:
            // TOOD: incomplete (for 0x00, and 0x01...)
            ;u8 arr0[3] = {0xFB, mode, a1H};
            sc_script_write(pScript, arr0, 3);
            break;
        case 0x02:
        case 0x04:
        case 0x07:
        case 0x09:
        case 0x0C:
            ;u8 arr1[2] = {0xFB, mode};
            sc_script_write(pScript, arr1, 2);
            break;
        case 0x03:
        case 0x08:
            ;u8 arr2[4] = {0xFB, mode, a1H, a1L};
            sc_script_write(pScript, arr2, 4);
            break;
    }
}

// // FC
// void sc_interface(sc_script *pScript, u8 mode, u8 a1, u8 a2, u8 a3);

// // FD
// void sc_sound(sc_script *pScript, u8 mode, u16 musicValue, u8 delay);

// // FE
// void sc_numberinput(sc_script *pScript, u8 mode, u8 a1, u8 a2, u8 a3);

// // FF
// void sc_copytext(sc_script *pScript, u8 mode, u8 index);