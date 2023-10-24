

#include "../lib.hpp"
#include "../lib/armv8/register.hpp"
#include "../lib/nx/runtime/pad.h"

const uintptr_t g_BaseAddress = exl::util::modules::GetTargetStart();
uintptr_t g_SpeedBooster = 0x0;
uintptr_t g_Player = 0x0;
uintptr_t g_PlayerPawn = 0x0;
u64 padButtons = 0;
u64 padButtonsOld = 0;
HidNpadFullKeyState g_NPad;
HidNpadFullKeyState restorePad;

struct{//from UpdatePlayerPawn's Player
    uintptr_t posX = 0x44;
    uintptr_t posY = 0x54;
    uintptr_t skew = 0x58;
    uintptr_t unkState = 0xB0;//u8
    uintptr_t unkState2 = 0x3D0;//u16
    uintptr_t velX = 0x2FA8;
    uintptr_t velY = 0x2FAC;
    uintptr_t fullInvuln = 0x3589;
    uintptr_t health = 0x14FA4;
    uintptr_t fKnockbackFrames = 0x14FB0;
    uintptr_t fIFrames = 0x14FB8;
    
    uintptr_t morphX = 0x789254;
    uintptr_t morphY = 0x789264;
    uintptr_t unkMorphState = 0x7892C0;
    uintptr_t morphXVel = 0x7897C8;
    uintptr_t morphYVel = 0x7897CC;
    uintptr_t morphGravity = 0x7896F4;
    uintptr_t morphRes = 0x78B9C6;
} playerOffs;

#define g_ButtonState(button) ((g_NPad.buttons & HidNpadButton::button) == HidNpadButton::button)
#define dontRestore(button) (restorePad.buttons &= ~(HidNpadButton::button))

bool ILonce = false;//Set a new entrance
bool ILallowTp = false;//Ignores any teleport that isnt a door tm
bool ILreset = false;//Whether to teleport
bool ILForce = false;//Force all teleport types

bool ignoreCombo = false;
int repeatInput = 0;
void checkInputs(){//NAND with input combo used and send new keystate maybe
    restorePad = g_NPad;
    ignoreCombo = false;

    if(repeatInput){
        repeatInput--;
        return;
    }

    if(!g_ButtonState(HidNpadButton_Down))
        return;

    ignoreCombo = true;

    if(g_ButtonState(HidNpadButton_ZL) && g_ButtonState(HidNpadButton_StickR)){
        dontRestore(HidNpadButton_ZL);
        dontRestore(HidNpadButton_StickR);

        ILreset = !ILreset;
        repeatInput = 200;
    }

    if(g_ButtonState(HidNpadButton_ZR) && g_ButtonState(HidNpadButton_StickR)){
        dontRestore(HidNpadButton_ZR);
        dontRestore(HidNpadButton_StickR);

        ILonce = false;
        repeatInput = 200;
    }
}

/* Define hook StubCopyright. Trampoline indicates the original function should be kept. */
/* HOOK_DEFINE_REPLACE can be used if the original function does not need to be kept. */
HOOK_DEFINE_TRAMPOLINE(StubCopyright) {

    /* Define the callback for when the function is called. Don't forget to make it static and name it Callback. */
    static void Callback(bool enabled) {

        /* Call the original function, with the argument always being false. */
        Orig(false);
    };

};

int ignoreCycles = 0;
HOOK_DEFINE_TRAMPOLINE(InstantSpeedBooster){//Instant Charge.
    static void Callback(uintptr_t speedboosterInst){
        g_SpeedBooster = speedboosterInst;

        float SpeedThreshhold = *(float*)(g_BaseAddress + 0x7265724c);//derived from the Tunable


        if(speedboosterInst)//Is Speed Booster Instance Valid?
            if(*(u8*)(speedboosterInst+0x394) == 1){//Is Speed Booster Charging?

                *(float*)(speedboosterInst+0x398) = SpeedThreshhold;//Set Speed Booster Time
            }

        if(g_PlayerPawn && *(u16*)(g_PlayerPawn + playerOffs.unkState2) && !ILallowTp){
            ILallowTp = true;
            ignoreCycles = 5;
        }

        if(ILallowTp || ignoreCycles > 0){//this is fucking inverted for some reason but it fucking works
            ignoreCycles--;
            if(ignoreCycles <= 0){
                ILallowTp = false;
            }
        }
        
        Orig(speedboosterInst);
    };//off 33ee94
};

HOOK_DEFINE_TRAMPOLINE(GetNpadStatic){
    static void Callback(int64_t param1){
        g_NPad = *(HidNpadFullKeyState*)(param1 + 0x660);

        checkInputs();
        if(ignoreCombo)
            *(HidNpadFullKeyState*)(param1 + 0x660) = restorePad;

        Orig(param1);
    };
};

HOOK_DEFINE_TRAMPOLINE(IgnoreSubAreaDeaths){
    static void Callback(uintptr_t EntityInst){
        g_Player = EntityInst;
        return;
    };
};

HOOK_DEFINE_TRAMPOLINE(ForceCoolSpark){
    static u64 Callback(u64 param1, uint* param2, uint* param3){
        return 1;
    };
};

HOOK_DEFINE_TRAMPOLINE(UpdatePlayerPawn){//includes all/most entites?
    static void Callback(long* Player, long* unkNewPos, ulong param3){

        
        if((Player+0x38) != unkNewPos){
            if(Player && !g_PlayerPawn && Player != (long*)g_PlayerPawn){
                g_PlayerPawn = (uintptr_t)Player;
            }
            //*(u8*)(g_PlayerPawn + playerOffs.morphRes) = 0;
        }

        return Orig(Player, unkNewPos, param3);
    };
};

float roomIL[3] = {0.0};
HOOK_DEFINE_TRAMPOLINE(RoomTransitionUnk){
    static void Callback(int64_t* Player, int32_t* unkNewPos, uint64_t param3){

        if(unkNewPos && (int64_t*)g_PlayerPawn == Player && *(float*)(g_PlayerPawn + playerOffs.posX)) {
            if(!ILonce){
                roomIL[0] = *(float*)(unkNewPos+0x00);
                roomIL[1] = *(float*)(g_PlayerPawn + playerOffs.posY);
                roomIL[2] = *(float*)(unkNewPos+0x08);
                ILonce = true;
            }
            
            if(roomIL[0] && ((ILreset && ILallowTp) || ILForce)) {
                Orig(Player, (int32_t*)roomIL, param3);
                return;
            }

        }
        Orig(Player, unkNewPos, param3);
    };
};

void TeleportPlayer(uintptr_t player, float location[2]){
    *(float*)(player + playerOffs.posX) = location[0];
    *(float*)(player + playerOffs.posY) = location[1];
    *(float*)(player + playerOffs.morphX) = location[0];
    *(float*)(player + playerOffs.morphY) = location[1];
}

/* Declare function to dynamic link with. */
namespace nn::oe {
    void SetCopyrightVisibility(bool);
};

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking enviroment. */
    exl::hook::Initialize();
    /* Install the hook at the provided function pointer. Function type is checked against the callback function. */
    StubCopyright::InstallAtFuncPtr(nn::oe::SetCopyrightVisibility);

    GetNpadStatic::InstallAtOffset(0x6dc7c);
    IgnoreSubAreaDeaths::InstallAtOffset(0xea4e68);
    InstantSpeedBooster::InstallAtOffset(0x33ee94);
    ForceCoolSpark::InstallAtOffset(0x32e798);
    UpdatePlayerPawn::InstallAtOffset(0x232bec);
    RoomTransitionUnk::InstallAtOffset(0xd6a5a0);

}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}