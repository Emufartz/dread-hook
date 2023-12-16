#pragma once

class CEntity;
class CHealthComponent;

//0xdbccd8
typedef void(*setSlomo)(float param1, float param2, int64_t param3);

//0x10534a0
typedef u64(*EnableDebugMinimap)(uint64_t* LuaState, bool param2);//bool

//0x1054de0
typedef u64(*SetIAmACheater)(void);

//0x1040fe0
typedef void(*ShowScenario)(void);

//0x1041010
typedef void(*HideScenario)(void);

//0x103e3f0
typedef u64 (*killBoss)(void);

//0x103e300 or 0x107ff70 == +0x41C70 on 2.1
typedef u64(*killEmmi)(void);

//0x103e1f0 or 0x107fe60 == +0x41C70 on 2.1
typedef u64(*killEnemies)(void);

//0x103ec60
typedef u64(*recoverLife)(void);

//0x104d150
typedef void(*recoverMissiles)(void);

//0x103dfe0
typedef u64(*showFps)(int param1);

//0x1036250
typedef void(*IsGamePaused)(uint64_t param1);

//0x1038c10
typedef u64(*giveAllItems)(void);

//0x103e1a0
typedef u64(*killPlayer)(void);

//0x1036210 or 0x1077e90 == +0x41C80 on v2.1
typedef u64(*pauseGame)(void);

//0xae6c10
typedef void(*giveItem)(int64_t param1, int64_t param2, int64_t param3);

//0x11008c8
typedef void(*giveItem2)(float param_1, float param_2, uint64_t* param_3, int64_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7);

//0x103e0e0 only works for 1 hit?
typedef u64(*DEBUG_MakePlayerInvincible)(uint64_t* LuaState, bool param2);

//FUN_7100db2798
typedef CEntity* (*getPlayerFromGM)(int64_t param1);

//FUN_7100302b54
typedef uint64_t (*unk_302b54)(CEntity* param1);

//FUN_7100a1d158
typedef void (*unk_a1d158)(float param1, int64_t param2);

//FUN_7100a1d258
typedef void (*unk_a1d258)(float param1, int64_t param2, int8_t param3, int8_t param4);

//FUN_7100dc47a0
typedef void (*unk_dc47a0)(int64_t param1);

//0x1036e10
typedef int (*saveGameToSnapshot)(uint64_t* LuaState, char* snapshotID);

//0x1036ea0
typedef int (*saveSnapshotToCheckpoint)(uint64_t* LuaState, char* snapshotID, char* sCheckpointKey, const char* sStartPointID, bool bForce);

//0x7e484
typedef void (*TRntString256)(uint64_t* thiz, char* string);

//0x7e484
typedef void (*TRntString256D)(uint64_t* thiz);

//0xdb0de8
typedef void (*changeGameMode)(uint64_t* GameManager, uint64_t* GameMode);

typedef void (*unkplVar3_170)(float param1, CHealthComponent* param2);
unkplVar3_170 unkHealthCompFunc1;

typedef void (*unkplVar3_168)(float param1, CHealthComponent* param2, u32 param3);
unkplVar3_168 unkHealthCompFunc;

//0xd98b18
typedef void (*drawDebugDamage)(float damage, long param2, float worldPos[3], float rgb[3]);

//0xd967c0
typedef void (*drawEnemyLifeBars)(float param1, long param2);

//0x20b754
typedef void (*unkEnemyLifeFunc)(long param1, float* param2);

//0x1c3fe8
typedef void (*copyWideStringAndParse)(int64_t param1, wchar_t* param2);

//0x219208
typedef void (*unkEnemyLifeW2S)(int64_t dataPtr, float* worldPos, float* param3, float* param4, uint param5, uint param6, uint param7);

//0x19d768
typedef void (*unkSetTextRGBA)(int64_t entity, float* param2);

//0x19d7d4
typedef void (*unkSetTextStyle)(float param1, float param2, float param3, float param4, int64_t param5);

//0x66df0
typedef void (*copyWideStringOfSize)(int64_t param1, wchar_t* wString, size_t size);

