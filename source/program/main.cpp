//TODO add toggles for infinite missiles health etc, add toggles for invulns and other misc flags.

#include "main.h"

bool checkInputs(){
    //Store "Last Frames" inputs to make Frame Advance work
    storeForFA = comboButtons;

    if(repeatInput >= 1){
        repeatInput--;
        if(!waitOne){
            return true;
        }
    }

    if(g_ButtonState(HidNpadButton_Up)){//Toggle Turbo
        turboButtons = !turboButtons;
        repeatInput = 20;
        getCombo = true;
        comboButtons = 0;
        if(turboButtons)
            svcSleepThread(waitTime);//Wait for a bit so the player can hold the button(s) they want turbo'd
        return true;
    }

    if(!g_ButtonState(HidNpadButton_Down) && !waitOne){//If we arent trying to enter a combo then obviously dont listen and allow input
        comboButtons = 0;
        return false;
    } else {
        comboButtons |= HidNpadButton_Down;
        comboButtons ^= HidNpadButton_Down;

        if(!g_ButtonXState(HidNpadButton_Down) || waitOne){//If we are holding more than just DPAD Down

            //#pragma region hidecombos
            if(g_ButtonState(HidNpadButton_ZL) && g_ButtonState(HidNpadButton_StickR)){
                //Toggle Room IL
                ILreset = !ILreset;
                repeatInput = avoidRepeat;
                return true;
            }

            if(g_ButtonState(HidNpadButton_ZR) && g_ButtonState(HidNpadButton_StickR)){
                //Store Next Room Entrance

                ILonce = false;
                repeatInput = avoidRepeat;
                return true;
            }

            if(g_ButtonState(HidNpadButton_L) && g_ButtonState(HidNpadButton_StickR)){
                //Save Tele pos for Teleport

                telePos[0] = *(float*)(g_PlayerPawn + playerOffs.posX);
                telePos[1] = *(float*)(g_PlayerPawn + playerOffs.posY);
                telePos[2] = *(float*)(g_PlayerPawn + playerOffs.morphX);
                telePos[3] = *(float*)(g_PlayerPawn + playerOffs.morphY);
                repeatInput = avoidRepeat;
                return true;
            }

            if(g_ButtonState(HidNpadButton_R) && g_ButtonState(HidNpadButton_StickR)){
                //Tele to saved pos

                TeleportPlayer(g_PlayerPawn, telePos);
                repeatInput = avoidRepeat;
                return true;
            }

            if(g_ButtonState(HidNpadButton_R) && g_ButtonState(HidNpadButton_ZR)){
                //Tele to map cursor, TODO add a check for in menu

                float tempPos[4] = {mapCursorPos[0], mapCursorPos[1], mapCursorPos[0], mapCursorPos[1]};
                TeleportPlayer(g_PlayerPawn, tempPos);
                repeatInput = avoidRepeat;
                return true;
            }

            if(g_ButtonState(HidNpadButton_A) && g_ButtonState(HidNpadButton_B)){
                //Toggle cool spark

                forceCSpark = !forceCSpark;
                repeatInput = avoidRepeat;
                return true;
            }

            if(g_ButtonState(HidNpadButton_X) && g_ButtonState(HidNpadButton_Y)){
                //Toggle Instant Booster

                setInstantSpeed = !setInstantSpeed;
                repeatInput = avoidRepeat;
                return true;
            }
            //#endregion
            if(g_ButtonState(HidNpadButton_X) && g_ButtonState(HidNpadButton_A)){
                //Toggle Freeze Time

                *(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea) = !*(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea);
                ourFreeze = (!ourFreeze & *(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea));
                repeatInput = avoidRepeat;
                comboButtons |= (HidNpadButton_X | HidNpadButton_A);//Just in case
                
                return false;
            }
        }
    }
    return false;
}

void TeleportPlayer(uintptr_t player, float location[4]){
    *(float*)(player + playerOffs.posX) = location[0];
    *(float*)(player + playerOffs.posY) = location[1];
    *(float*)(player + playerOffs.morphX) = location[2];
    *(float*)(player + playerOffs.morphY) = location[3];
}

