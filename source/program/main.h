#pragma once

#include "../lib.hpp"
#include "../lib/armv8/register.hpp"
#include "../lib/nx/runtime/pad.h"

u8 g_Version = 1;
//0 -> 1.0, 1 -> 2.1

const exl::util::ModuleInfo g_MainInfo = exl::util::GetMainModuleInfo();
const uintptr_t g_BaseAddress = g_MainInfo.m_Total.m_Start;
const uintptr_t g_MainEnd = g_BaseAddress + g_MainInfo.m_Total.m_Size;
uintptr_t g_SpeedBooster = 0x0;
uintptr_t g_Player = 0x0;
uintptr_t g_PlayerPawn = 0x0;
uint64_t g_luaState = 0;
float mapCursorPos[3] = { 0.0 };
HidNpadFullKeyState g_NPad;

uint64_t* setFps = 0;

float slomoSpeed = 1;
bool doSlomo = true;

//0xdbccd8
typedef void(*setSlomo)(float param1, float param2, int64_t param3);

//0x10534a0
typedef u64(*EnableDebugMinimap)(int64_t lua_state);

//0x1054de0
typedef u64(*SetIAmACheater)(void);

//0x110075c
typedef uint64_t(*TestGiveItem)(int64_t param1, int64_t* param2);

//0x11007c8
typedef uint64_t(*TestGiveItem2)(int64_t param1, int64_t* param2);

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
typedef u64(*showFps)(void);

//0x1036250
typedef void(*IsGamePaused)(uint64_t param1);

//0x103efb0
//typedef u64(*setFps)(int64_t param1);

//0x1038c10
typedef u64(*giveAllItems)(void);

//0x103e1a0
typedef u64(*killPlayer)(void);

//0x1036210 or 0x1077e90 == +0x41C80 on v2.1
typedef u64(*pauseGame)(void);

//0xae6c10
typedef void(*giveItem)(int64_t param1, int64_t param2, int64_t param3);

//0x11008c8
typedef void(*giveItem2)(float param_1, float param_2, int64_t param_3, int64_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7);

//0x103e0e0
typedef u64(*DEBUG_MakePlayerInvincible)(int64_t);
//FUN_7100db2798
typedef int64_t (*unk_db2798)(int64_t param1);

//FUN_7100302b54
typedef uint64_t (*unk_302b54)(int64_t param1);

//FUN_7100a1d158
typedef void (*unk_a1d158)(float param1, int64_t param2);

//FUN_7100a1d258
typedef void (*unk_a1d258)(float param1, int64_t param2, int8_t param3, u32 param4);

//FUN_7100dc47a0
typedef void (*unk_dc47a0)(int64_t param1);


typedef void (*unkplVar3_170)(float param1, int64_t* param2);
unkplVar3_170 unkplVar3_170_func;

typedef void (*unkplVar3_168)(float param1, int64_t* param2, u32 param3);
unkplVar3_168 unkplVar3_168_func;

void initplVar3(int64_t* var){
    unkplVar3_170_func = (unkplVar3_170)(*(int64_t*)(*var + 0x170));
    unkplVar3_168_func = (unkplVar3_168)(*(int64_t*)(*var + 0x168));
}

namespace outFuncs{
    setSlomo setGameSpeed;
    SetIAmACheater setCheater;
    TestGiveItem testGivePlayerItem;
    TestGiveItem2 testGivePlayerItem2;
    HideScenario hideGameScenario;
    ShowScenario showGameScenario;
    DEBUG_MakePlayerInvincible makePlayerInvincible;
    killBoss killCurrentBoss;
    killEmmi killCurrentEmmi;
    killEnemies killAllEnemies;
    recoverLife recoverPlayerLife;
    recoverMissiles recoverPlayerMissiles;
    showFps showGameFps;
    //setFps setGameFps;
    IsGamePaused isGamePaused;
    giveAllItems givePlayerAllItems;
    giveItem givePlayerItem;
    giveItem2 givePlayerItem2;
    killPlayer killPlayerFunc;
    pauseGame togglePause;
    unk_db2798 unk_db2798_func;
    unk_302b54 unk_302b54_func;
    unk_a1d158 unk_a1d158_func;
    unk_a1d258 unk_a1d258_func;
    unk_dc47a0 unk_dc47a0_func;
}