typedef bool (*ExternFUN_7100219548)(long param_1,uint *param_2,int param_3);
typedef void (*unkDebugTextDtor)(long *param_1,uint64_t *param_2);
typedef long* (*ExternFUN_7100075454)(long param_1,ulong param_2,long param_3,float param_4);
typedef uint64_t* (*ExternFUN_7100d9977c)(long **param_1,long param_2,long **param_3);
typedef uint64_t (*ExternFUN_7100219650)(long param_1,long *param_2,uint param_3);
typedef uint32_t* (*ExternFUN_71011738ec)(long param_1,long **param_2);
typedef void (*ExternFUN_7100080124)(long *thiz,long *instance);
typedef void (*ExternFUN_71001c3a90)(long param_1,long param_2);
typedef void (*ExternFUN_710020bdb8)(long param_1,int param_2);
typedef void (*ExternFUN_710019d854)(long param_1);
typedef void (*ExternHashString)(long **result,const char *text,bool storeInPool);
typedef int (*Externswprintf)(wchar_t *__s,size_t __n,const wchar_t *__format,...);

namespace outFuncs{
    EnableDebugMinimap setDebugMiniMap;
    setSlomo setGameSpeed;
    SetIAmACheater setCheater;
    HideScenario hideGameScenario;
    ShowScenario showGameScenario;
    DEBUG_MakePlayerInvincible makePlayerInvincible;
    killBoss killCurrentBoss;
    killEmmi killCurrentEmmi;
    killEnemies killAllEnemies;
    recoverLife recoverPlayerLife;
    recoverMissiles recoverPlayerMissiles;
    showFps showGameFps;
    IsGamePaused isGamePaused;
    giveAllItems givePlayerAllItems;
    giveItem givePlayerItem;
    giveItem2 givePlayerItem2;
    killPlayer killPlayerFunc;
    pauseGame togglePause;
    getPlayerFromGM GetPlayerFromGM;
    unk_302b54 unk_302b54_func;
    unk_a1d158 unk_a1d158_func;
    unk_a1d258 unk_a1d258_func;
    unk_dc47a0 unk_dc47a0_func;
    saveGameToSnapshot SaveGameToSnapshotFunc;
    saveSnapshotToCheckpoint SaveSnapshotToCheckpointFunc;
    TRntString256 TRntString256Ctor;
    TRntString256D TRntString256Dtor;
    changeGameMode ChangeGameMode;
    drawDebugDamage DrawDebugDamageToScreen;
    drawEnemyLifeBars DrawEnemyLifeBarsToScreen;
    unkEnemyLifeFunc UnkEnemyLifeFunc;
    copyWideStringAndParse CopyWideStringAndParse;
    unkEnemyLifeW2S UnkEnemyLifeW2S;
    unkSetTextRGBA UnkSetTextRGBA;
    unkSetTextStyle UnkSetTextStyle;
    copyWideStringOfSize CopyWideStringOfSize;

    ExternFUN_7100219548 FUN_7100219548;
    unkDebugTextDtor UnkDebugTextDtor;
    ExternFUN_7100075454 FUN_7100075454;
    ExternFUN_7100d9977c FUN_7100d9977c;
    ExternFUN_7100219650 FUN_7100219650;
    ExternFUN_71011738ec FUN_71011738ec;
    ExternFUN_7100080124 FUN_7100080124;
    ExternFUN_71001c3a90 FUN_71001c3a90;
    ExternFUN_710020bdb8 FUN_710020bdb8;
    ExternFUN_710019d854 FUN_710019d854;
    ExternHashString HashString;
    Externswprintf swprintf;
}

