#ifndef SCRIPT_COMMANDS_H
#define SCRIPT_COMMANDS_H

#include <inttypes.h>
// doc: http://forums.therockmanexezone.com/topic/8695308/1/
typedef struct{
    u32 size;
    u8 content[0];
}sc_script;

void sc_init_script(sc_script *pScript);

/*The following functions take a script, and append the command to them*/

/**
 * Appends the ASCII text as gameText in the script
 */
void sc_text(sc_script *pScript, char* str);

/**
 * E5 = nop
 * do nothing (but make the script go on)
 * @param pScript    Script to append output of command on
 */
void sc_nop(sc_script *pScript);

/**
 * E6 = end
 * ends the current script and closes message box
 * @param pScript    script to append output of command on
 */
void sc_end(sc_script *pScript);

/**
 * E7 = buttonhalt
 * display an arrow at the lower right of the message box 
 * and stop processing until a button is pressed
 *  @param pScript script to append output of command on
 *  @param mode  00 = wait for A or B button, 01 = wait for any button
 */
void sc_buttonhalt(sc_script *pScript, u8 mode);

// E8
void sc_msgbox(sc_script *pScript, u8 type, u8 specialType, u8 arrowPos);

/**
 * E9
 * moves the position for text writing to the next line
 */
void sc_newline(sc_script *pScript);

/**
 * EA
 * does various things with flags!
 */
void sc_flag(sc_script *pScript, u8 function, u16 flag);

// EB
void sc_option(sc_script *pScript, u8 a1, u8 LR, u8 UD);

// EC
void sc_label(sc_script *pScript, u8 spacesMode, u8 spacesAmt);

// ED
void sc_select(sc_script *pScript, u8 a1, u8 a2, u8 a3);

// EE
void sc_pause(sc_script *pScript, u8 mode, u16 data);

/**
 * EF
 *  tests something and executes a specific script based on the result
 */
void sc_checkflag(sc_script *pScript, u8 func, u8 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6, u8 a7,
u8 a8, u8 a9, u8 a10, u8 a11, u8 a12, u8 a13);

// F0
void sc_jump(sc_script *pScript, u8 func, u8 index);

// F1
void sc_textspeed(sc_script *pScript, u8 a1, u8 speed);

// F2
/**
 * F2
 * removes all text from the screen and resets text printing position
 * Also changes the currScript in the chatbox struct
 */
void sc_clearmsgbox(sc_script *pScript);

// F3
void sc_control(sc_script *pScript, u8 func, u8 flag);

// F4
void sc_unkF4(sc_script *pScript, u8 func, u8 a1, u8 a2, u8 a3);

// F5
void sc_mugshot(sc_script *pScript, u8 mode, u8 value);

// F6
void sc_textcolor(sc_script *pScript, u8 mode, u8 index);

// F7
void sc_movebox(sc_script *pScript, u8 mode, u8 x, u8 y, u8 z);

// F8
void sc_playeranimation(sc_script *pScript, u8 mode, u8 index);

// F9
void sc_storebyte(sc_script *pScript, u8 mode, u8 a1, u8 a2);

// FA
void sc_print(sc_script *pScript, u8 mode, u8 a1, u8 a2);

// FB
void sc_special(sc_script *pScript, u8 mode, u16 a1);

// FC
void sc_interface(sc_script *pScript, u8 mode, u8 a1, u8 a2, u8 a3);

// FD
void sc_sound(sc_script *pScript, u8 mode, u16 musicValue, u8 delay);

// FE
void sc_numberinput(sc_script *pScript, u8 mode, u8 a1, u8 a2, u8 a3);

// FF
void sc_copytext(sc_script *pScript, u8 mode, u8 index);

#endif // SCRIPT_COMMANDS_H