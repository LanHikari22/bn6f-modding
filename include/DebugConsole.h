#ifndef DEBUG_CONSOLE_H
#define DEBUG_CONSOLE_H

#include <inttypes.h>

typedef enum{
    // Those can be entered in 0x089A0000. Pressing R will trigger specified action

    // By default, the debugger will be listening for a special sequence of key presses to perform an action
    dc_cmd_cheatsystem      = 0x00,
    // Executes onStart() in the main module. Necessary for modules with state.
    dc_cmd_init             = 0x01,
    // Arbitrary function defined in main.c executes.
    dc_cmd_toggleRPress           = 0x02,
    // Calls in Shuko for help!
    dc_cmd_shuko            = 0x03,
    // Format: <Address> <RetAddress> <numParams> <Params ...>
    dc_cmd_call             = 0x04,
    // Format: <Address> <LogAddress> <Start> <Amount>
    dc_cmd_sweep1D          = 0x05,
    // Format: <Address> <LogAddress> <Start> <Amount> <ConstantValue> <1|2 (Parameter to put const in)>
    dc_cmd_sweepPartial2D   = 0x06,
    // Format: <TblAddr> <TblOffsetW> <RetAddress> <numParams> <Params ...>
    dc_cmd_jumptable        = 0x07,

    dc_cmd_NONE             = 0xFF,

}dc_Command;

typedef struct{
    dc_Command command;
    u32 params[];
}dc_ROM;



/*
 * @param writeLoc   A Location to write output to, use for scriptList, etc.
 * @param readLoc    A Location to read in configuration from the user
*/
void dc_init(u32 *writeLoc, dc_ROM *readLoc);

void dc_onUpdate();


/**
 */
void dc_startConsole(u32 *writeLoc, dc_ROM *readLoc);

#endif // DEBUG_CONSOLE_H