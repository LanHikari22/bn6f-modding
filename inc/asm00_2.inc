.ifndef INC_ASM00_2
.equ INC_ASM00_2, 0

/* Public Symbols */
.global sub_800ED80
.global sub_800ED90
.global sub_800F214
.global sub_800F23C
.global sub_800F26C
.global sub_800F29C
.global sub_800F2AA
.global sub_800F2B6
.global sub_800F2C6
.global sub_800F2FC
.global sub_800F322
.global sub_800F378
.global sub_800F46C
.global sub_800F486
.global sub_800F49E
.global sub_800F614
.global sub_800F656
.global sub_800F672
.global sub_800F884
.global sub_800F898
.global sub_800F8B0
.global sub_800F8CE
.global sub_800F90E
.global sub_800F964
.global sub_800F998
.global sub_800FA20
.global sub_800FA54
.global sub_800FAAC
.global sub_800FAE0
.global sub_800FAF6
.global sub_800FB54
.global sub_800FC30
.global sub_800FC7C
.global sub_800FC9E
.global sub_800FCFC
.global sub_800FDB6
.global sub_800FDC0
.global sub_800FE12
.global sub_800FE28
.global sub_800FE36
.global sub_800FE52
.global sub_800FFE4
.global sub_800FFEE
.global sub_800FFFE
.global sub_8010004
.global sub_8010018
.global sub_801002C
.global sub_80100EC
.global sub_801011A
.global sub_80101AE
.global sub_80101C4
.global sub_80101D4
.global sub_80101F8
.global sub_80102AC
.global sub_8010300
.global sub_8010312
.global sub_801031C
.global sub_801032C
.global sub_8010332
.global sub_80103A8
.global sub_80103BC
.global sub_80103EC
.global sub_80103F8
.global sub_8010474
.global sub_801055E
.global sub_801056A
.global sub_80105F2
.global sub_8010660
.global sub_80106C0
.global sub_8010740
.global sub_80107C0
.global sub_80107D4
.global sub_801086C
.global sub_80108FC
.global sub_80109A4
.global sub_8010C76
.global sub_8010CE0
.global sub_8010D20
.global sub_8010DD0
.global loc_8010DF6
.global sub_8011020
.global loc_8011044
.global loc_8011268
.global loc_8011384
.global sub_8011420
.global sub_8011450
.global sub_8011504
.global sub_801155A
.global sub_801156A
.global sub_801162A
.global sub_801164C
.global sub_8011680
.global sub_8011684
.global sub_8011688
.global loc_801168C
.global loc_8011690
.global loc_8011694
.global sub_80116AE
.global sub_80116D8
.global sub_8011714
.global loc_801171C
.global sub_8011764
.global sub_801177A
.global sub_8011790
.global loc_80117A4
.global sub_801265A
.global sub_80126E4
.global sub_8012792
.global sub_8012956
.global sub_801299C
.global sub_8012DFC
.global sub_8012E74
.global sub_8012EA8
.global sub_80133EC
.global sub_8013422
.global initStruct_8013438 // (void *struc) -> void
.global sub_80134C8
.global sub_8013554
.global sub_80135E8
.global sub_8013682 // (int idx) -> void*
.global sub_80136CC
.global sub_80136D8
.global sub_80136E4
.global sub_80136F0
.global sub_8013704
.global sub_8013754
.global sub_8013764
.global sub_8013774
.global sub_8013790
.global navicust_801379E // (int a1, int a2, int a3) -> void
.global sub_80137B6 // (int a1, int a2) -> u8
.global sub_80137E6
.global sub_80137FE
.global sub_8013816
.global sub_801382E
.global sub_8013846
.global sub_8013854
.global sub_8013864
.global sub_8013874
.global sub_8013884
.global sub_801393A
.global sub_80139C4
.global init_8013B4E // (bool a1, int a2) -> void
.global init_8013B64 // (int idx, int a2) -> void
.global sub_8013CC4
.global sub_8013D5E
.global sub_8013DA0
.global sub_8013FAE
.global sub_8013FD0
.global navicust_8014018 // (int idx_8014034) -> bool
.global sub_801401E
.global sub_8014040
.global sub_8014178
.global sub_80141AC
.global loc_8014216
.global sub_80142C2
.global sub_80143A6
.global loc_80143B4
.global sub_801443C
.global sub_8014446
.global sub_80144C0
.global sub_80147E4
.global sub_801482C
.global loc_801483C
.global sub_8015940
.global sub_8015952
.global sub_8015A16
.global sub_8015A38
.global sub_8015B00
.global sub_8015B54
.global sub_8015B5C
.global sub_8015BEC
.global sub_8015C32
.global sub_8015C48
.global sub_8015C94
.global sub_8015CC0
.global sub_8015D80
.global sub_8015E46
.global sub_8016004
.global sub_8016218
.global sub_801632C
.global sub_80165B8
.global sub_80165C2
.global sub_8016934
.global sub_80169BE
.global byte_8016B02
.global byte_8016B03
.global sub_8016B36
.global sub_8016B72
.global sub_8016C8A
.global sub_8016C9C
.global sub_8016CE8
.global sub_8016E64
.global sub_8016EC4
.global sub_80170C4
.global sub_80174FE
.global sub_80175B8
.global sub_8017688
.global sub_8017768
.global sub_8017CC0
.global sub_80182B4
.global sub_8018810
.global sub_8018842
.global sub_801986C
.global sub_8019892
.global sub_80198CE
.global off_8019B78
.global dword_8019C34
.global sub_8019F86
.global sub_8019F8C
.global sub_8019FB4
.global sub_801A00E
.global sub_801A018
.global sub_801A04C
.global sub_801A066
.global sub_801A074 // () -> void
.global sub_801A07C
.global sub_801A082
.global sub_801A0D4
.global sub_801A100
.global sub_801A140
.global sub_801A146
.global object_setFlag // (int a1) -> void
.global object_clearFlag // (int bitfield) -> void
.global object_getFlag // () -> int
.global sub_801A16C
.global sub_801A176
.global sub_801A180
.global sub_801A258
.global sub_801A264
.global sub_801A284
.global sub_801A29A
.global sub_801A2B0
.global sub_801A4D0
.global sub_801A4DC
.global sub_801A5E2
.global sub_801A66C
.global sub_801A67E
.global sub_801A7CC
.global sub_801A7F4
.global sub_801ABB8
.global sub_801AC6C
.global sub_801AD12
.global sub_801AD6A
.global sub_801AD9E
.global sub_801ADFA
.global sub_801AF44
.global sub_801B1C4
.global sub_801B394
.global sub_801B4D4
.global sub_801B610
.global loc_801B750
.global loc_801B878
.global sub_801BB1C
.global sub_801BB46
.global sub_801BBAC
.global sub_801BBF4
.global sub_801BC24
.global sub_801BC64
.global sub_801BCA6
.global sub_801BCD0
.global sub_801BCF4
.global sub_801BD3C
.global sub_801BDDE
.global sub_801BE04
.global nullsub_10
.global sub_801BE2A
.global sub_801BE70
.global sub_801BEB8
.global sub_801BEC2
.global sub_801BECC
.global sub_801BED6
.global sub_801BEE0
.global sub_801BF64
.global sub_801DA24
.global sub_801DA48
.global sub_801DACC
.global sub_801DBD4
.global sub_801DC36
.global sub_801DC7C
.global sub_801DCCC
.global sub_801DD34
.global sub_801DED0
.global sub_801DEEE
.global sub_801DF0C
.global sub_801DF8C
.global sub_801DF92
.global sub_801DFA2
.global sub_801DFB8
.global sub_801DFE4
.global sub_801E0A0
.global sub_801E0C8
.global sub_801E0D0
.global sub_801E15C
.global sub_801E228
.global sub_801E2BA
.global sub_801E398
.global sub_801E408
.global sub_801E474
.global sub_801E574
.global sub_801E5F8
.global sub_801E658
.global sub_801E660
.global sub_801E71C
.global sub_801E724
.global sub_801E754
.global sub_801E780
.global loc_801E792
.global sub_801E914
.global sub_801EB18
.global sub_801EC44


