//TODO add toggle for instant speed, add toggles for infinite missiles health etc, add toggles for invulns and other misc flags. Fix Inputs not being ignored

#include "main.h"

void checkInputs(){//NAND with input combo used and send new keystate maybe

    if(repeatInput){
        repeatInput--;
        if(!waitOne)
            return;
    }

    if(g_ButtonState(HidNpadButton_Up)){
        turboButtons = !turboButtons;
        repeatInput = avoidRepeat;
    }

    if(!g_ButtonState(HidNpadButton_Down)){
        ignoreCombo = false;
        return;
    }
    ignoreCombo = true;

    //Wait for some time since combos are probably not frame perfect lol
    //svcSleepThread(waitTime);
    restorePad.buttons = 0;
    restorePad.analog_stick_l = (HidAnalogStickState)0;
    restorePad.analog_stick_r = (HidAnalogStickState)0;

    if(g_ButtonState(HidNpadButton_ZL) && g_ButtonState(HidNpadButton_StickR)){
        dontRestore(HidNpadButton_ZL);
        dontRestore(HidNpadButton_StickR);

        ILreset = !ILreset;
        repeatInput = avoidRepeat;
    }

    if(g_ButtonState(HidNpadButton_ZR) && g_ButtonState(HidNpadButton_StickR)){
        dontRestore(HidNpadButton_ZR);
        dontRestore(HidNpadButton_StickR);

        ILonce = false;
        repeatInput = avoidRepeat;
    }

    if(g_ButtonState(HidNpadButton_L) && g_ButtonState(HidNpadButton_StickR)){
        telePos[0] = *(float*)(g_PlayerPawn + playerOffs.posX);
        telePos[1] = *(float*)(g_PlayerPawn + playerOffs.posY);
        telePos[2] = *(float*)(g_PlayerPawn + playerOffs.morphX);
        telePos[3] = *(float*)(g_PlayerPawn + playerOffs.morphY);
    }

    if(g_ButtonState(HidNpadButton_R) && g_ButtonState(HidNpadButton_StickR)){
        TeleportPlayer(g_PlayerPawn, telePos);
    }

    if(g_ButtonState(HidNpadButton_R) && g_ButtonState(HidNpadButton_ZR)){
        float tempPos[4] = {mapCursorPos[0], mapCursorPos[1], mapCursorPos[0], mapCursorPos[1]};
        TeleportPlayer(g_PlayerPawn, tempPos);
    }
    
    if(g_ButtonState(HidNpadButton_A) && g_ButtonState(HidNpadButton_B)){
        forceCSpark = !forceCSpark;
        repeatInput = avoidRepeat;
    }
    
    if(g_ButtonState(HidNpadButton_X) && g_ButtonState(HidNpadButton_Y)){
        setInstantSpeed = !setInstantSpeed;
        repeatInput = avoidRepeat;
    }
    
    if(g_ButtonState(HidNpadButton_X) && g_ButtonState(HidNpadButton_A)){
        *(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea) = !*(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea);
        ourFreeze = (!ourFreeze & *(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea));
        repeatInput = avoidRepeat;
        svcSleepThread(waitTime);
    }
    
    if((g_ButtonState(HidNpadButton_Y) && g_ButtonState(HidNpadButton_A)) || waitOne){
        if(ourFreeze && *(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea)){
            *(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea) = false;
            waitOne = true;
            svcSleepThread(waitTime);
            restorePad = g_NPad;
        }
        else{
            *(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea) = true;
            waitOne = false;
        }
        repeatInput = avoidRepeat;
    }


    
}

void TeleportPlayer(uintptr_t player, float location[4]){
    *(float*)(player + playerOffs.posX) = location[0];
    *(float*)(player + playerOffs.posY) = location[1];
    *(float*)(player + playerOffs.morphX) = location[2];
    *(float*)(player + playerOffs.morphY) = location[3];
}

HOOK_DEFINE_TRAMPOLINE(DisableFullInput){
    static int Callback(HidNpadFullKeyState* state, uint32_t* unkInt){
        int result = Orig(state, unkInt);

        if(ignoreCombo && false){//it doesnt work rn so force off
            //state->buttons = restorePad.buttons;
            //state->analog_stick_l = restorePad.analog_stick_l;
            //state->analog_stick_r = restorePad.analog_stick_r;
            state->buttons = 0;
            state->analog_stick_l = (HidAnalogStickState)0;
            state->analog_stick_r = (HidAnalogStickState)0;
        }

        return result;

    };
};

HOOK_DEFINE_TRAMPOLINE(DisableHandheldInput){
    static int Callback(HidNpadHandheldState* state, uint32_t* unkInt){
        int result = Orig(state, unkInt);

        if(ignoreCombo){
            state->buttons = restorePad.buttons;
            state->analog_stick_l = restorePad.analog_stick_l;
            state->analog_stick_r = restorePad.analog_stick_r;
        }

        return result;

    };
};

HOOK_DEFINE_TRAMPOLINE(GetMapCursor){
    static void Callback(int64_t param1){
        mapCursorPos[0] = *(float*)(param1 + 0x134);
        mapCursorPos[1] = *(float*)(param1 + 0x138);
        mapCursorPos[2] = *(float*)(param1 + 0x13c);

        Orig(param1);
    };
};

HOOK_DEFINE_TRAMPOLINE(InstantSpeedBooster){//Instant Charge.
    static void Callback(uintptr_t speedboosterInst){
        g_SpeedBooster = speedboosterInst;

        float SpeedThreshhold = *(float*)(g_BaseAddress + 0x7265724c);//derived from the Tunable


        if(speedboosterInst && setInstantSpeed)//Is Speed Booster Instance Valid and are we using it.
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
    };
};

HOOK_DEFINE_TRAMPOLINE(GetNpadStatic){
    static void Callback(int64_t param1){
        g_NPad = *(HidNpadFullKeyState*)(param1 + 0x660);
        restorePad = *(HidNpadFullKeyState*)(param1 + 0x660);

        checkInputs();

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
        bool origRet = Orig(param1, param2, param3);

        return origRet | forceCSpark;
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

HOOK_DEFINE_TRAMPOLINE(RoomTransitionUnk){
    static void Callback(int64_t* Player, int32_t* unkNewPos, uint64_t param3){

        if(unkNewPos && (int64_t*)g_PlayerPawn == Player && *(float*)(g_PlayerPawn + playerOffs.posX) && ((ILreset && ILallowTp) || ILForce)) {
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

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking enviroment. */
    exl::hook::Initialize();

    DisableFullInput::InstallAtOffset(0x11f3630);
    DisableHandheldInput::InstallAtOffset(0x11f3640);

    GetMapCursor::InstallAtOffset(0x1b9f44);
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