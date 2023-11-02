//TODO add toggles for infinite missiles health etc, add toggles for invulns and other misc flags.

#include "main.h"

int64_t unkItem = 0;
int64_t unkItem2 = 0;
int64_t unkItem10 = 0;
int64_t unkDat = 0;
int64_t unkDat2 = 0;
uint64_t unkDat3 = 0;//this is a static pointer that can be followed to the player(with unk_db2798_func).
//it also most likely points to more important world state variables and im looking into it.
int64_t lVar1 = 0;
uint64_t lVar2 = 0;
int64_t* plVar3 = 0;
float thisItemVal = 0;

//old idea to use signatures to fix for updates
//but the game doesn't update profusely (or really at all) so its not worth fixing

//uintptr_t checkWildcard(uintptr_t mask, uintptr_t input){
//    uintptr_t tempMask        = mask;
//             (tempMask <<= 8) += mask;
//             (tempMask <<= 8) += mask;
//             (tempMask <<= 8) += mask;
//
//
//    uintptr_t tempInput = input ^ tempMask;
//
//    for(int i = 0; i < 4; i++){
//        if(!(uint8_t)tempInput){
//            tempInput >>= 8;
//            tempInput += 0xFF000000;
//        } else {
//            tempInput >>= 8;
//        }
//    }
//
//    return tempInput;
//}
////doesnt work
//uint64_t sigScanMain(uint32_t scanOps[], int scanSize){
//    uintptr_t wildcard = 0xB3;
//
//    uintptr_t curOffset = 0;
//    uintptr_t curMask = 0;
//
//    if(scanSize){
//        while((curOffset+g_BaseAddress) <= g_MainEnd){
//            for(int i = 0; i < scanSize; i++){
//                if(scanOps[i] != *(uint32_t*)(g_BaseAddress+curOffset)){//if the instruction isnt the one we want
//                    if(curMask = checkWildcard(wildcard, scanOps[i]), curMask == 0)
//                        continue;
//                    if(((scanOps[i] | curMask) ^ curMask) != ((*(uint32_t*)(g_BaseAddress+curOffset) | curMask) ^ curMask))
//                        continue;
//                }
//                if(i == scanSize)
//                    return ((g_BaseAddress+curOffset) - (0x4*scanSize));
//            }
//            curOffset += 0x4;
//        }
//    }
//    return 0;
//}

//Item pointers are wrong or something. Only sets the first variable(health)
void duplicateGiveAllItems(){
    unkItem = 0;
    unkItem2 = 0;
    unkItem10 = 0;
    unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
    unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
    unkDat3 = *(*(uint64_t**)(g_BaseAddress+0x1c626b8));//2.1 +0x579D0

    lVar1 = outFuncs::unk_db2798_func(unkDat3);
    if (lVar1) {
        //This probably unlocks Aeion or something but doesnt seem required other than that.
        //lVar2 = outFuncs::unk_302b54_func(lVar1);
        //if (lVar2) {
        //    outFuncs::unk_a1d158_func(2200.0, lVar1);
        //    outFuncs::unk_a1d258_func(2200.0, lVar2, 0x0, 0x1);
        //}
        //plVar3 = *(int64_t **)(lVar1 + 0x1b8);
        //initplVar3(plVar3);
        //if (plVar3) {
        //    unkplVar3_170_func(1099.0, plVar3);
        //    unkplVar3_168_func(1099.0, plVar3, 0x1);
        //}
        lVar1 = *(int64_t*)(lVar1 + 0x270);

        if (lVar1) {
            for(int i = 0; i < 37; i++){
                unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[i]);
                unkItem2 = *(int64_t*)(unkItem+0x10);

                if(i < 10)
                    thisItemVal = itemVals[i];
                else
                    thisItemVal = 1.0;

                if (unkItem2 == (unkDat2+0x10)) {
                    outFuncs::givePlayerItem((unkItem+0x10), unkItem, unkDat);
                }
                outFuncs::givePlayerItem2(thisItemVal, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
            }

            outFuncs::unk_dc47a0_func(unkDat3);
        }
    }
}

