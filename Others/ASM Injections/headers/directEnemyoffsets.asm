/**
 * ROM Offsets for enemy offsets to modify AI/attacks.
 * Data imported from TREZ
 * Src: "http://forums.therockmanexezone.com/topic/8591295/1/"
 * Date created: 7/21/2017
 * Description
 * 
*/
#ifndef MMBN6_HEADER
#define MMBN6_HEADER
.thumb

// Navis
 
.equ pHeatman, 				080F2A28 // Heatman
.equ pAIHeatman, 			080F2B49 // Heatman's AI
.equ pMVHeatman0,			080F2ED5 // Heatman's Move
.equ pMVHeatman1,			080F2FBB // Heat Wave
.equ pMVHeatman2,			080F3125 // Heat Press
.equ pMVHeatman3,			080F3429 // Flamethrower
 
.equ pElecman,				080F38E0 // Elecman
.equ pAIElecman,			080F3A05 // Elecman's AI
.equ pMVElecman0,			080F3D25 // Elecman's Move
.equ pMVElecman1,			080F3E2B // DollThunder
.equ pMVElecman2,			080F3EC7 // Conductors
.equ pMVElecman3,			080F40D9 // ElecSword
.equ pMVElecman4,			080F4299 // Random Lightning Strike

.equ pSlashman,				080F47A8 // Slashman
.equ pAISlashman,			080F48C9 // Slashman's AI
.equ pMVSlashman0,			080F4C25 // Slashman's Move
.equ pMVSlashman1,			080F4D1F // Double Slash
.equ pMVSlashman2,			080F4FFF // Spinning Slash
.equ pMVSlashman3,			080F5281 // Kunais

.equ pKillerman,			080F580C // Killerman
.equ pAIKillerman,			080F5929 // Killerman's AI
.equ pMVKillerman0,			080F5B85 // Killerman's Move
.equ pMVKillerman1,			080F5C67 // Death Scythe
.equ pMVKillerman2,			080F5DD3 // KillerEye Beam

.equ pChargeman,			080F6368 // Chargeman
.equ pAIChargeman,			080F648D // Chargeman's AI
.equ pMVChargeman0,			080F6725 // Chargeman's Move
.equ pMVChargeman1,			080F68C5 // Chargeman's Rapid Charging
.equ pMVChargeman2,			080F6BEB // Chargeman's Leaving the field
.equ pMVChargeman3,			080F6DE5 // Chargeman's Volcano Eruption
.equ pMVChargeman4,			080F66ED // Chargeman's Cargo

.equ pAquaman,				080F7550 // Aquaman
.equ pAIAquaman,			080F7671 // Aquaman's AI
.equ pMVAquaman0,			080F79F1 // Aquaman's Move
.equ pMVAquaman1,			080F7AD3 // Bubble Shot
.equ pMVAquaman2,			080F7C5F // Aqua Hose
.equ pMVAquaman3,			080F7EA7 // Sprinkler

.equ pTomahawkman,			080F8308 // Tomahawkman
.equ pAITomahawkman,		080F8429 // Tomahawkman's AI
.equ pMVTomahawkman0,		080F870D // Tomahawkman's Move
.equ pMVTomahawkman1,		080F87FF // Axe Throw
.equ pMVTomahawkman2,		080F8997 // Tomahawk Axe
.equ pMVTomahawkman3,		080F8B45 // Eagle Tomahawk

.equ pTenguman,				080F8EC0 // Tenguman
.equ pAITenguman,			080F8FE1 // Tenguman's AI
.equ pMVTenguman0,			080F92D1 // Tenguman's Move
.equ pMVTenguman1,			080F93C3 // Tengu Nose
.equ pMVTenguman2,			080F953D // Tengu Tornado
.equ pMVTenguman3,			080F96C3 // Tengu Dash

.equ pGroundman,			080F9C54 // Groundman
.equ pAIGroundman,			080F9D75 // Groundman's AI
.equ pMVGroundman0,			080FA0B1 // Groundman's Move
.equ pMVGroundman1,			080FA1AF // Drill Beneath
.equ pMVGroundman2,			080FA41F // Triple Drill
.equ pMVGroundman3,			080FA6D5 // Rock Crusher