void ManipulateInput(HidNpadCommonState* state){
    
    if(!waitOne){
        if(ignoreCombo){
                state->buttons &= HidNpadButton_Down;//Dont remove dpad down it causes issues
                state->analog_stick_l = (HidAnalogStickState)0;
                state->analog_stick_r = (HidAnalogStickState)0;
        } else 
        if(comboButtons){
            comboButtons ^= HidNpadButton_Down;//Remove DPAD Down
            state->buttons ^= comboButtons;//XOR combo buttons to ignore them
            state->buttons ^= HidNpadButton_Down;//Reset DPAD Down
            comboButtons = 0;
        }
    }

    if(turboButtons && !ignoreCombo) {

        if(turboSwitcher){
            turboSwitcher = false;
            state->buttons &= ~turboCombo;
        } 
        else {
            turboSwitcher = true;
        }
    }
}

void handleInput(HidNpadFullKeyState *state){
    g_NPad = *state;//yoinky state to use for inputs
    comboButtons = g_NPad.buttons;//store copy of pre-modified state for later use
    if(getCombo){//Grab combo for turbo
        turboCombo = (g_NPad.buttons | HidNpadButton_Up);
        turboCombo ^= HidNpadButton_Up;//Don't turbo the turbo toggle button lol
        getCombo = false;
    }

    ignoreCombo = checkInputs();//Do all input based logic

    ManipulateInput(state);//Manipulate game perceived controler state
}

HOOK_DEFINE_TRAMPOLINE(DisableFullKeyState){
    static int Callback(HidNpadFullKeyState *state, int *unkInt){
        int result = Orig(state, unkInt);

        handleInput(state);

        return result;

    };
};

HOOK_DEFINE_TRAMPOLINE(DisableHandheldState){
    static int Callback(HidNpadHandheldState *state, int *unkInt){
        int result = Orig(state, unkInt);

        handleInput(state);

        return result;

    };
};

HOOK_DEFINE_TRAMPOLINE(DisableJoyDualState) {
  static int Callback(HidNpadJoyDualState *state, int *unkInt) {
        int result = Orig(state, unkInt);

        handleInput(state);

    return result;
  };
};

HOOK_DEFINE_TRAMPOLINE(DisableJoyLeftState) {
  static int Callback(HidNpadJoyLeftState *state, int *unkInt) {
        int result = Orig(state, unkInt);

        handleInput(state);

    return result;
  };
};

HOOK_DEFINE_TRAMPOLINE(DisableJoyRightState) {
  static int Callback(HidNpadJoyRightState *state, int *unkInt) {
        int result = Orig(state, unkInt);

        handleInput(state);

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

HOOK_DEFINE_TRAMPOLINE(checkForFrameAdvance){//this one sucks, and its only use seems to be that frame advance works in it, but nothing else does :)
    static void Callback(int64_t param1){

        g_NPad.buttons = storeForFA;//hacky solution to immitate the old functionality of this function.
    
        if(((g_ButtonState(HidNpadButton_Y) && g_ButtonState(HidNpadButton_A)) && g_ButtonState(HidNpadButton_Down)) || waitOne){
            //Advance one frame
            
            if(ourFreeze && *(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea)){
                *(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea) = false;
                waitOne = true;
                svcSleepThread(waitTime);
            }
            else{
                *(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea) = true;
                waitOne = false;
            }
        }


        Orig(param1);
    };
};

HOOK_DEFINE_TRAMPOLINE(IgnoreSubAreaDeaths){
    static void Callback(uintptr_t EntityInst){
        g_Player = EntityInst;
        if(!ignoreOobDeath){
            Orig(EntityInst);
        }
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

    DisableFullKeyState::InstallAtSymbol("_ZN2nn3hid12GetNpadStateEPNS0_16NpadFullKeyStateERKj");
    DisableHandheldState::InstallAtSymbol("_ZN2nn3hid12GetNpadStateEPNS0_17NpadHandheldStateERKj");
    DisableJoyDualState::InstallAtSymbol("_ZN2nn3hid12GetNpadStateEPNS0_16NpadJoyDualStateERKj");
    DisableJoyLeftState::InstallAtSymbol("_ZN2nn3hid12GetNpadStateEPNS0_16NpadJoyLeftStateERKj");
    DisableJoyRightState::InstallAtSymbol("_ZN2nn3hid12GetNpadStateEPNS0_17NpadJoyRightStateERKj");

    GetMapCursor::InstallAtOffset(0x1b9f44);
    checkForFrameAdvance::InstallAtOffset(0x6dc7c);
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