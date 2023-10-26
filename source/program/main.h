#pragma once

#include "../lib.hpp"
#include "../lib/armv8/register.hpp"
#include "../lib/nx/runtime/pad.h"

const uintptr_t g_BaseAddress = exl::util::modules::GetTargetStart();
uintptr_t g_SpeedBooster = 0x0;
uintptr_t g_Player = 0x0;
uintptr_t g_PlayerPawn = 0x0;
float mapCursorPos[3] = { 0.0 };
u64 padButtons = 0;
u64 padButtonsOld = 0;
HidNpadFullKeyState g_NPad;
//HidNpadFullKeyState restorePad;

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
    uintptr_t fKnockbackFrames = 0x14FB0;//float
    uintptr_t fIFrames = 0x14FB8;//float
    
    //Morph
    uintptr_t morphX = 0x789254;//float
    uintptr_t morphY = 0x789264;//float
    uintptr_t morphXVel = 0x7897C8;//float
    uintptr_t morphYVel = 0x7897CC;//float
    uintptr_t morphGravity = 0x7896F4;//bool
    uintptr_t morphRes = 0x78B9C6;//bool

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