void initExternFuncs(uintptr_t g_BaseAddress, u8 g_Version){//ermmm epic optimisation
    //outFuncs::setDebugMiniMap = (EnableDebugMinimap)(g_BaseAddress + 0x10534a0 + (0x41DB0 * g_Version));
    outFuncs::setGameSpeed = (setSlomo)(g_BaseAddress + 0xdbccd8 + (0x39FA0 * g_Version));
    //outFuncs::setCheater = (SetIAmACheater)(g_BaseAddress + 0x1054de0 + (0x41C80 * g_Version));
    outFuncs::hideGameScenario = (HideScenario)(g_BaseAddress + 0x1041010 + (0x41C70 * g_Version));
    outFuncs::showGameScenario = (ShowScenario)(g_BaseAddress + 0x1040fe0 + (0x41C70 * g_Version));
    //outFuncs::makePlayerInvincible = (DEBUG_MakePlayerInvincible)(g_BaseAddress + 0x103e0e0 + (0x41C70 * g_Version));//0x41C70
    //outFuncs::killCurrentBoss = (killBoss)(g_BaseAddress + 0x103e3f0 + (0x41C70 * g_Version));
    //outFuncs::killCurrentEmmi = (killEmmi)(g_BaseAddress + 0x103e300 + (0x41C70 * g_Version));//0x41C70
    //outFuncs::killAllEnemies = (killEnemies)(g_BaseAddress + 0x103e1f0 + (0x41C70 * g_Version));//0x41C70
    outFuncs::givePlayerAllItems = (giveAllItems)(g_BaseAddress + 0x1038c10 + (0x41C70 * g_Version));//0x41C70
    outFuncs::givePlayerItem = (giveItem)(g_BaseAddress + 0xae6c10 + (0x2E00 * g_Version));
    outFuncs::givePlayerItem2 = (giveItem2)(g_BaseAddress + 0x11008c8 + (0x42160 * g_Version));
    outFuncs::killPlayerFunc = (killPlayer)(g_BaseAddress + 0x103e1a0 + (0x41C70 * g_Version));//0x41C70
    outFuncs::togglePause = (pauseGame)(g_BaseAddress + 0x1036210 + (0x41C80 * g_Version));
    outFuncs::GetPlayerFromGM = (getPlayerFromGM)(g_BaseAddress + 0xdb2798 + (0x39FF0 * g_Version));
    outFuncs::unk_302b54_func = (unk_302b54)(g_BaseAddress + 0x302b54 + (0x500 * g_Version));
    outFuncs::unk_a1d158_func = (unk_a1d158)(g_BaseAddress + 0xa1d158 + (0x2840 * g_Version));
    outFuncs::unk_a1d258_func = (unk_a1d258)(g_BaseAddress + 0xa1d258 + (0x2840 * g_Version));
    outFuncs::unk_dc47a0_func = (unk_dc47a0)(g_BaseAddress + 0xdc47a0 + (0x3B5A8 * g_Version));
    //outFuncs::setGameFps = (setFps)(g_BaseAddress + 0x103efb0 + (0x41DA0 * g_Version));//0x41DA0
    outFuncs::showGameFps = (showFps)(g_BaseAddress + 0x103dfe0 + (0x41C80 * g_Version));
    outFuncs::isGamePaused = (IsGamePaused)(g_BaseAddress + 0x1036250 + (0x41C80 * g_Version));
    outFuncs::recoverPlayerLife = (recoverLife)(g_BaseAddress + 0x103ec60 + (0x41DA0 * g_Version));//0x41DA0
    outFuncs::recoverPlayerMissiles = (recoverMissiles)(g_BaseAddress + 0x104d150 + (0x41DB0 * g_Version));//0x41DB0
    //outFuncs::SaveGameToSnapshotFunc = (saveGameToSnapshot)(g_BaseAddress + 0x1036e10 + (0xDEAD * g_Version));
    //outFuncs::SaveSnapshotToCheckpointFunc = (saveSnapshotToCheckpoint)(g_BaseAddress + 0x1036ea0 + (0xDEAD * g_Version));
    outFuncs::TRntString256Ctor = (TRntString256)(g_BaseAddress + 0x7e484 + (0xDEAD * g_Version));
    outFuncs::TRntString256Dtor = (TRntString256D)(g_BaseAddress + 0x7e444 + (0xDEAD * g_Version));
    //outFuncs::ChangeGameMode = (changeGameMode)(g_BaseAddress + 0xdb0de8 + (0xDEAD * g_Version));
    outFuncs::DrawDebugDamageToScreen = (drawDebugDamage)(g_BaseAddress + 0xd98b18 + (0xDEAD * g_Version));//1.0
    outFuncs::DrawEnemyLifeBarsToScreen = (drawEnemyLifeBars)(g_BaseAddress + 0xd967c0 + (0xDEAD * g_Version));//1.0
    outFuncs::UnkEnemyLifeFunc = (unkEnemyLifeFunc)(g_BaseAddress + 0x20b754 + (0xDEAD * g_Version));//1.0
    outFuncs::CopyWideStringAndParse = (copyWideStringAndParse)(g_BaseAddress + 0x1c3fe8 + (0xDEAD * g_Version));//1.0
    outFuncs::UnkEnemyLifeW2S = (unkEnemyLifeW2S)(g_BaseAddress + 0x219208 + (0xDEAD * g_Version));//1.0
    outFuncs::UnkSetTextRGBA = (unkSetTextRGBA)(g_BaseAddress + 0x19d768 + (0xDEAD * g_Version));//1.0
    outFuncs::UnkSetTextStyle = (unkSetTextStyle)(g_BaseAddress + 0x19d7d4 + (0xDEAD * g_Version));//1.0
    outFuncs::CopyWideStringOfSize = (copyWideStringOfSize)(g_BaseAddress + 0x66df0 + (0xDEAD * g_Version));//1.0
    
    outFuncs::FUN_7100219548 = (ExternFUN_7100219548)(g_BaseAddress + 0x219548 + (0xDEAD * g_Version));
    outFuncs::UnkDebugTextDtor = (unkDebugTextDtor)(g_BaseAddress + 0x754a4 + (0xDEAD * g_Version));
    outFuncs::FUN_7100075454 = (ExternFUN_7100075454)(g_BaseAddress + 0x75454 + (0xDEAD * g_Version));
    outFuncs::FUN_7100d9977c = (ExternFUN_7100d9977c)(g_BaseAddress + 0xd9977c + (0xDEAD * g_Version));
    outFuncs::FUN_7100219650 = (ExternFUN_7100219650)(g_BaseAddress + 0x219650 + (0xDEAD * g_Version));
    outFuncs::FUN_71011738ec = (ExternFUN_71011738ec)(g_BaseAddress + 0x11738ec + (0xDEAD * g_Version));
    outFuncs::FUN_7100080124 = (ExternFUN_7100080124)(g_BaseAddress + 0x80124 + (0xDEAD * g_Version));
    outFuncs::FUN_71001c3a90 = (ExternFUN_71001c3a90)(g_BaseAddress + 0x1c3a90 + (0xDEAD * g_Version));
    outFuncs::FUN_710020bdb8 = (ExternFUN_710020bdb8)(g_BaseAddress + 0x20bdb8 + (0xDEAD * g_Version));
    outFuncs::FUN_710019d854 = (ExternFUN_710019d854)(g_BaseAddress + 0x19d854 + (0xDEAD * g_Version));
    outFuncs::HashString = (ExternHashString)(g_BaseAddress + 0x3d4 + (0xDEAD * g_Version));
    outFuncs::swprintf = (Externswprintf)(g_BaseAddress + 0x11f4230 + (0xDEAD * g_Version));

}

