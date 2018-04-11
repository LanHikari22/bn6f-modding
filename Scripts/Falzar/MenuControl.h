#ifndef SCRIPT_FALZAR_MENUCONTROL_H
#define SCRIPT_FALZAR_MENUCONTROL_H

#include "../../include/inttypes.h"
#include "../../Constants/_Constants.h"
#include "../../Structs/_Structs.h"
#include "../../include/IDADefinitions.h"


// VERSION UNIQUE ------------------------------------
#define MenuControl_cbOpenSubmenu ((int __cdecl (*) ()) (0x0811F774 +1))
#define MenuControl_Navicust_81356F4 ((void __noreturn (*) ()) (0x081356F4 +1))
#define MenuControl_NaviCust_81357C4 ((int (*) ()) (0x081357C4 +1))
#define MenuControl_init_8135B54 ((int __fastcall (*) (int a1)) (0x08135B54 +1))

// VERSION DEPENDENT ---------------------------------
#define MenuControl_cbChipFoldar ((int (*) ()) (0x08123434 +1))
#define MenuControl_cbSubChip ((int (*) ()) (0x08123F5C +1))
#define MenuControl_cbLibrary ((int (*) ()) (0x08124B3C +1))
#define MenuControl_cbMegaman ((int (*) ()) (0x08126B4C +1))
#define MenuControl_cbEmail ((int (*) ()) (0x081279F8 +1))
#define MenuControl_cbKeyItem ((int (*) ()) (0x08128730 +1))
#define MenuControl_cb_8128CBC ((int (*) ()) (0x08128CBC +1))
#define MenuControl_cbComm ((int (*) ()) (0x081291E8 +1))
#define MenuControl_cbSave ((int (*) ()) (0x08132B88 +1))
#define MenuControl_ChipFoldar_cbEDIT ((int (*) ()) (0x08133200 +1))
#define MenuControl_Megaman_cbNaviCust ((int __cdecl (*) ()) (0x081356D4 +1))
#define MenuControl_NaviCust_cb_8136DE0 ((int (*) ()) (0x08136DE0 +1))
#define MenuControl_Megaman_cbRecords ((int (*) ()) (0x081378B4 +1))

#endif // SCRIPT_FALZAR_MENUCONTROL_H
