
#include <scriptCommands.h>
#include <TextGenerator.h>

void sc_init_script(sc_script *pScript){
    pScript->size = 0;
    pScript->content[0] = '\0';
}

void sc_text(sc_script *pScript, char* str){
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

// // EF
// void sc_checkflag(sc_script *pScript, u8 func, u8 a1, u8 a2, u8 a3, u8 a4);

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

// // F2
// void sc_clearmsgbox(sc_script *pScript);

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

// // FB
// void sc_special(sc_script *pScript, u8 mode, u16 a1);

// // FC
// void sc_interface(sc_script *pScript, u8 mode, u8 a1, u8 a2, u8 a3);

// // FD
// void sc_sound(sc_script *pScript, u8 mode, u16 musicValue, u8 delay);

// // FE
// void sc_numberinput(sc_script *pScript, u8 mode, u8 a1, u8 a2, u8 a3);

// // FF
// void sc_copytext(sc_script *pScript, u8 mode, u8 index);