//massive fucking list of item offsets I think......
int64_t itemOffs[37] = {//TODO get offsets for pbs and hyper beam
    0x1caf988, 0x1caf998, 0x1caf990, 0x1c9ebc0, 0x1c9ebc8, 0x1c88a38, 0x1c88a40, 0x1c88a50, 
    0x1c88a48, 0x1c9f2d8, 0x1c78ef0, 0x1ca11b0, 0x1c9e630, 0x1c9e930, 0x1c9ea48, 0x1c9ebb8, 
    0x1c9eba0, 0x1caf9c8, 0x1c9ebb0, 0x1caf9d0, 0x1c9eba8, 0x1c9eb98, 0x1c88a30, 0x1c9ed88, 
    0x1c78bf0, 0x1caf9e0, 0x1ca5e78, 0x1c62780, 0x1c9f430, 0x1c87330, 0x1ca5270, 0x1ca5c28, 
    0x1ca7a78, 0x1c78bd0, 0x1c78bd8, 0x1c78be0, 0x1c78be8 };

int64_t itemOffsV21[37] = {
    0x1d073e0, 0x1d073f0, 0x1d073e8, 0x1cf65f0, 0x1cf65f8, 0x1ce0428, 0x1ce0430, 0x1ce0440, 
    0x1ce0438, 0x1cf6d08, 0x1cd08c8, 0x1cf8be0, 0x1cf6060, 0x1cf6360, 0x1cf6478, 0x1cf65e8, 
    0x1cf65d0, 0x1d07430, 0x1cf65e0, 0x1d07428, 0x1cf65d8, 0x1cf65c8, 0x1ce0420, 0x1cf67b8, 
    0x1cd05c8, 0x1cda8a8, 0x1cfd8a0, 0x1cba150, 0x1cf6e60, 0x1cded20, 0x1cfcca0, 0x1cfd650, 
    0x1cff498, 0x1cd05a8, 0x1cd05b0, 0x1cd05b8, 0x1cd05c0 };
