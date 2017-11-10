[address]!
[address]?

Subroutines that access a pointer:
	s_02009CD0
		0803FE88  br@0803FE90
		08040358  br@08040392
		08040EB0? br@08040EBA
		 br@03007D38
		 
		
	p_020348BC <pCurrBattle>
		00000B4C
		08007204
		0802D234  br@0802D23C br@0802D24E

	p_02009CFC <pCurrScript>
		00000B4C
		08040358
		0803FF24  br@0802FF2C
		0803FF24? br@0803FFA6

	p_02001B9C <pCurrBattleData>
		080014EC  br@080014F4
		0800531C  br@08005346




How the game accesses a pointer:
	s_02009CD0
		sChiefStruct[0x2C]
		
	p_020348BC <pCurrBattle>
		080B0860[0x18][0x3C]

	p_02009CFC <pCurrScript>
		02009CD0[0x2C]

	p_02001B9C <pCurrBattleData>
		02001B80[0x1C]