/* External Symbols */
.include "start.inc"
// .global start_
// .global dword_8000004
// .global dword_8000004

.include "asm00_0.inc"
// .global sound_play // () -> void
// .global musicGameState_8000784 // () -> void
// .global sub_80008C0
// .global CpuSet_ZeroFillWord // (void *memBlock, int size) -> void
// .global CpuSet_copyWords // (u32 *src, u32 *dest, int size) -> void
// .global loc_8000AC4
// .global loc_8000AC8
// .global decomp_initGfx_8000B8E // (u32 *dataRefs) -> void
// .global sub_8000C00
// .global sub_8000C5C
// .global sub_8000D84
// .global getPETNaviSelect // () -> u8
// .global calcAngle_800117C
// .global sub_80011A0
// .global sub_800139A
// .global change_20013F0_800151C // () -> int
// .global sub_8001532
// .global sub_8001562
// .global sub_800187C
// .global copyTiles // (int j, int i, int cpyOff, u16 *tileRefs) -> void
// .global sub_80018D0
// .global sub_80018E0

.include "sprite.inc"
// .global sprite_loadAnimationData // () -> void
// .global sprite_update
// .global sprite_load // (int a1, int a2, int a3) ->
// .global sprite_decompress
// .global sub_8002C7A
// .global sub_8002CCE
// .global sprite_setPallete // (int pallete) -> void
// .global sprite_getPallete
// .global sprite_setAnimation // (u8 a1) -> void
// .global sprite_forceWhitePallete