void initExternFuncs(){//ermmm epic optimisation
    outFuncs::setGameSpeed = (setSlomo)(g_BaseAddress + 0xdbccd8 + (0x39FA0 * g_Version));
    outFuncs::setCheater = (SetIAmACheater)(g_BaseAddress + 0x1054de0 + (0x41C80 * g_Version));
    outFuncs::testGivePlayerItem = (TestGiveItem)(g_BaseAddress + 0x110075c + (0x41C80 * g_Version));
    outFuncs::testGivePlayerItem2 = (TestGiveItem2)(g_BaseAddress + 0x11007c8 + (0x41C80 * g_Version));
    outFuncs::hideGameScenario = (HideScenario)(g_BaseAddress + 0x1041010 + (0x41C70 * g_Version));
    outFuncs::showGameScenario = (ShowScenario)(g_BaseAddress + 0x1040fe0 + (0x41C70 * g_Version));
    outFuncs::makePlayerInvincible = (DEBUG_MakePlayerInvincible)(g_BaseAddress + 0x103e0e0 + (0x41C70 * g_Version));//0x41C70
    outFuncs::killCurrentBoss = (killBoss)(g_BaseAddress + 0x103e3f0 + (0x41C70 * g_Version));
    outFuncs::killCurrentEmmi = (killEmmi)(g_BaseAddress + 0x103e300 + (0x41C70 * g_Version));//0x41C70
    outFuncs::killAllEnemies = (killEnemies)(g_BaseAddress + 0x103e1f0 + (0x41C70 * g_Version));//0x41C70
    outFuncs::givePlayerAllItems = (giveAllItems)(g_BaseAddress + 0x1038c10 + (0x41C70 * g_Version));//0x41C70
    outFuncs::givePlayerItem = (giveItem)(g_BaseAddress + 0xae6c10 + (0x41C80 * g_Version));
    outFuncs::givePlayerItem2 = (giveItem2)(g_BaseAddress + 0x11008c8 + (0x41C70 * g_Version));
    outFuncs::killPlayerFunc = (killPlayer)(g_BaseAddress + 0x103e1a0 + (0x41C70 * g_Version));//0x41C70
    outFuncs::togglePause = (pauseGame)(g_BaseAddress + 0x1036210 + (0x41C80 * g_Version));
    outFuncs::unk_db2798_func = (unk_db2798)(g_BaseAddress + 0xdb2798 + (0x41C80 * g_Version));
    outFuncs::unk_302b54_func = (unk_302b54)(g_BaseAddress + 0x302b54 + (0x41C80 * g_Version));
    outFuncs::unk_a1d158_func = (unk_a1d158)(g_BaseAddress + 0xa1d158 + (0x41C80 * g_Version));
    outFuncs::unk_a1d258_func = (unk_a1d258)(g_BaseAddress + 0xa1d258 + (0x41C80 * g_Version));
    outFuncs::unk_dc47a0_func = (unk_dc47a0)(g_BaseAddress + 0xdc47a0 + (0x41C80 * g_Version));
    //outFuncs::setGameFps = (setFps)(g_BaseAddress + 0x103efb0 + (0x41DA0 * g_Version));//0x41DA0
    outFuncs::showGameFps = (showFps)(g_BaseAddress + 0x103dfe0 + (0x41C80 * g_Version));
    outFuncs::isGamePaused = (IsGamePaused)(g_BaseAddress + 0x1036250 + (0x41C80 * g_Version));
    outFuncs::recoverPlayerLife = (recoverLife)(g_BaseAddress + 0x103ec60 + (0x41DA0 * g_Version));//0x41DA0
    outFuncs::recoverPlayerMissiles = (recoverMissiles)(g_BaseAddress + 0x104d150 + (0x41DB0 * g_Version));//0x41DB0
}

uintptr_t sigScanMain(uint32_t scanOps[], int scanSize);

#define frameRate(delta) (*setFps = (uint64_t)(1000.0 / delta))

bool checkInputs();

void ManipulateInput(HidNpadCommonState* state);

void handleInput(HidNpadFullKeyState *state);

void TeleportPlayer(uintptr_t player, float location[2]);