void handleFrameAdvance(){
    g_NPad.buttons = storeForFA;//hacky solution to immitate old functionality.
    
    if(((g_ButtonState(HidNpadButton_Y) && g_ButtonState(HidNpadButton_A)) && g_ButtonState(HidNpadButton_Down)) || waitOne){
        //Advance one frame
        if(storeForWaitOne != (storeForFA))
            storeForWaitOne = storeForFA;
        
        if(ourFreeze || !waitOne){
            //*(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea) = false;
            repeatInput = avoidRepeat;
            outFuncs::togglePause();
            waitOne = true;
            svcSleepThread(waitTime);
        } else {
            //*(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea) = true;
            
            repeatInput = 10;
            outFuncs::togglePause();
            waitOne = false;
        }
    }
}

bool checkInputs(){
    //Store "Last Frames" inputs to make Frame Advance work
    storeForFA = comboButtons;

    if(isNoclip){
        noclipDif[0] += ((g_NPad.analog_stick_r.x * 40) / 0x7FFF);
        noclipDif[1] += ((g_NPad.analog_stick_r.y * 40) / 0x7FFF);

        *(float*)(g_PlayerPawn+playerOffs.posX) = noclipPos[0] + noclipDif[0];
        *(float*)(g_PlayerPawn+playerOffs.posY) = noclipPos[1] + noclipDif[1];
        *(float*)(g_PlayerPawn+playerOffs.morphX) = noclipPos[2] + noclipDif[0];
        *(float*)(g_PlayerPawn+playerOffs.morphY) = noclipPos[3] + noclipDif[1];
    } else {
        noclipDif[0] = 0;
        noclipDif[1] = 0;
    }

    if(repeatInput >= 1){
        repeatInput--;
        return true;
    }

    if(g_ButtonState(HidNpadButton_Up)){//Toggle Turbo
        turboButtons = !turboButtons;
        //testing

        //outFuncs::showGameFps(); //does nothing?
        //duplicateGiveAllItems(); //doesnt really work right now, lots of undefined reads so probably a bad typedef'd arg
        //outFuncs::setCheater(); //does nothing?
        //if(g_luaState)
        //    outFuncs::makePlayerInvincible(g_luaState);
        //outFuncs::killCurrentBoss(); //works
        //outFuncs::hideGameScenario(); //disables z flushing(?) like when out of bounds in a source game

        repeatInput = 20;
        getCombo = true;
        comboButtons = 0;
        if(turboButtons){//delete testing shit later
            //outFuncs::showGameScenario(); //fixes z flushing
            svcSleepThread(waitTime);//Wait for a bit so the player can hold the button(s) they want turbo'd
        }
        return true;
    }

    if(g_ButtonState(HidNpadButton_R)){
        comboButtons = 0;
        unkDat3 = *(*(uint64_t**)(g_BaseAddress+0x1c626b8 + (0x579D0 * g_Version)));//2.1 +0x579D0

        if(g_ButtonState(HidNpadButton_Left)){
            comboButtons |= (HidNpadButton_R | HidNpadButton_Left);
            slomoSpeed -= 0.05;
            repeatInput = 5;
            outFuncs::setGameSpeed(slomoSpeed, 0, unkDat3);
            return true;
        }
        if(g_ButtonState(HidNpadButton_Right)){
            comboButtons |= (HidNpadButton_R | HidNpadButton_Right);
            slomoSpeed += 0.05;
            repeatInput = 5;
            outFuncs::setGameSpeed(slomoSpeed, 0, unkDat3);
            return true;
        }
        if(g_ButtonState(HidNpadButton_Minus)){
            comboButtons |= (HidNpadButton_R | HidNpadButton_Minus);
            slomoSpeed = 1;
            repeatInput = avoidRepeat;
            outFuncs::setGameSpeed(slomoSpeed, 0, unkDat3);
            return true;
        }
    }

    if(g_ButtonState(HidNpadButton_L) && !g_ButtonState(HidNpadButton_Down)){
        comboButtons = 0;
        if(g_ButtonState(HidNpadButton_Left)){
            comboButtons |= HidNpadButton_Left | HidNpadButton_L;
            
            isNoclip = !isNoclip;
            if(isNoclip){
                repeatInput = avoidRepeat;
                noclipPos[0] = *(float*)(g_PlayerPawn+playerOffs.posX);
                noclipPos[1] = *(float*)(g_PlayerPawn+playerOffs.posY);
                noclipPos[2] = *(float*)(g_PlayerPawn+playerOffs.morphX);
                noclipPos[3] = *(float*)(g_PlayerPawn+playerOffs.morphY);
            } else {
                repeatInput = 10;
            }
            return true;
        }
        if(g_ButtonState(HidNpadButton_Right)){
            if(isNoclip){
                repeatInput = 10;
                *(float*)(g_PlayerPawn+playerOffs.posX) = noclipPos[0];
                *(float*)(g_PlayerPawn+playerOffs.posY) = noclipPos[1];
                *(float*)(g_PlayerPawn+playerOffs.morphX) = noclipPos[2];
                *(float*)(g_PlayerPawn+playerOffs.morphY) = noclipPos[3];
                isNoclip = false;
            }
            return true;
        }
        return false;
    }

    //If we arent trying to enter a combo or are using Frame Advance, don't listen and allow input
    if(!g_ButtonState(HidNpadButton_Down) || waitOne){
        comboButtons = 0;
        return false;
    } else {
        comboButtons |= HidNpadButton_Down;
        comboButtons ^= HidNpadButton_Down;

        //If we are just holding DPAD Down still ignore inputs
        if(!g_ButtonXState(HidNpadButton_Down)){

            //Give All Items
            if(g_ButtonState(HidNpadButton_Plus)){
                outFuncs::givePlayerAllItems(); //works, 7 tanks, 150 missiles, and everything else except power bombs and hyper beam
            }

            //Fill missiles and health
            if(g_ButtonState(HidNpadButton_Minus)){
                outFuncs::recoverPlayerLife();
                outFuncs::recoverPlayerMissiles();
                repeatInput = avoidRepeat;
                return true;
            }

            //Toggle OOB Ignore
            if(g_ButtonState(HidNpadButton_StickL)){
                ignoreOobDeath = !ignoreOobDeath;
                repeatInput = avoidRepeat;
                return true;
            }

            //Room IL, Room IL Gauntlet, Store Pos and Tele Pos
            if(g_ButtonState(HidNpadButton_StickR)){
                if(g_ButtonState(HidNpadButton_ZR)){
                    //Store Next Room Entrance
                    ILonce = false;
                    repeatInput = avoidRepeat;
                    return true;
                }

                if(g_ButtonState(HidNpadButton_ZL)){
                    //Toggle Room IL
                    ILreset = !ILreset;
                    repeatInput = avoidRepeat;
                    return true;
                }

                if(g_ButtonState(HidNpadButton_X)){
                    //Store Next Room Entrance As Finish Line
                    ILnext = false;
                    repeatInput = avoidRepeat;
                    return true;
                }

                if(g_ButtonState(HidNpadButton_Y)){
                    //Toggle IL Gauntlet
                    ILGauntlet = !ILGauntlet;
                    repeatInput = avoidRepeat;
                    return true;
                }

                if(g_ButtonState(HidNpadButton_L)){
                    //Save Tele pos for Teleport
                    telePos[0] = *(float*)(g_PlayerPawn + playerOffs.posX);
                    telePos[1] = *(float*)(g_PlayerPawn + playerOffs.posY);
                    telePos[2] = *(float*)(g_PlayerPawn + playerOffs.morphX);
                    telePos[3] = *(float*)(g_PlayerPawn + playerOffs.morphY);
                    repeatInput = avoidRepeat;
                    return true;
                }

                if(g_ButtonState(HidNpadButton_R)){
                    //Tele to saved pos
                    TeleportPlayer(g_PlayerPawn, telePos);
                    repeatInput = avoidRepeat;
                    return true;
                }
            }

            //Tele to map cursor, TODO add a check for in menu
            if(g_ButtonState(HidNpadButton_R) && g_ButtonState(HidNpadButton_ZR)){
                //if(!ourFreeze){
                    float tempPos[4] = {mapCursorPos[0], mapCursorPos[1], mapCursorPos[0], mapCursorPos[1]};
                    TeleportPlayer(g_PlayerPawn, tempPos);
                    repeatInput = avoidRepeat;
                    return true;
                //}
            }

            //Toggle cool spark
            if(g_ButtonState(HidNpadButton_A) && g_ButtonState(HidNpadButton_B)){
                forceCSpark = !forceCSpark;
                repeatInput = avoidRepeat;
                return true;
            }

            //Toggle Instant Booster
            if(g_ButtonState(HidNpadButton_X) && g_ButtonState(HidNpadButton_Y)){
                setInstantSpeed = !setInstantSpeed;
                repeatInput = avoidRepeat;
                return true;
            }

            //Toggle Freeze Time
            if((g_ButtonState(HidNpadButton_X) && g_ButtonState(HidNpadButton_A))){
                outFuncs::togglePause();

                //ourFreeze = !ourFreeze;//Desyncs if unpausing the game manually. Gonna get IsGamePaused working before using this
                //*(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea) = !*(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea);
                //ourFreeze = (!ourFreeze & *(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea));
                
                storeForWaitOne = 0;

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
    if(storeForWaitOne){
        state->buttons = (storeForFA & storeForWaitOne);
        return;
    }

    if(!waitOne){
        if(ignoreCombo){
                state->buttons &= HidNpadButton_Down;//Dont remove dpad down it causes issues
                //state->analog_stick_l = (HidAnalogStickState)0; //useful later for gui
                //state->analog_stick_r = (HidAnalogStickState)0; //useful later for gui
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
        handleFrameAdvance();
    
        int result = Orig(state, unkInt);

        handleInput(state);

        return result;

    };
};

HOOK_DEFINE_TRAMPOLINE(DisableHandheldState){
    static int Callback(HidNpadHandheldState *state, int *unkInt){
        handleFrameAdvance();

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

        float SpeedThreshhold = *(float*)(g_BaseAddress + 0x7265724c + (0x59DA0 * g_Version));//derived from the Tunable


        if(speedboosterInst && setInstantSpeed){//Is Speed Booster Instance Valid and are we using it.
            if(*(u8*)(speedboosterInst+0x394) == 1 || g_ButtonState(HidNpadButton_StickL)){//Is Speed Booster Charging?
                

                *(float*)(speedboosterInst+0x398) = SpeedThreshhold;//Set Speed Booster Time
            }
        }
        if(g_PlayerPawn && *(u16*)(g_PlayerPawn + playerOffs.unkState2) && !ILallowTp){
            ILallowTp = true;
            ignoreCycles = 5;
        }

        if(ILallowTp || ignoreCycles > 0){
            ignoreCycles--;
            if(ignoreCycles <= 0){
                ILallowTp = false;
            }
        }
        
        Orig(speedboosterInst);
    };
};

HOOK_DEFINE_TRAMPOLINE(IgnoreSubAreaDeaths){
    static void Callback(uintptr_t EntityInst){
        g_Player = EntityInst;
        if(!(ignoreOobDeath | isNoclip)){
            Orig(EntityInst);
        }
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
        //if(!setFps){
        //    setFps = (uint64_t*)((**(uintptr_t**)(g_BaseAddress + 0x1c62718 + (0x57A08 * g_Version))) + 0x38);
        //    frameRate(60);
        //}
        if((Player+0x38) != unkNewPos){
            if(Player && !g_PlayerPawn && Player != (long*)g_PlayerPawn){
                g_PlayerPawn = (uintptr_t)Player;
            }
        }

        return Orig(Player, unkNewPos, param3);
    };
};

HOOK_DEFINE_TRAMPOLINE(RoomTransitionUnk){
    static void Callback(int64_t* Player, int32_t* unkNewPos, uint64_t param3){
        if(unkNewPos && ((int64_t*)g_PlayerPawn == Player) && ILallowTp) {
            newPosX = *(float*)(unkNewPos+0x00);
            newPosY = *(float*)(g_PlayerPawn + playerOffs.posY);
            newPosZ = *(float*)(unkNewPos+0x08);

            if(!ILonce){
                roomIL[0] = newPosX;
                roomIL[1] = newPosY;
                roomIL[2] = newPosZ;
                ILonce = true;
            }

            if(!ILnext){
                finishIL[0] = newPosX;
                finishIL[1] = newPosY;
                finishIL[2] = newPosZ;
                ILnext = true;
            }
            
            if((ILreset && ILallowTp) || ILForce || ILGauntlet) {
                if((roomIL[0] && !ILGauntlet) || ILForce){
                    Orig(Player, (int32_t*)roomIL, param3);
                    return;
                }

                if(finishIL[0]){
                    if(((newPosX - finishDelta) < finishIL[0]) && (finishIL[0] < (newPosX + finishDelta))){
                        if(((newPosY - 50) < finishIL[1]) && (finishIL[1] < (newPosY + 50))){
                            Orig(Player, (int32_t*)roomIL, param3);
                            return;
                        }
                    }
                }
            }
        }
        Orig(Player, unkNewPos, param3);
    };
};

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking enviroment. */
    exl::hook::Initialize();

    initExternFuncs();
    
    //HideScenario void 0x1041010(void) works
    //ShowScenario void 0x1040fe0(void) works
    //DEBUG_TESTMakePlayerInvulnerable 710103e0e0(und8 unkParam1)
    //SaveSnapShotToCheckpointLua? 7101036ea0(und8 unkParam1)
    //setFrameRateLua? 710103efb0(und8 unkParam1)
    //ShowFps 710103dfe0(void) no worky
    //EnableDebugMinimap 71010534a0(lua_state?)
    //SetIAmACheater 7101054de0(void) nothing?

    DisableFullKeyState::InstallAtSymbol("_ZN2nn3hid12GetNpadStateEPNS0_16NpadFullKeyStateERKj");
    DisableHandheldState::InstallAtSymbol("_ZN2nn3hid12GetNpadStateEPNS0_17NpadHandheldStateERKj");

    GetMapCursor::InstallAtOffset(0x1b9f44 + (0x430 * g_Version));//+0x430
    IgnoreSubAreaDeaths::InstallAtOffset(0xea4e68 + (0x40720 * g_Version));//0x40720
    InstantSpeedBooster::InstallAtOffset(0x33ee94 + (0x868 * g_Version));//0x868
    ForceCoolSpark::InstallAtOffset(0x32e798 + (0x638 * g_Version));//+0x638
    UpdatePlayerPawn::InstallAtOffset(0x232bec + (0x490 * g_Version));//0x490
    RoomTransitionUnk::InstallAtOffset(0xd6a5a0 + (0x12B00 * g_Version));//0x12B00

    //uint32_t tempOffsets[7] = { 0xfd7bbfa9, 0xfd030091, 0xb3b300b3, 0x08b3b3f9, 0x080140f9, 0x004d42f9, 0x800000b4 };
    //checkForFrameAdvance::InstallAtOffset(sigScanMain(tempOffsets, 7));//0x230 sig: fd7bbfa9 fd030091 b3b300b3 08b3b3f9 080140f9 004d42f9 800000b4
}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}