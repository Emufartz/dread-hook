#pragma once

#include "../lib.hpp"
#include "../lib/armv8/register.hpp"
#include "../lib/nx/runtime/pad.h"

const uintptr_t g_BaseAddress = exl::util::modules::GetTargetStart();
uintptr_t g_SpeedBooster = 0x0;
uintptr_t g_Player = 0x0;
uintptr_t g_PlayerPawn = 0x0;
uint64_t g_luaState = 0;
float mapCursorPos[3] = { 0.0 };
u64 padButtons = 0;
u64 padButtonsOld = 0;
HidNpadFullKeyState g_NPad;

float slomoValue = 0.5;
bool doSlomo = true;

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

//0x103e300
typedef u64(*killEmmi)(void);

//0x103e1f0
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
typedef u64(*setFps)(int64_t param1);

//0x1038c10
typedef u64(*giveAllItems)(void);

//0x103e1a0
typedef u64(*killPlayer)(void);

//0x1036210
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
    SetIAmACheater setCheater;
    TestGiveItem testGivePlayerItem;
    TestGiveItem2 testGivePlayerItem2;
    HideScenario hideGameScenario;
    ShowScenario showGameScenario;
    DEBUG_MakePlayerInvincible makePlayerInvincible;
    killEmmi killCurrentEmmi;
    killEnemies killAllEnemies;
    recoverLife recoverPlayerLife;
    recoverMissiles recoverPlayerMissiles;
    showFps showGameFps;
    setFps setGameFps;
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

void initExternFuncs(){
    outFuncs::setCheater = (SetIAmACheater)(exl::util::modules::GetTargetOffset(0x1054de0));
    outFuncs::testGivePlayerItem = (TestGiveItem)(exl::util::modules::GetTargetOffset(0x110075c));
    outFuncs::testGivePlayerItem2 = (TestGiveItem2)(exl::util::modules::GetTargetOffset(0x11007c8));
    outFuncs::hideGameScenario = (HideScenario)(exl::util::modules::GetTargetOffset(0x1041010));
    outFuncs::showGameScenario = (ShowScenario)(exl::util::modules::GetTargetOffset(0x1040fe0));
    outFuncs::makePlayerInvincible = (DEBUG_MakePlayerInvincible)(exl::util::modules::GetTargetOffset(0x103e0e0));
    outFuncs::killCurrentEmmi = (killEmmi)(exl::util::modules::GetTargetOffset(0x103e300));
    outFuncs::killAllEnemies = (killEnemies)(exl::util::modules::GetTargetOffset(0x103e1f0));
    outFuncs::givePlayerAllItems = (giveAllItems)(exl::util::modules::GetTargetOffset(0x1038c10));
    outFuncs::givePlayerItem = (giveItem)(exl::util::modules::GetTargetOffset(0xae6c10));
    outFuncs::givePlayerItem2 = (giveItem2)(exl::util::modules::GetTargetOffset(0x11008c8));
    outFuncs::killPlayerFunc = (killPlayer)(exl::util::modules::GetTargetOffset(0x103e1a0));
    outFuncs::togglePause = (pauseGame)(exl::util::modules::GetTargetOffset(0x1036210));
    outFuncs::unk_db2798_func = (unk_db2798)(exl::util::modules::GetTargetOffset(0xdb2798));
    outFuncs::unk_302b54_func = (unk_302b54)(exl::util::modules::GetTargetOffset(0x302b54));
    outFuncs::unk_a1d158_func = (unk_a1d158)(exl::util::modules::GetTargetOffset(0xa1d158));
    outFuncs::unk_a1d258_func = (unk_a1d258)(exl::util::modules::GetTargetOffset(0xa1d258));
    outFuncs::unk_dc47a0_func = (unk_dc47a0)(exl::util::modules::GetTargetOffset(0xdc47a0));
    outFuncs::setGameFps = (setFps)(exl::util::modules::GetTargetOffset(0x103efb0));
    outFuncs::showGameFps = (showFps)(exl::util::modules::GetTargetOffset(0x103dfe0));
    outFuncs::isGamePaused = (IsGamePaused)(exl::util::modules::GetTargetOffset(0x1036250));
    outFuncs::recoverPlayerLife = (recoverLife)(exl::util::modules::GetTargetOffset(0x103ec60));
    outFuncs::recoverPlayerMissiles = (recoverMissiles)(exl::util::modules::GetTargetOffset(0x104d150));
}

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
    uintptr_t morphX = 0x789254;//float
    uintptr_t morphY = 0x789264;//float
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

bool ILonce = false;//Set a new entrance
bool ILallowTp = false;//Ignores any teleport that isnt a door tm
bool ILreset = false;//Whether to teleport
bool ILForce = false;//Force all teleport types

int avoidRepeat = 30;//testing var to find the optimal time to ignore combos without feeling unresponsive, seems this function runs once per frame so its framecount
int repeatInput = 0;//ignore input for X cycles
int waitTime = 300 * 1000000;//milliseconds to wait for frame advance to avoid polluting inputs, svcSleep counts in nanoseconds so X*1,000,000
bool waitOne = false;//testing for a frame advance
bool ourFreeze = false;
bool ignoreCombo = false;//ignore combo input on the games side
u64 comboButtons = 0;
bool turboButtons = false;//flip button state every frame
bool turboSwitcher = false;//used to rapidly switch button states
bool getCombo = false;
u64 turboCombo = 0;
u64 storeForFA = 0;

//Skew stuff
float desiredSkew = 0.0;

//Instant Speed vars 
int ignoreCycles = 0;
bool setInstantSpeed = true;

//Cool Spark vars
bool forceCSpark = false;

//Ignore Sub Area Deaths vars
bool ignoreOobDeath = true;

//Individual Room vars
float roomIL[3] = {0.0};

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