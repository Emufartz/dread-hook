#pragma once

#include "../lib.hpp"
#include "../lib/armv8/register.hpp"
#include "../lib/nx/runtime/pad.h"
#include "externalFunctions.h"

const u8 g_Version = 0;
//0 -> 1.0, 1 -> 2.1

const exl::util::ModuleInfo g_MainInfo = exl::util::GetMainModuleInfo();
const uintptr_t g_BaseAddress = g_MainInfo.m_Total.m_Start;
const uintptr_t g_MainEnd = g_BaseAddress + g_MainInfo.m_Total.m_Size;
uintptr_t g_SpeedBooster = 0x0;
uint64_t* g_StaticPlayerItems = 0;
uint64_t* g_luaState = nullptr;
float mapCursorPos[3] = { 0.0 };
HidNpadFullKeyState g_NPad;
bool showMenu = false;
bool justOpened = false;

uint64_t* g_GameManager = *(uint64_t**)(g_BaseAddress + 0x1c626b8 + (0x579D0 * g_Version));//2.1 +0x579D0
uint64_t nvnProcVT = *(uint64_t *)(g_BaseAddress + 0x6e241c10);//vtable of nvn functions, 522 pointers long
uint64_t DAT_7101cee300 = *(uint64_t *)(g_BaseAddress + 0x1c62700);
uint64_t DAT_71726c5788 = *(uint64_t *)(g_BaseAddress + 0x1c9c1d0);
uint64_t DAT_7101cee108 = *(uint64_t *)(g_BaseAddress + 0x1cee108);

struct menuEntry {
    int64_t ptr = 0;
    float offs[2];
    float life = 0;
};

uint64_t* setFps = 0;

float slomoSpeed = 1;
bool doSlomo = true;

class CCollisionComponent{
    public:
    char unkPadding[0x7b9];
    char fullInvuln;//0x7b9
};

class CHealthComponent{
    public:
    long vTable;
    char unkPadding[0x48];
    float maxHealth;//0x50
    float curHealth;
    char unkPadding1[0x8];
    float fKnockbackFrames;//0x60
    char unkPadding2[0x4];
    float fIFrames;//0x68
    char unkPadding3[0xFC];
    long* someFunc;//0x168
    long* someFunc1;

};

void initplrHealthComp(CHealthComponent* healthComp){
    unkHealthCompFunc = (unkplVar3_168)*(long*)(healthComp->vTable + 0x168);
    unkHealthCompFunc1 = (unkplVar3_170)*(long*)(healthComp->vTable + 0x170);
}

class CEntity{
    public:
    long* vTable;
    long* parentPtr;//pointer to **g_GameManager + 0x2aa0
    char unkPadding[0x34];
    float posX;//0x44
    char unkPadding1[0xC];
    float posY;//0x54
    float skew;
    char unkPadding2[0x8];
    float posZ;//0x64
    char unkPadding3[0x150];
    CHealthComponent* healthComp;//0x1B8
    char unkPadding4[0x40];
    CCollisionComponent* collisionComp;//? 0x200
    char unkPadding5[0x68];
    long* playerAbilities;//0x270
    char unkPadding6[0x158];
    short unkState2;
    char unkPadding7[0x2BD2];
    float velX;
    float velY;
};
CEntity* g_Player;
CEntity* g_Morph;
CEntity* g_StaticPlayer;

class unkClassPCE{
    char unkPadding[0x10];
    CEntity* entity;
};

class CGameManager{
    char unkPadding[0x2a80];
    unkClassPCE* samusPCE;//0x2a80
    unkClassPCE* morphPCE;//0x2a88
    char unkPadding1[0x10];
    unkClassPCE* activePCE;//0x2aa0
};

#define frameRate(delta) (*setFps = (uint64_t)(1000.0 / delta))

bool checkInputs();

void ManipulateInput(HidNpadCommonState* state);

void handleInput(HidNpadFullKeyState *state);

void TeleportPlayer(CEntity* player, CEntity* morph, float location[4]);

void updateMenu();

struct {
    //Samus
    uintptr_t posX = 0x44;//float
    uintptr_t posY = 0x54;//float
    uintptr_t skew = 0x58;//float -1 -> 1, 0 is facing camera
    uintptr_t velX = 0x2FA8;//float
    uintptr_t velY = 0x2FAC;//float
    
    //Morph
    uintptr_t morphXVel = 0x5B8 + (0x250 * g_Version);//float doesnt work on console
    uintptr_t morphYVel = 0x5BC + (0x250 * g_Version);//float
    uintptr_t morphGravity = 0x4E4 + (0x250 * g_Version);//bool offset 0x250 v2.1

    //this from morph. Or *(*(morph+0x1F0)+0x3E0)
    uintptr_t morphRes = 0x27B6 + (0x250 * g_Version);//bool; from morph
} playerOffs;

struct {
    uintptr_t SpeedThreshold = 0x7265724c + (0x59DA0 * g_Version);

} tunableOffs;

//Input Combo vars and macros
#define g_ButtonState(button) ((g_NPad.buttons & HidNpadButton::button) == HidNpadButton::button)
#define g_KeyState(key) ((g_NPad.buttons & key) == key)
#define g_ButtonXState(button) ((g_NPad.buttons ^ HidNpadButton::button) == 0)
#define g_KeyXState(key) ((g_NPad.buttons ^ key) == 0)

//Noclip vars
float telePos[4] = { 0.0 };
float noclipPos[4] = { 0.0 };
float noclipDif[2] = { 0.0 };
bool isNoclip = false;

//Individual Room vars
float roomIL[3] = { 0.0 };
float finishIL[3] = { 0.0 };
float finishDelta = 700;
bool ILonce = false;//Set a new entrance
bool ILnext = false;//Set next entrance as finish line
bool ILallowTp = false;//Ignores any teleport that isnt a door tm
bool ILreset = false;//Whether to teleport
bool ILGauntlet = false;//Whether only the finish line teleports
bool ILForce = false;//Force all teleport types

int avoidRepeat = 30;//input is polled once per frame, equivalent to 30 frames or 0.5s
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