.include "asm00_1.inc"
// .global sub_8002DD8
// .global sub_8002E3C
// .global sub_8002ED0
// .global sub_8002EE8
// .global sub_8002EF6
// .global sub_8002F2C
// .global sub_8002F5C
// .global sub_8002F90 // () -> void
// .global sub_8002FB2
// .global object_freeMemory
// .global sub_800362C
// .global engine_setScreeneffect // (int a1, int a2) -> void
// .global engine_isScreeneffectAnimating // () -> zf
// .global sub_80077B4
// .global battle_isPaused
// .global battle_isTimeStop
// .global sub_800A104
// .global sub_800A11C
// .global battle_isBattleOver
// .global battle_setFlags
// .global battle_clearFlags
// .global battle_getFlags
// .global sub_800A704
// .global sub_800A70C
// .global sub_800A772
// .global sub_800A7E2
// .global sub_800A8F8
// .global sub_800A97A
// .global sub_800A998
// .global sub_800A9E2
// .global battle_networkInvert
// .global sub_800AA06
// .global sub_800AA1A
// .global sub_800AA40
// .global sub_800AB2E
// .global sub_800AB46
// .global sub_800AE44
// .global loc_800B79A
// .global sub_800B8EE

.include "object.inc"
// .global sub_800BEDA
// .global sub_800BF16
// .global loc_800BF30
// .global object_getPanelParameters
// .global sub_800C90A
// .global object_crackPanelDup1
// .global object_breakPanel_dup2
// .global object_setPanelType
// .global object_isValidPanel
// .global object_checkPanelParameters
// .global object_getPanelsExceptCurrentFilterred
// .global sub_800CEA0
// .global sub_800D086
// .global sub_800D120
// .global sub_800D15A
// .global sub_800E258
// .global sub_800E276 // (int a1, int a2) -> (int n1, int n2)
// .global sub_800E29C // () -> void
// .global sub_800E2AC
// .global sub_800E2C0
// .global sub_800E2C2
// .global object_getFlipDirection_800E2CA // () -> int
// .global object_getFlipDirection // (int a1, int a2) -> int
// .global object_subtractHP
// .global object_addHP
// .global sub_800E2FC
// .global sub_800E3BE
// .global sub_800E3DE
// .global object_calculateFinalDamage2
// .global sub_800E456 // () -> int
// .global sub_800E45E
// .global sub_800E468
// .global sub_800E5AC
// .global sub_800E618
// .global sub_800E6E8
// .global sub_800E730
// .global sub_800E994
// .global object_setCounterTime
// .global sub_800E9FA
// .global object_setInvulnerableTime
// .global sub_800EB08
// .global sub_800EB26
// .global object_spawnHiteffect
// .global object_getEnemyByNameRange
// .global sub_800EC56