struct{//from UpdatePlayerPawn's Player
    //Samus
    uintptr_t posX = 0x44;//float
    uintptr_t posY = 0x54;//float
    uintptr_t skew = 0x58;//float -1 -> 1, 0 is facing camera
    uintptr_t velX = 0x2FA8;//float
    uintptr_t velY = 0x2FAC;//float
    uintptr_t fullInvuln = 0x3589;//bool, set by the EMMI door glitch
    uintptr_t health = 0x14FA4;//float
    uintptr_t fKnockbackFrames = 0x14FB0;//float; doesnt work on console
    uintptr_t fIFrames = 0x14FB8;//float; doesnt work on console
    
    //Morph
    uintptr_t morphX = 0x789254;//float doesnt work
    uintptr_t morphY = 0x789264;//float doesnt work
    uintptr_t morphXVel = 0x7897C8;//float
    uintptr_t morphYVel = 0x7897CC;//float
    uintptr_t morphGravity = 0x7896F4;//bool
    uintptr_t morphRes = 0x78B9C6;//bool; doesnt work on console

    //Misc
    uintptr_t unkState = 0xB0;//u8
    uintptr_t unkState2 = 0x3D0;//u16
    uintptr_t unkMorphState = 0x7892C0;
    uintptr_t notUpdate3dArea = -0x4365090;//Pauses updating 3d area, like if you were in a menu

} playerOffs;

//Input Combo vars and methods
#define g_ButtonState(button) ((g_NPad.buttons & HidNpadButton::button) == HidNpadButton::button)
#define g_ButtonXState(button) ((g_NPad.buttons ^ HidNpadButton::button) == 0)

float telePos[4] = { 0.0 };
float noclipPos[4] = { 0.0 };
float noclipDif[2] = { 0.0 };
bool isNoclip = false;

//Individual Room vars
float roomIL[3] = {0.0};
float finishIL[3] = {0.0};
float finishDelta = 700;
float newPosX = 0;
float newPosY = 0;
float newPosZ = 0;
bool ILonce = false;//Set a new entrance
bool ILnext = false;//Set next entrance as finish line
bool ILallowTp = false;//Ignores any teleport that isnt a door tm
bool ILreset = false;//Whether to teleport
bool ILGauntlet = false;//Whether only the finish line teleports
bool ILForce = false;//Force all teleport types

int avoidRepeat = 30;//testing var to find the optimal time to ignore combos without feeling unresponsive, seems this function runs once per frame so its framecount
int repeatInput = 0;//ignore input for X cycles
int waitTime = 300 * 1000000;//milliseconds to wait for frame advance to avoid polluting inputs, svcSleep counts in nanoseconds so X*1,000,000
bool waitOne = false;//testing for a frame advance
bool ourFreeze = false;//are we the one pausing or is the game paused
bool ignoreCombo = false;//ignore combo input on the games side
u64 comboButtons = 0;//buttons to make the game ignore
bool turboButtons = false;//flip button state every frame
bool turboSwitcher = false;//used to rapidly switch button states
bool getCombo = false;//do we get a turbo combo
u64 turboCombo = 0;//buttons to turbo
u64 storeForFA = 0;//buttons from the frame before frame advancing
u64 storeForWaitOne = 0;//buttons we are currently holding for this frame

//Skew stuff
float desiredSkew = 0.0;

//Instant Speed vars 
int ignoreCycles = 0;
bool setInstantSpeed = true;

//Cool Spark vars
bool forceCSpark = false;

//Ignore Sub Area Deaths vars
bool ignoreOobDeath = true;

void TeleportPlayer(uintptr_t player, float location[4]);

/* Declare function to dynamic link with. */
namespace nn::oe {
    void SetCopyrightVisibility(bool);
};

//massive fucking list of item offsets I think......
int64_t itemOffs[37] = {
    0x988, 0x998, 0x990, 0xbc0, 0xbc8, 0xa38, 0xa40, 0xa50, 0xa48, 0x2d8,
    0xef0, 0x1b0, 0x630, 0x930, 0xa48, 0xbb8, 0xba0, 0x9c8, 0xbb0, 0x9d0,
    0xba8, 0xb98, 0xa30, 0xd88, 0xbf0, 0x9e0, 0xe78, 0x780, 0x430, 0x330,
    0x270, 0xc28, 0xa78, 0xbd0, 0xbd8, 0xbe0, 0xbe8 };

float itemVals[10] = {
    799.0, 799.0, 0.0, 1000.0, 1000.0, 150.0, 150.0, 10.0,
    10.0, 1.0 };