//DAT_717275a740
//ITEM_HYPER_BEAM 0x1d07430
//ITEM_WEAPON_POWER_BOMB 0x1cda8a8
//Omega Stream 0x1cd0778
//Omega Cannon 0x1cda758
//replacing index(1) 18 Nothing 0x1d07420 with Hyper Beam
//replacing index(1) 26 Nothing 0x1d07438 with Power Bombs
//QUARANTINE_RELEASED 0x1cd6130 doesnt work like an item
//unknown item at 0x1d073c8 doesnt do anything
//unknown item at 0x1cd0780 doesnt do anything
//unknown item at 0x1cfef78 could be missile+ tanks 

float itemVals[37] = {
    1299.0, 1299.0, 0.0, 1000.0, 1000.0, 250.0, 250.0, 15.0,
      15.0,    0.0, 1.0,    1.0,    1.0,   1.0,   1.0,  1.0,
       1.0,    0.0, 1.0,    1.0,    1.0,   1.0,   1.0,  1.0,
       1.0,    1.0, 1.0,    1.0,    1.0,   1.0,   1.0,  1.0, 
       1.0,    1.0, 1.0,    1.0,    1.0 };

const char* itemNames[37] = {
    "Health Max"     , "Health"       , "Life Shards"  , "Aeion"      , "Aeion Max"   , "Missiles"      , "Missiles Max"  , "Power Bombs" ,
    "Power Bombs Max", "Metroid Suit" , "Gravity Suit" , "Varia Suit" , "Bombs"       , "Charge Beam"   , "Diffusion Beam", "Grapple Beam",
    "Wide Beam"      , "Hyper Beam"   , "Wave Beam"    , "Nothing"    , "Plasma Beam" , "Super Missiles", "Ice Missiles"  , "Cross Bombs" ,
    "Storm Missiles" , "Power Bombs"  , "Spin Boost"   , "Morph Ball" , "Screw Attack", "Space Jump"    , "Some Function" , "Spider Grip" , 
    "Slide"          , "Phantom Cloak", "Speed Booster", "Flash Shift", "Pulse Radar" };

const char* internalItemNames[37] = {
    "ITEM_MAX_LIFE"             , "ITEM_CURRENT_LIFE"    , "ITEM_LIFE_SHARDS"     , "ITEM_MAX_SPECIAL_ENERGY", "ITEM_CURRENT_SPECIAL_ENERGY", "ITEM_WEAPON_MISSILE_CURRENT", "ITEM_WEAPON_MISSILE_MAX"   , "ITEM_WEAPON_POWER_BOMB_CURRENT",
    "ITEM_WEAPON_POWER_BOMB_MAX", "ITEM_HYPER_SUIT"      , "ITEM_GRAVITY_SUIT"    , "ITEM_VARIA_SUIT"        , "ITEM_WEAPON_BOMB"           , "ITEM_WEAPON_CHARGE_BEAM"    , "ITEM_WEAPON_DIFFUSION_BEAM", "ITEM_WEAPON_GRAPPLE_BEAM"      ,
    "ITEM_WEAPON_WIDE_BEAM"     , "ITEM_HYPER_BEAM"      , "ITEM_WEAPON_WAVE_BEAM", "Nothing"                , "ITEM_WEAPON_PLASMA_BEAM"    , "ITEM_WEAPON_SUPER_MISSILE"  , "ITEM_WEAPON_ICE_MISSILE"   , "ITEM_WEAPON_LINE_BOMB"         ,
    "ITEM_MULTILOCKON"          , "Nothing"              , "ITEM_DOUBLE_JUMP"     , "ITEM_MORPH_BALL"        , "ITEM_SCREW_ATTACK"          , "ITEM_SPACE_JUMP"            , "Some Function"             , "ITEM_MAGNET_GLOVE"             , 
    "Nothing(Slide)"            , "ITEM_OPTIC_CAMOUFLAGE", "ITEM_SPEED_BOOSTER"   , "ITEM_GHOST_AURA"        , "ITEM_SONAR" };

//debug menu notes
//class guicallbacks:
//members:
//"OnLoadScenarioRequests"
//class msemenu:
//members:
//"GainAllItemsAndPowerups"
//class msemenu_start:
//members:
//"OnSaveDataInitialized"
//class msemenu_ingame:
//members:
//"AppendMenuInfo"