.equ pDustman,				080FACB0 // Dustman
.equ pAIDustman,			080FADD1 // Dustman's AI
.equ pMVDustman0,			080FB115 // Dustman's Move
.equ pMVDustman1,			080FB207 // Dust Break
.equ pMVDustman2,			080FB3F9 // Panel Shot
.equ pMVDustman3,			080FB5B9 // Inhale + Crush

.equ pProtoman,				080FB8B4 // Protoman
.equ pAIProtoman,			080FB9DD // Protoman's AI
.equ pMVProtoman0,			080FC075 // Protoman's Move
.equ pMVProtoman1,			080FC153 // Hero Sword
.equ pMVProtoman2,			080FC303 // Shield + Slash
.equ pMVProtoman3,			080FC5FB // Step Sword
.equ pMVProtoman4,			080FC7E7 // Cross-Slash
.equ pMVProtoman5,			080FC9C9 // Blade Dance

.equ pBlastman,				080FD018 // Blastman
.equ pAIBlastman,			080FD139 // Blastman's AI
.equ pMVBlastman0,			080FD4C9 // Blastman's Move
.equ pMVBlastman1,			080FD5AF // Row Bomb
.equ pMVBlastman2,			080FD719 // Tornado
.equ pMVBlastman3,			080FD8D5 // Fire Balls

.equ pDiveman,				080FDCC4 // Diveman
.equ pAIDiveman,			080FDDE5 // Diveman's AI
.equ pMVDiveman0,			080FE0D5 // Diveman's Move
.equ pMVDiveman1,			080FE21F // Emerge
.equ pMVDiveman2,			080FE331 // Dive Bomb
.equ pMVDiveman3,			080FE453 // Dive Wave

.equ pCircusman,			080FE7A4 // Circusman
.equ pAICircusman,			080FE8C5 // Circusman's AI
.equ pMVCircusman0,			080FEC91 // Circusman's Move
.equ pMVCircusman1,			080FEE15 // Happy Clap
.equ pMVCircusman2,			080FF043 // Circus Lions
.equ pMVCircusman3,			080FF249 // Tent Attack

.equ pJudgeman,				080FF7C4 // Judgeman
.equ pAIJudgeman,			080FF8E5 // Judgeman's AI
.equ pMVJudgeman0,			080FFB89 // Judgeman's Move
.equ pMVJudgeman1,			080FFC83 // Electric Whip
.equ pMVJudgeman2,			080FFE27 // Biting Books
.equ pMVJudgeman3,			080FFF09 // Judgement Manual

.equ pElementman,			081001BC // Elementman
.equ pAIElementman,			081002E9 // Elementman's AI
.equ pMVElementman0,		0810075D // Elementman's Move
.equ pMVElementman1,		0810084F // Color Change
.equ pMVElementman2,		08100945 // Meteors
.equ pMVElementman3,		08100A2D // Freeze
.equ pMVElementman4,		08100C1D // Wood Tower
.equ pMVElementman5,		08100DD7 // Lightning Strike
.equ pMVElementman6,		08100E9D // Transition Tornado

.equ pColonel,				0810123C // Colonel
.equ pAIColonel,			08101361 // Colonel's AI
.equ pMVColonel0,			081030A1 // Colonel's Move
.equ pMVColonel1,			08103177 // Screen Divide
.equ pMVColonel2,			081032F5 // Missiles
.equ pMVColonel3,			08103477 // Soldiers
.equ pMVColonel4,			0810359F // Aspire Break

.equ pBass,					08101854 // Bass
.equ pAIBass,				08101A69 // Bass's AI
.equ pMVBass,				08102291 // Bass's Move
.equ pMVBass,				081023A1 // Shooting Buster
.equ pMVBass,				081024AB // Hell's Rolling
.equ pMVBass,				08102563 // Varying Attack
.equ pMVBass,				08102963 // Cybeast Power

.equ pGregar,				08103B88 // Gregar