.include "asm02.inc"
// .global getChip_8021DA8 // (int chip_idx) -> ChipData*
// .global sub_8021D14

.include "asm03_0.inc"
// .global sub_8027D10
// .global off_802CCB4
// .global sub_802CDD0
// .global sub_802CE60
// .global sub_802CE78
// .global sub_802CEF4
// .global sub_802CFF8
// .global sub_802D1B4
// .global sub_802D1BE
// .global sub_802D234
// .global get_802D246 // () -> int
// .global sub_802D26A
// .global sub_802D310
// .global sub_802D644
// .global sub_802D65E
// .global loc_802D714
// .global loc_802D926
// .global sub_802DCDE
// .global sub_802DCEC
// .global sub_802DD2A
// .global sub_802DFC8
// .global sub_802E032
// .global sub_802E066
// .global sub_802E070
// .global sub_802E09A
// .global sub_802E1D8
// .global sub_802E440
// .global sub_802E44A
// .global sub_802E454
// .global sub_802E4B8
// .global sub_802E830
// .global sub_802EF5C
// .global dword_802F0A8
// .global isActiveFlag_2001C88_entry // (int entryIdx, int byteFlagIdx) -> zf
// .global sub_802FE28
// .global sub_802FE48
// .global sub_802FE6A
// .global sub_802FE7A
// .global sub_80302A8
// .global sub_80302B6
// .global sub_803D0C8
// .global sub_803F524

.include "chatbox.inc"
// .global loc_8040000

.include "asm03_1.inc"
// .global render_graphicalText_8045F8C

.include "asm31.inc"
// .global sub_80BC844
// .global sub_80C41D8
// .global sub_80C4204
// .global sub_80C44A8
// .global sub_80C44C8
// .global sub_80C44D2
// .global sub_80C468C
// .global sub_80C46B0
// .global sub_80C46B6
// .global sub_80C46C0
// .global sub_80C4C12
// .global sub_80C4C3A
// .global sub_80C4FFE
// .global sub_80C53A6
// .global sub_80C7F20
// .global sub_80CC0B2
// .global sub_80CFBC4
// .global sub_80D99EC
// .global sub_80E05F6
// .global sub_80E08C4
// .global sub_80E0D98
// .global sub_80E0F02
// .global sub_80E11E0
// .global sub_80E1620
// .global sub_80E1662
// .global sub_80E192C
// .global sub_80E1A6A
// .global sub_80E1A86
// .global sub_80E1D7A
// .global sub_80E4D8A
// .global sub_80E4DA2
// .global sub_80E5410
// .global sub_80E544C
// .global sub_80E8124
// .global sub_80E90FE
// .global dword_80E98C0
// .global sub_80E996E
// .global sub_80EA438
// .global off_80EA814
// .global loc_80EA8D8
// .global off_80EAC60
// .global loc_80EAD9C
// .global loc_80EB04C
// .global loc_80EB234
// .global loc_80EE90C
// .global loc_80EEA3C
// .global loc_80EED56
// .global off_80F24D8
// .global off_80F253C
// .global sub_80FF668
// .global off_81090D0
// .global off_8109150
// .global sub_81096FA

