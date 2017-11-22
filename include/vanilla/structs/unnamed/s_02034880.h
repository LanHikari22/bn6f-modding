#ifndef S_02034880_H
#define S_02034880_H

#pragma region Docs
/*
s_02034880
	Description
		Has CURRENT BATTLE Information. Modifying this can change immediate
		battle pointer!
	Function Accesses
		<> Simple indicates that this does something significant when CALLED by pressing R.
		XX indicates a CRASH, or a situation that may ultimately leads to it.
		08007204(Modifies Battle pointer)
		--
		0800A2F8, 0800794C <>, 080079A8, 080079D0, 0800A3E4, 080079F0 <>, 08007A0C <>, 080077D2,
		0800799C, 080071FE <> XX, 08007778 <> XX, 08007368 <>
		---
		080091F0, 0800927C <>, 08009338 <>, 08026840 <>
		---
		080094DA <>, 0800A998, 0801FF18, 0800A840, 0800AABC <endsBattleNoGM>, 08007BD0, 08007C14, 08007CA0 <>
	[Definition]
	0x3C <pcurrBattle>
*/
#pragma endregion Docs

#endif /* S_02034880_H */