// No more offsets available for Gregar

.equ pFalzar,				08105390 // Falzar
.equ pAIFalzar,				081054B9 // Falzar's AI
.equ pMVFalzar0,			08105971 // Falzar's Move
.equ pMVFalzar1,			08105A97 // Feather Storm
.equ pMVFalzar2,			08105C97 // Falzar Twister
.equ pMVFalzar3,			08105E61 // Fire Birds
.equ pMVFalzar4,			08105FE7 // Random Claws
.equ pMVFalzar5,			081061D7 // Spinning Tornado

.equ pGBeast,				081067FC // GBeast
.equ pAIGBeast,				08106925 // GBeast's AI
.equ pMVGBeast0,			08106DED // GBeast's Move
.equ pMVGBeast1,			08106ECF // Fire Sword
.equ pMVGBeast2,			081070A9 // Thunder
.equ pMVGBeast3,			08107185 // Beast Slash
.equ pMVGBeast4,			081073F7 // Paralyze Slash + Gregar Buster
.equ pMVGBeast5,			08107751 // Heat Breath

.equ pFBeast,				08107B24 // FBeast
.equ pAIFBeast,				08107C4D // FBeast's AI
.equ pMVFBeast0,				0810821D // FBeast's Move
.equ pMVFBeast1,				081082FF // Aqua Needle
.equ pMVFBeast2,				081083C7 // Boomerang
.equ pMVFBeast3,				081084C1 // Beast Slash
.equ pMVFBeast4,				0810874B // Paralyze Slash + Feather Buster
.equ pMVFBeast5,				08108ABD // Falzar Twister





// Viruses
.equ pDummy,				 
.equ pMettaur,				08109BD0 // Mettaur
.equ pPiranha,				0810A2C0 // Piranha
.equ pHeady,				0810A840 // Heady
.equ pSwordy,				0810AE44 // Swordy
.equ pKillerEye,			0810B78C // KillerEye
.equ pQuaker,				0810BECC // Quaker
.equ pCatack,				0810C35C // Catack
.equ pChampy,				0810C8CC // Champy
.equ pWindBox,				0810D008 // WindBox
.equ pTrumpy,				0810D16C // Trumpy
.equ pOldStove,				0810D6F8 // OldStove
.equ pHauntedCandle,		0810DD10 // HauntedCandle
.equ pKettle,				0810E3E8 // Kettle
.equ pPuffy,				0810EC80 // Puffy
.equ pStarFish,				0810F200 // StarFish
.equ pEarthDragon,			0810F4E4 // EarthDragon
.equ pScareCrow,			08110290 // ScareCrow
.equ pPulseBulb,			08110628 // PulseBulb
.equ pBigHat,				08111130 // BigHat
.equ pBombCorn,				0811190C // BombCorn
.equ pShrubby,				08111FF8 // Shrubby
.equ pHoneyBomber,			081126DC // HoneyBomber
.equ pGunner,				08112B94 // Gunner
.equ pFighterPlane,			0811323C // FighterPlane
.equ pDarkMech,				08113754 // DarkMech
.equ pSnakeArm,				081143C8 // SnakeArm
.equ pArmadillo,			081150AC // Armadillo
.equ pCragger,				08115704 // Cragger
.equ pNightmare,			08115BEC // Nightmare