.include "asm37_0.inc"
// .global sub_813BF1C


/* Undeclared Symbols */
.equ timer_2000000, 0x2000000
.equ unk_20018C0, 0x20018C0
.equ unk_200F3C4, 0x200F3C4
.equ unk_2020000, 0x2020000
.equ byte_20349C0, 0x20349C0
.equ unk_2034A60, 0x2034A60
.equ unk_2034F60, 0x2034F60
.equ byte_2035280, 0x2035280
.equ byte_2035281, 0x2035281
.equ byte_2035282, 0x2035282
.equ byte_203528B, 0x203528B
.equ byte_203528C, 0x203528C
.equ byte_2035292, 0x2035292
.equ byte_2035293, 0x2035293
.equ byte_2035295, 0x2035295
.equ byte_2035296, 0x2035296
.equ byte_2035297, 0x2035297
.equ byte_2035298, 0x2035298
.equ byte_2035299, 0x2035299
.equ byte_203529A, 0x203529A
.equ byte_203529B, 0x203529B
.equ byte_203529C, 0x203529C
.equ byte_203529E, 0x203529E
.equ byte_203529F, 0x203529F
.equ word_20352A0, 0x20352A0
.equ word_20352A2, 0x20352A2
.equ word_20352A4, 0x20352A4
.equ word_20352A6, 0x20352A6
.equ word_20352A8, 0x20352A8
.equ word_20352AA, 0x20352AA
.equ word_20352AC, 0x20352AC
.equ word_20352AE, 0x20352AE
.equ word_20352B0, 0x20352B0
.equ word_20352B2, 0x20352B2
.equ word_20352B4, 0x20352B4
.equ word_20352B8, 0x20352B8
.equ dword_20352C0, 0x20352C0
.equ dword_20352C4, 0x20352C4
.equ dword_20352C8, 0x20352C8
.equ dword_20352E0, 0x20352E0
.equ dword_20352E0, 0x20352E0
.equ dword_20352E0, 0x20352E0
.equ dword_20352E0, 0x20352E0
.equ dword_20352E4, 0x20352E4
.equ dword_2035310, 0x2035310
.equ dword_20367E0, 0x20367E0
.equ dword_20367F0, 0x20367F0
.equ byte_20367F4, 0x20367F4
.equ dword_2036820, 0x2036820
.equ byte_2036840, 0x2036840
.equ byte_2036841, 0x2036841
.equ word_2036842, 0x2036842
.equ byte_2036846, 0x2036846
.equ byte_2036847, 0x2036847
.equ byte_2036848, 0x2036848
.equ word_203684A, 0x203684A
.equ word_203684C, 0x203684C
.equ unk_2036850, 0x2036850
.equ word_2036852, 0x2036852
.equ word_2036852, 0x2036852
.equ byte_2036857, 0x2036857
.equ byte_2036858, 0x2036858
.equ byte_2036859, 0x2036859
.equ unk_20384F0, 0x20384F0
.equ dword_2038528, 0x2038528
.equ unk_203A380, 0x203A380
.equ unk_203A980, 0x203A980
.equ unk_203A990, 0x203A990
.equ unk_203C4E0, 0x203C4E0
.equ dword_203CA48, 0x203CA48
.equ dword_203CA4C, 0x203CA4C
.equ unk_203CB10, 0x203CB10
.equ unk_203CCE0, 0x203CCE0
.equ dword_203CDF0, 0x203CDF0
.equ unk_203CE00, 0x203CE00
.equ byte_203CED0, 0x203CED0
.equ byte_203CED1, 0x203CED1
.equ byte_203CED3, 0x203CED3
.equ byte_203CED4, 0x203CED4
.equ dword_203CED8, 0x203CED8
.equ dword_203CFA0, 0x203CFA0
.equ unk_203EB00, 0x203EB00
.equ byte_203EB50, 0x203EB50
.equ word_203EB52, 0x203EB52
.equ byte_203EB54, 0x203EB54
.equ byte_203EB55, 0x203EB55
.equ word_203EB56, 0x203EB56
.equ byte_203EB58, 0x203EB58
.equ byte_203EB59, 0x203EB59
.equ dword_203EB5C, 0x203EB5C
.equ dword_203EB60, 0x203EB60
.equ unk_203EBA0, 0x203EBA0
.equ unk_203EDA0, 0x203EDA0
.equ unk_203EFA0, 0x203EFA0
.equ dword_203F6A0, 0x203F6A0
.equ dword_203F7E0, 0x203F7E0
.equ unk_3001670, 0x3001670
.equ word_3001684, 0x3001684
.equ unk_30016B0, 0x30016B0
.equ unk_30016D0, 0x30016D0
.equ unk_30016F0, 0x30016F0
.equ unk_3001A80, 0x3001A80
.equ unk_3001AC0, 0x3001AC0
.equ unk_3001AE0, 0x3001AE0
.equ unk_3001B00, 0x3001B00
.equ loc_3007550, 0x3007550
.equ loc_300777C, 0x300777C
.equ LCDControl, 0x4000000
// .global off_801ECB4
.equ word_801ED6C, 0x801ED6C
.equ word_801EDB4, 0x801EDB4
.equ dword_801EDFC, 0x801EDFC
.equ word_801EE14, 0x801EE14
.equ word_801EE58, 0x801EE58
.equ dword_801EE78, 0x801EE78
.equ dword_801EE98, 0x801EE98
.equ dword_801EF10, 0x801EF10
.equ off_801EF30, 0x801EF30
.equ off_801EF4C, 0x801EF4C
.equ off_801EF68, 0x801EF68
.equ pt_801EF84, 0x801EF84
.equ pt_801EFD4, 0x801EFD4
.equ word_801F374, 0x801F374
.equ byte_801F376, 0x801F376
.equ word_801F554, 0x801F554
.equ byte_801F556, 0x801F556
.equ off_801FD64, 0x801FD64
.equ off_801FD90, 0x801FD90
.equ dword_801FDC0, 0x801FDC0
// .global dword_8020354
.equ dword_8020404, 0x8020404
.equ dword_80209CC, 0x80209CC
.equ off_80209EC, 0x80209EC
.equ dword_8020B2C, 0x8020B2C
.equ dword_8020B8C, 0x8020B8C
.equ dword_8020E54, 0x8020E54
.equ dword_8020FE0, 0x8020FE0
.equ dword_8021220, 0x8021220
.equ dword_80212D4, 0x80212D4
.equ dword_8021300, 0x8021300
.equ byte_8021369, 0x8021369
.equ byte_802136A, 0x802136A
.equ byte_802136B, 0x802136B
.equ byte_802136C, 0x802136C
.equ dword_86A5D60, 0x86A5D60
.equ dword_86B7AE0, 0x86B7AE0
.equ dword_86B7B20, 0x86B7B20
.equ dword_86B7B60, 0x86B7B60
.equ dword_86B7BA0, 0x86B7BA0
.equ dword_86B7BE0, 0x86B7BE0
.equ dword_86B7C20, 0x86B7C20
.equ dword_86B7C60, 0x86B7C60
.equ dword_86B7CA0, 0x86B7CA0
.equ dword_86B7CE0, 0x86B7CE0
.equ dword_86B7D20, 0x86B7D20
.equ dword_86B7D60, 0x86B7D60
.equ dword_86BA0A0, 0x86BA0A0
.equ dword_86BA120, 0x86BA120
.equ dword_86E0AB8, 0x86E0AB8
.equ dword_86E0AF8, 0x86E0AF8
.equ dword_86E0B38, 0x86E0B38
.equ dword_86E0B78, 0x86E0B78
.equ dword_86E0BB8, 0x86E0BB8
.equ dword_86E0BF8, 0x86E0BF8
.equ dword_86E0C38, 0x86E0C38
.equ dword_86E0C78, 0x86E0C78
.equ dword_86E0CB8, 0x86E0CB8
.equ dword_86E0CF8, 0x86E0CF8
.equ dword_86E0D38, 0x86E0D38
.equ dword_86E0D78, 0x86E0D78
.equ dword_86E0DB8, 0x86E0DB8
.equ dword_86E0DF8, 0x86E0DF8
.equ dword_86E0E38, 0x86E0E38
.equ dword_86E0E78, 0x86E0E78
.equ dword_86E0EB8, 0x86E0EB8
.equ dword_86E0EF8, 0x86E0EF8
.equ dword_86E0F38, 0x86E0F38
.equ dword_86E0F78, 0x86E0F78
.equ dword_86E0FB8, 0x86E0FB8
.equ dword_86E0FF8, 0x86E0FF8
.equ dword_86E1038, 0x86E1038
.equ dword_86E1078, 0x86E1078
.equ dword_86E10B8, 0x86E10B8
.equ dword_86E10F8, 0x86E10F8
.equ dword_86E1138, 0x86E1138
.equ dword_86E1178, 0x86E1178
.equ dword_86E11B8, 0x86E11B8
.equ dword_86E11F8, 0x86E11F8
.equ dword_86E1C78, 0x86E1C78
.equ dword_86E1CD8, 0x86E1CD8
.equ dword_86E489C, 0x86E489C
.equ dword_86E4C1C, 0x86E4C1C
.equ dword_86E611C, 0x86E611C
.equ dword_86E958C, 0x86E958C
.equ dword_86E960C, 0x86E960C
.equ dword_86E966C, 0x86E966C
.equ off_86E968C, 0x86E968C
.equ dword_86E97CC, 0x86E97CC
.equ dword_86E98CC, 0x86E98CC
.equ dword_86E994C, 0x86E994C
.equ dword_86E9A0C, 0x86E9A0C
.equ dword_86E9A2C, 0x86E9A2C
.equ dword_86E9F2C, 0x86E9F2C
.equ dword_86EA42C, 0x86EA42C
.equ dword_86EA92C, 0x86EA92C
.equ aBdfhjlnprtvxzB, 0x86F0300
.equ aLoxajs, 0x86F0374
.equ dword_86F2900, 0x86F2900
.equ dword_86F2E00, 0x86F2E00
.equ dword_86F2E14, 0x86F2E14
.equ dword_86F2E20, 0x86F2E20
.equ dword_86F2E34, 0x86F2E34
.equ dword_86F2E40, 0x86F2E40
.equ dword_86F2E54, 0x86F2E54
.equ dword_872CE94, 0x872CE94
.equ unk_872D014, 0x872D014
.equ unk_872D094, 0x872D094
.equ dword_872D694, 0x872D694
.equ dword_872D814, 0x872D814
.equ dword_872D914, 0x872D914
.equ dword_872D994, 0x872D994
.equ dword_872DB14, 0x872DB14
.equ unk_872DC94, 0x872DC94
.equ dword_872DE14, 0x872DE14
.equ unk_872DF94, 0x872DF94
.equ dword_872E094, 0x872E094
.equ dword_872E194, 0x872E194
.equ dword_872E294, 0x872E294
.equ dword_872E394, 0x872E394
.equ dword_872E494, 0x872E494
.equ dword_872E594, 0x872E594
.equ dword_872E694, 0x872E694
.equ dword_872E794, 0x872E794
.equ dword_872E894, 0x872E894
.equ dword_872E994, 0x872E994
.equ dword_872EF14, 0x872EF14
.equ dword_872F014, 0x872F014
.equ dword_872F114, 0x872F114

.endif // INC_ASM00_2