/*
080E Attack Set 1
 
60CD 080E // VDoll Damage Curse
68DD 080E // Judgeman Says: "MegaMan, thou must not move."
72A4 080E // LifeSync
8269 080E // BodyGuard
8B45 080E // Meteor Knuckle
8E19 080E // Form Program Advance
9025 080E // Beat Steals Chip
9461 080E // ColonelForce
95B5 080E // BugFrag Use
A011 080E // BigHook
B437 080E // Charged Buster Shot
B629 080E // Mini Bomb
B777 080E // Step Sword
BC0F 080E // Cannon
C02B 080E // YoYo
C0E7 080E // BatCannon
C1F1 080E // GroundBeast Special Move
C45F 080E // Gregar Buster
C5BD 080E // Feather Buster
C7A7 080E // Thunder
C885 080E // AirShot
C961 080E // CrackShot
CA35 080E // Buster Shot
CACB 080E // TankCannon
CBB1 080E // SpoutCross Chargeshot
CCB1 080E // AirHockey
CDFD 080E // TrainArrow
CF2F 080E // MachineGun
D091 080E // CornShot
D13F 080E // Shield NCP
D375 080E // DrillArm
D455 080E // Tornado
D55D 080E // WideShot
D6FD 080E // Endless AquaNeedle
D6E7 080E // AquaNeedle
D749 080E // Bugged Buster
D811 080E // H-Burst
D8C5 080E // HeatBeast Special Move
D9AF 080E // RlngLog
DCC1 080E // AirSpin
DD81 080E // RiskyHoney
DE7F 080E // SpoutBeast Special Move
DF5D 080E // ElecBeast Special Move
E0BD 080E // ElecCross DollThunder
E193 080E // WindRack => Tengucross
E2A1 080E // MoonBlade
E34B 080E // Sword Toss
E55F 080E // ElecPulse
E635 080E // AuraHead
E6FD 080E // MagnetCoil
E90D 080E // AntiDamage
ED57 080E // BodyGuard
EFDD 080E // GroundCross Ground Drill
F1ED 080E // TomahawkBeast Special Move
F283 080E // ChargeBeast Special Move
F4B5 080E // HeatDragon
F535 080E // That Unknown Freezing Move
FA55 080E // ChargeCross Charge
FAD9 080E // Invincible No Move
FC1D 080E // DustCross DustBreak
FCB5 080E // DustCross Inhale


080F Attack Set 2
 
0095 080F // Summon Meteor
00F3 080F // Bass Blaster
020F 080F // BloodRain
070F 080F // Heatman ChargeShot
0779 080F // Heat Press (Heatman chip attack)
094D 080F // Elecman ChargeShot
09B9 080F // ElecSword (Elecman chip attack)
0C49 080F // Slashman ChargeShot
0CB1 080F // Slashman Tornado (Slashman chip attack)
0FB5 080F // Eraseman ChargeShot
1057 080F // Erase Beam (Eraseman chip attack)
1199 080F // Chargeman ChargeShot
1335 080F // Volcano Eruption (Chargeman chip attack)
153D 080F // Spoutman ChargeShot
15CF 080F // Drip Shower (Spoutman chip attack)
17C5 080F // Tomahawkman ChargeShot
18AD 080F // Eagle Tomahawk (Tomahawkman chip attack)
19D5 080F // Tenguman ChargeShot
1A47 080F // Tengu Twister (Tenguman chip attack)
1BA9 080F // Groundman ChargeShot
1C1D 080F // RC Break (Groundman chip attack)
1F19 080F // Dustman ChargeShot
1FA1 080F // Dust Inhale & Smash (Dustman chip attack)


080C Attack Set 3
 
1DA1 080C // Recover 50 HP
215D 080C // Reappear as FBeast
2771 080C // TwinLeaders Protoman Portion Compilation
2799 080C // Protoman Appear in TwinLeaders
2855 080C // Protoman's Portion of TwinLeaders
2AF9 080C // Delta Ray Attack Compilation
2B21 080C // Delta Ray Appear and Ching
2BE7 080C // Delta Ray After Appear
3001 080C // NumberBall Load Edit
30C3 080C // NumberBall Attack Edit
3219 080C // Rush Appear Edit
3321 080C // Rush Jump On You Edit
3735 080C // Enemy Drops through Field
37BD 080C // Enemy Drops through Field
3A79 080C // Bass Rake Giga Chip
3CE9 080C // Bass Giga Chip Disappear
3DDD 080C // BassAnly Giga Chip


080B Attack Set 4
 
E8AF 080B // MasterCross No Time-Freeze No Explosion
E879 080B // MasterCross No Time-Freeze
AC99 080B = Cannon Meteor
CC0D 080B = Corn Fiesta (freezes shortly after)
D115 080B = Strange combo (Protoman's actions from Double Hero and a reverse Tank Cannon)
DD89 080B = Rapid buster shots
DEC1 080B = Forfeit (just vanishes and the battle is over)
E175 080B = Django portion of Crossover PA
EC69 080B = Reverse Tank Cannon
EF2D 080B = Wind Rack (recovery at the end)
F325 080B = Meteors (sad one)
F3B1 080B = Spontaneous color change
F801 080B = Reappear with a different color
F889 080B = Gospel Cannon (stays on face)
F9B1 080B = Forfeit (after flashes)
FAD9 080B = Dark Sword (from Darkness PA)


Mixed Attack Set 5
 
FC29 080B = Fade out; forfeit
2855 080C = Protoman's Step Sword (chip)
C3B9 080C = Float in the air
DAD9 080C = Implant Time bomb (funny, but makes YOU lose)
6397 0801 = Basic appear
8377 080B = Colonel's Z Cut
D587 080B = Protoman portion of Twin Leaders
E2FF 080B = Suicide
EFE3 080B = Last portion of Master Cross PA (really awesome!)
F44B 080B = Bizarre spontaneous color change
F56B 080B = Alpha missile? (explodes at the end and ends battle)
0913 080C = Roll's move
0B77 080C = Jump in the air (and never come down)
2BE7 080C = Delta Ray (can't complete)
3323 080C = Step on you (end battle)
2FC3 080D = Escape


080E Attack set 6
 
B437 080E = Non-flinching explosive shot
B777 080E = Step Sword
BC0F 080E = Standard Cannon
C02B 080E = YoYo (easily modifiable; default 7 for Bass)
C0E7 080E = Bat Cannon
C7A7 080E = Thunderball
CACB 080E = Tank Cannon (chip attack)
CF2F 080E = Mach Gun (awesome)
D13F 080E = Shield (NCP)
D6E7 080E = Aqua Needle (chip attack)
D9AF 080E = Rolling Log
DE7F 080E = AquaBeast's Aqua Swirl (awesome attack)
E193 080E = Wind Rack (sans the item)
E34B 080E = Sword Toss (easily modifiable)
E55F 080E = ElecPulse (levels vary)
ED57 080E = Shuriken (default 7; can be lethal)
F283 080E = ChargeBeast's grega head (awesome)
F62F 080E = Sword (thus can be transformed into any sword)
F7E3 080E = Sword (again)
AF57 080E = Grega's head dash? (no real function and ends shortly)


Mixed Attack Set 7
 
00F3 080F = Spontaneous combustion
070F 080F = Create fire (like Heatman's charge attack)
1057 080F = Killerman's Beam
15CF 080F = Aquaman's Drip Shower
1A47 080F = Tenguman's Twister (special chip attack)
2FBB 080F = Heatman's Heat Wave
3EC7 080F = Quick move
4D1F 080F = Slashman's Slash
4FFF 080F = Slashman's Rolling Blade
5C67 080F = Killerman's Scythe
9DD3 0810 = Mettaur's Shockwave
ABAD 080B = Elementman chip color warp
17C5 080F = Tomahawkman's T Swing (playable)
18AD 080F = Tomahawkman's E Tomahawk
19D5 080F = Tenguman's Nose (tip paralyzes)
1C1D 080F = Groundman's RC Break (special chip)
0799 080F = Heatman's Heat Press (special chip)


080E Attack Set 8
 
B629 080E = Mini Bomb
BD9D 080E = Time Freeze (remember this one? should turn into almost anything.)
BF11 080E = Vulcan
C1F1 080E = Ground Beast Dash
C351 080E = Navi Summon (can't make more than Roll come out)
C39D 080E = Poof (also turns to other things somehow)
C45F 080E = Rapidfire buster
C5BD 080E = Faltzer Beast buster
C845 080E = Recovery
C885 080E = AirShot
C961 080E = PanelShot
CA35 080E = CopyDamage
CBB1 080E = Spreader
CD29 080E = FireBurner
CDFD 080E = TrainArrow
D2F9 080E = StarFish
D8C5 080E = HeatBeast's Heat Breath
DAE1 080E = GunSol
DCC1 080E = AirSpin
DF5D 080E = ElecBeast's Elec Breath
E045 080E = TenguBeast's Tengu Twister
E635 080E = AuraHead
E7D1 080E = KillerCross's Beam
E841 080E = KillerBeast's Tail
EA3D 080E = AntiSword (cheap)
ED57 080E = Bodyguard (its different...)
EE61 080E = Slash X
F1ED 080E = TomahawkBeast's Wing attack
F329 080E = DustBeast's Special attack
FB45 080E = FireDragon
F535 080E = Mysterious attack (may slow game)
F971 080E = Z Saver (just the last part, but can be modified to reel in)
FC1D 080E = Scrap Reborn


Mixed Attack Set 9
 
FEE1 080E = Z Saver (the real one!)
0095 080F = Meteors (the charge attack one)
00F3 080F = Rapid buster shots
F97D 080B = Tank Cannon
FA1D 080B = Bass's Arrival from Darkness PA
78B7 0801 = Hurt



080B Attack Set 10
 
.equ 080BF9B1 = SunMeteor Crash (You can't see it, Battle ends afterwards)
.equ 080BF07B = Throw a field explosion (10 damage)
.equ 080BF0F9 = Slightly delayed Recovery
.equ 080bF001 = Buster Charge (Useless)
.equ 080BEF49 = WindRack (Infinate)
.equ 080BEFC1 = Double recovery (weak)
.equ 080BEA11 = End Battle Immediately (Results Screen)
.equ 080BEE63 = DrillArm with Recovery (Doesn't go away after)
.equ 080BCC2D = CornFiesta (Works with different levels though) (On Level 4 It had neverending fiesta)
.equ O80BCC0D = CornFiesta (Ends but game crashes after)
.equ 090BCAD5 = Looks like a reverse 'Bass in DarknessPA'. Battle ends afterwards. (Enemy Files Away)
.equ 080BCA25 = Disappear, (Shield Noises, Reappear noises), Become White Dot when hit
.equ 080BC8A9 = Sprite Change (Game Slows)
.equ 080BC58D = Palette Go Up A Level (Only 1 per battle)
.equ 080BC525 = Become Invisible (Continues AI,When Hit, Become Green Dot)
.equ 080BEA41 = single megaman cross split from MasterCross (Enemy is the cross)
.equ 080BE7BD = Turn Into ElecCross (Only shows when hit)
.equ 080BEBBD = Middle Panel Movement (?)
.equ 080BE4F9 = Some... Random Attack that does not appear to work, but looks valid
.equ 080BBC81 = Some Unknown Attack (With weird sound) (Does Nothing, Lags game)
.equ 080BBCD9 = Add Rockets to Navi (Groundman's Drill Dive)
.equ 080BBD61 = GroundMan Drop Rocks (Perfect Attack)
.equ 080B99D5 = Change To Diveman
.equ 080BB9F1 = Chargeman's Traincars
.equ 080BBA27 = Chargeman's Train (Engine)
.equ 080BB939 = Change To ChargeMan
.equ 080BB711 = Killerman's Tracking Line (Does not move back and forth, does not do anything)
.equ 080BB79B = Killerman's Beam/Cannon (Cannon at bottom three levels)
.equ 080BB62D = Change To Killerman
.equ 080BB399 = Magnum Cursor 3rd column (On mine, i lost ability to move)
.equ 080BB3F7 = Magnum on back two columns (Blinks, you can move)
.equ 080BB42F = Magnum Explosion (Panels Offscreen, Never ends)
.equ 080BB049 = Cursor of Flame Candle Chip (Game Control is lost)
.equ 080BB099 = Scrolling Flame Candle Chip Cursor (May lose game control)
.equ 080BB0D3 = FlameCandle Chip Throw Flame (Never hits)
.equ 080BABAD = Change of Palette (ElementMan?) 
.equ 080BADB5 = Super Yoyo (More than one per throw) (Never Comes back to him)
.equ 080BAAB1 = Change To ElementMan
.equ 080BA72D = Change To JudgeMan
.equ 080BA4BB = Enemy randomly falls...? (Weird)
.equ 080BA529 = Weird sound then cannon shooting
.equ 080BA56D = Explosions/Graphic Frags, Then Yoyo
.equ 080BA5Ab = Glitchy Recovery
.equ 080BA5D3 = Recovery
.equ 080BA529 = Float up, weird data and surrender
.equ 080BA389 = Change To CircusMan
.equ 080BA091 = SlashMan's Kunai Throw (Chip) (Hits Enemy)
.equ 080BA0FD = StepYoyo (Touching Navi does not hurt you)
.equ 080BA153 = Gregar Slash Then Poof (Game Slows)
.equ 080B9F69 = Change To SlashMan
.equ 080B9D37 = Turn Invisible Until Next Hit
.equ 080B9D6f = TenguMan's Bottom Two Rows Attack (Game Slows)
.equ 080B9C39 = Change To TenguMan
.equ 080B9A61 = YoYo Sound
.equ 
.equ 
.equ 080B Attack Set 11
.equ  
.equ 080B9ABB = Movement Sprite, Screen Shakes
.equ 080B9AED = DiveMan's Wave Throw (White Dots)
.equ 080B98ED = TomahawkMan's Slash (Game Slows)
.equ 080B961B = Shoot AquaShot Then YoYo (Game Slows)
.equ 080B966D = AquaCannon (AquaMan's Hose but It turns into Cannon, Game Slows)
.equ 080B966D = AquaWater (The Attack part of AquaMan's Hose)
.equ 080B94E1 = Change To AquaMan
.equ 080B93C7 = Gregars Electricity (Does not work, Severe Game Slowdown)
.equ 080B92DD = Change To ElecMan
.equ 080B91B1 = HeatMan Spreading Flame
.equ 080B909D = Change To HeatMan
.equ 080B8FB7 = Shoot Blastman 3 Wide Bomb Shot (WhiteDot)
.equ 080B8EC5 = Change to BlastMan
.equ 080B8B09 = Throw BlizzardBall (Never Ends)
.equ 080B86F9 = GolemFist Where Enemy Stands (Enemy Then stands still)
.equ 080B86C5 = Enemy Invisible (Does not move)
.equ 080B8601 = Wild Sprite Change (Enemy cannot attack afterwards, but move)
.equ 080B82E1 = Enemy Continuously Reappears (Blinks)
.equ 080B8377 = Colonel's Z Slash (Colonels Arm does not go away)
.equ 080BACAB = Invisible (Don't Move. Any damage will kill him)
.equ 080BACBD = Cannon Meteor (Shoot meteor and cannon)
.equ 080BAD07 = Freeze Row Ahead, shoot cannon(ElementMan's)
.equ 080BAD77 = Shoot Lighting on random column (Pretty Cool. Breaks Panels)
.equ 080BB049 = Top Left Flame Candle Chip Search (Does not move)
.equ 080BB099 = Flame Candle Chip Search (Does not attack)
.equ 080BB0D3 = Flame Candle Chip Attack (Does not appear on the field)
.equ 080BC30F = First Time Use, Gravitate away from field, Then Nothing (WTF?)
.equ 080BC8A9 = Reappear as (Sand Worm? May be different on levels) (Game Freezes)
.equ 080BCC2D = DeathFiesta (CornFiesta)
.equ 080BCEB3 = Charge, Then DeltaRay Ding (Kinda cool... doesn't do anything)
.equ 080BD065 = ... Fade in from white (like scan lines), I think from TwinLeaders PA
.equ 080BCEB3 = Charge, Then ProtoMan's Delta Ray (Goes off screen afterwards... Damn)
.equ 080BD115 = Protoman's part in Twin Leaders, No Damage
.equ 080BD085 = Flashing White Reappear, Never ends
.equ 080BD157 = Protoman Slashing From TwinLeaders/Never Ends/No Damage
.equ 080BD4BD = White Flash, Quick Move (Anywhere on field), Continue AI.
.equ 080BD587 = Protoman ghost's in front you and does widesword, twice, screen flashes (Pretty Cool)
.equ 080BD743 = Don't move, but sprite displacment (...)
.equ 080BD6B7 = Stand Still and NeverEnd Protoman Flash WideSword (Kills Epileptics)
.equ 080BDB05 = Super Mega Charge (Overload)
.equ 080BD3C5 = Turn Into MegaMan!!!
.equ 080BDD41 = Protomans Delta Ray (If away from walls)
.equ 080BDD89 = Rapid MegaBuster Shots
.equ 080BDEC1 = Step Back, Slash, And Surrender (Good for a video of a surrender)
.equ 080BE145 = Hurt, Delta Ray And Dissapear
.equ 080BE175 = Django's part of Crossover, (Gun Del Sol)
.equ 080BDFA7 = Infinate Sword w/ Flash
.equ 080BE283 = Hurt Animation (Stays still)
.equ 080BE4F9 = Change Sprite (Bad Offset, AI loops the attack)
.equ 080BEBBD = Slight Move, Poof, Fast Move (It's in the MasterCross section)
.equ 080BEA51 = Slash And Heal
.equ 080BEE05 = KillerCross Beam and Heal (It goes away, unlike the one Megarock listed)
.equ 080BEF2D = WindRack And Heal (Rack does not go away)
.equ 080BEA79 = Turn White, Fade to Color (Never Ends)
.equ 080BEC41 = Poof
.equ 080BEE81 = Neverendning Drill Arm
.equ 080BEF49 = Neverending WindRack
.equ 080BF001 = Charge, When Charged, Begin to Recharge (If only it did something)
.equ 080BF325 = Hurt, Upsidedown Meteor Throw (6) 3 panels ahead
.equ 080BF44B = BlueMoon's Laser Ray (Uninstall/Lots of Damage/WhiteDot)
.equ 080BF341 = Neverending SunMoon Meteor Throw (Stupid Looking)
.equ 080BF3CD = Light/Lightoff (Brimming with power)(SunMoon Palette Change)
.equ 080BF465 = Neverending BlueMoon Laser (Loops)
.equ 080BF589 = SunMoon Ground Crash EarthQuake
.equ 080BF5E1 = SunMoon Ground Explosion
.equ 080BF801 = Change Palette (Dark), Fade in (Become Evil)
.equ 080BF889 = Gospel Breath from Darkness (Head Doesn't fade till second object does)
.equ 080BF9B1 = Sound of Bass approaching, charging, slashing, Battle Then Ends
.equ 080BFA1D = Bass Appears (But It's whatever enemy is there for bass has not loaded)
.equ 080BFAD9 = Charge Then DarkSword (Sword does not leave)
.equ 080BFC29 = EndFlag for Darkness PA (Fadeout/Battle End)
.equ 080BF8A9 = Summon Gospel Head
.equ 080BF8DB = Fire Gospel Breath
.equ 
.equ 
.equ 0801 Attack Set 12
.equ  
.equ 08016381 = Appear (pixelated)
.equ 080173F5 = Deleted (Megaman's deletion)
.equ 080170C5 = Deleted (bosses)
.equ 080174FF = Hurt
.equ 08017689 = Freeze
.equ 080171A7 = Cybeast Deleted







By Mgamerz and Timaeus
 
Offsets found by Mgamerz


B94D 0800 = Dim Screen and throw something
B9B1 0800 = Non time Stop Chip

Offsets found by Timaeus


0CAB 080E = Appear(with barrier sound)
1521 080E = They... latch on to you? Hm.
19DD 080E = Appear
1CF9, 1D89 080E = Nothing
1E4D, 2081, 225D 080E = Sprite turns invisible.
28A9 080E = BugFix?
2BC1 080E = MetaGel(OSSIM!)


Offsets found by Mgamerz


2E79 080E = Blinder
30E1 080E = WindBox
4161 080E = Anubis(freezes after a bit)
4679 080E = RockCube
5989 080E = Snake(epic)
5E45 080E = Trumpy
5F11 080E = AirRaid
6601 080E = Give up Panel Standing on
*/
#endif