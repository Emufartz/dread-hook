//TODO add toggles for infinite missiles health etc, add toggles for invulns and other misc flags.

#include "main.h"

int64_t curItem = 0;
int64_t curItemName = 0;
int64_t itemNamesArray = 0;
uint64_t playerAeion = 0;
CHealthComponent* plrHealthComp = 0;

const int menuEntriesMax = 32;
menuEntry menuText[menuEntriesMax];
float screenPos[3];
float worldPos[3];
float unkF1 = 0;
float unkF2 = 0;
float scaledX = 1600.0;
float scaledY = 900.0;

int drawTextOnScreen(float damageDealt, long param_2, float drawPos[3], float drawColor[3], const wchar_t* string) {
    uint **ppuVar1;
    long **ppTVar5;
    long *tempStr;
    uint32_t *puVar5;
    int iVar6;
    uint **ppuVar7;
    uint **ppuVar8;
    uint **ppuVar9;
    long *formattedText;

    if (*(ulong *)(param_2 + 0x25a8) == *(ulong *)(param_2 + 0x25e0) >> 5) {
        ppuVar1 = ppuVar7 = *(uint ***)(param_2 + 0x25b0);
  
        for (ppuVar8 = (uint **)ppuVar7[3]; ppuVar8; ppuVar8 = (uint **)ppuVar8[3]) {
            ppuVar9 = ppuVar8;
            if (*(float *)((long)ppuVar1 + 0x8) <= *(float *)((long)ppuVar8 + 0x8)) {
                ppuVar9 = ppuVar1;
            }
            ppuVar1 = ppuVar9;
        }
        ppuVar8 = 0x0;

        do {
            ppuVar9 = ppuVar8;
            ppuVar8 = ppuVar7;
            if (!ppuVar8) break;
            ppuVar7 = (uint **)ppuVar8[3];
        } while (ppuVar8 != ppuVar1);

        if(ppuVar8){
            if (!ppuVar9) {
                *(uint64_t *)(param_2 + 0x25b0) = (uint64_t)ppuVar7;
            }
            else {
                ppuVar9[3] = (uint *)ppuVar7;
                if (*(uint ***)(param_2 + 0x25b8) == ppuVar1) {
                    *(uint ***)(param_2 + 0x25b8) = ppuVar9;
                    iVar6 = --(*(int *)(param_2 + 0x25a8));
                }
            }

            iVar6 = --(*(int *)(param_2 + 0x25a8));
            if(!iVar6){
                *(uint64_t *)(param_2 + 0x25b0) = 0;
                *(uint64_t *)(param_2 + 0x25b8) = 0;
            }

            if (*ppuVar1) {
                outFuncs::FUN_7100219548(DAT_7101cee300,*ppuVar1,0);
                *ppuVar1 = 0x0;
            }
            outFuncs::UnkDebugTextDtor(*(long **)(param_2 + 0x25c0),(uint64_t*)ppuVar1);
        }
    }

    ppTVar5 = (long **)outFuncs::FUN_7100075454(*(long *)(param_2 + 0x25c0),0x20,0x8,*(float *)(param_2 + 0x25c8));
    if (!ppTVar5) {
        ppTVar5 = *(long ***)(param_2 + 0x25b8);
    } else {
        ppTVar5[0] = 0x0;
        ppTVar5[1] = 0x0;
        ppTVar5[2] = 0x0;
        ppTVar5[3] = 0x0;
        if (!(*(int *)(param_2 + 0x25a8))) {
            iVar6 = 1;
            *(long ***)(param_2 + 0x25b0) = ppTVar5;
        }
        else {
            *(long ***)(*(long *)(param_2 + 0x25b8) + 0x18) = ppTVar5;
            ppTVar5[3] = 0x0;
            iVar6 = *(int *)(param_2 + 0x25a8) + 1;
        }
        *(long ***)(param_2 + 0x25b8) = ppTVar5;
        *(int *)(param_2 + 0x25a8) = iVar6;//advances duration timer?
    }
    *(float *)((long)ppTVar5 + 0x8) = 1.0;// duration
    *(float *)((long)ppTVar5 + 0xc) = drawPos[0];
    *(float *)((long)ppTVar5 + 0x10) = drawPos[1];
    *(float *)((long)ppTVar5 + 0x14) = drawPos[2];
    formattedText = 0x0;
    outFuncs::FUN_7100d9977c(*(long ***)(*(uint64_t*)DAT_7101cee300 + 0x218),0,&formattedText);
    outFuncs::FUN_7100219650(*(uint64_t*)DAT_7101cee300,formattedText,2);
    *ppTVar5 = formattedText;
    if (formattedText) {
        outFuncs::HashString(&formattedText,"digital_small",true);
        puVar5 = outFuncs::FUN_71011738ec(*(uint64_t*)DAT_71726c5788,&formattedText);
        tempStr = (long *)DAT_7101cee108;
        if (DAT_7101cee108) {
            if ((formattedText) &&
                (iVar6 = --(*(int *)(formattedText + 1)), !iVar6)) {
                outFuncs::FUN_7100080124(tempStr,formattedText);//ReleaseStringInstance
                tempStr = (long *)DAT_7101cee108;
            }
            formattedText = (long*)((long)tempStr + 0x10);
        }
        if (puVar5) {
            (*ppTVar5)[0x27] = (long)puVar5;
            outFuncs::FUN_71001c3a90((*ppTVar5)[0x26],(long)(puVar5 + 0x6));
            *(char *)((long)(*ppTVar5) + 0x11b) = 0x1;
            outFuncs::FUN_710020bdb8((long)(*ppTVar5 + 0x4),-1000);
            *(float *)((*ppTVar5)[0x26] + 0x94) = 1.0;//something with text size
            *(float *)((*ppTVar5)[0x26] + 0x98) = 1.0;//^^
            *(char *)((long)(*ppTVar5) + 0x11b) = 0x1;
            *(char *)(*(long *)((*ppTVar5)[0x26] + 0x78) + 0x1af) = 0;
            outFuncs::FUN_710019d854(*(long *)((*ppTVar5)[0x26] + 0x78));
            outFuncs::UnkSetTextStyle(drawColor[0],drawColor[1],drawColor[2],1.0,*(long *)((*ppTVar5)[0x26] + 0x78));
            outFuncs::UnkEnemyLifeW2S(*(uint64_t*)DAT_7101cee300,drawPos,&unkF2,&unkF1,0,0,1);
            screenPos[0] = (scaledY / scaledX) * ((unkF1 * 2) / scaledY - 1.0);//useless?
            screenPos[1] = (unkF2 * 2) / scaledX - 1.0;//useless?
            screenPos[2] = 0;//useless?
            outFuncs::UnkEnemyLifeFunc((long)(*ppTVar5) + 0x20, screenPos);
            if(!string){
                outFuncs::swprintf((wchar_t *)formattedText,0x40,L"%.2f", damageDealt);
                outFuncs::CopyWideStringAndParse((*ppTVar5)[0x26],(wchar_t *)formattedText);
            }else{
                outFuncs::CopyWideStringAndParse((*ppTVar5)[0x26],(wchar_t *)string);
            }
            //outFuncs::CopyWideStringAndParse((*ppTVar5)[0x26],(wchar_t *)formattedText);
            *(char *)((long)(*ppTVar5) + 0x11b) = 0x1;
            
            for(int i = 0; i < menuEntriesMax; i++){
                if(menuText[i].ptr)// && *(float*)(menuText[i].ptr + 0x8))
                    continue;

                menuText[i].ptr = (int64_t)ppTVar5;
                menuText[i].offs[0] = drawPos[0] - g_Player->posX;
                menuText[i].offs[1] = drawPos[1] - g_Player->posY;
                return i;
            }
        }
    }

    return -1;
}

void givePlayerItems(){
    curItem = 0;
    curItemName = 0;
    itemNamesArray = *(uint64_t*)(g_BaseAddress+0x1c626c0 + (0x579D0 * g_Version));

    g_StaticPlayer = outFuncs::GetPlayerFromGM(*g_GameManager);
    if (g_StaticPlayer) {
        playerAeion = outFuncs::unk_302b54_func(g_StaticPlayer);
        if (playerAeion) {
            outFuncs::unk_a1d158_func(2200.0, playerAeion);
            outFuncs::unk_a1d258_func(2200.0, playerAeion, 0x0, 0x1);
        }
        plrHealthComp = g_StaticPlayer->healthComp;
        initplrHealthComp(plrHealthComp);
        if (plrHealthComp) {
            unkHealthCompFunc1(1099.0, plrHealthComp);
            unkHealthCompFunc(1099.0, plrHealthComp, 0x1);
        }
        g_StaticPlayerItems = *(uint64_t**)((uint64_t)g_StaticPlayer + 0x270);

        if (g_StaticPlayerItems) {
            for(int i = 0; i < 37; i++){
                if(g_Version)
                    curItem = *(int64_t*)(g_BaseAddress + itemOffsV21[i]);
                else
                    curItem = *(int64_t*)(g_BaseAddress + itemOffs[i]);
                curItemName = *(int64_t*)(curItem+0x10);

                if (!curItemName) {
                    outFuncs::givePlayerItem((curItem+0x10), curItem, itemNamesArray);
                }
                outFuncs::givePlayerItem2(itemVals[i], 0.0, g_StaticPlayerItems, (curItem+0x10), 0x1, 0x1, 0x1);
            }

            outFuncs::unk_dc47a0_func(*g_GameManager);
        }
    }
}

void handleFrameAdvance(){
    g_NPad.buttons = storeForFA;
    
    if(((g_ButtonState(HidNpadButton_Y) && g_ButtonState(HidNpadButton_A)) && g_ButtonState(HidNpadButton_Down)) || waitOne){
        //Advance one frame
        if(storeForWaitOne != (storeForFA))
            storeForWaitOne = storeForFA;
        
        if(ourFreeze || !waitOne){
            repeatInput = avoidRepeat;
            outFuncs::togglePause();
            waitOne = true;
            svcSleepThread(waitTime);
        } else {
            repeatInput = 10;
            outFuncs::togglePause();
            waitOne = false;
        }
    }
}

float lastPos[2] = {0};
float lastSkew = 0;
float lastVel[2] = {0};
float drawStyle[3] = {0.9, 0.0, 1.0};
float tabStyle[3] = {0.9, 0.0, 1.0};
const int8_t maxIndexes = 5;
int8_t infoIndexes[maxIndexes] = { -1 };
int menuTabTextIdx = -1;
int8_t currentTab = 0;
int8_t currentSubtab = -1;
bool entryUpdate = false;
wchar_t fancySubtext[64] = { 0 };
const wchar_t* fancyDivider = L"->";
size_t sizeOfDiv = wcslen(fancyDivider);
size_t sizeOfTitle;
size_t sizeOfSub;
void updateMenu() {
    if(menuTabs[1].tabToggled[2] && !isNoclip)
        ToggleNoclip();

    if(menuTabs[0].tabToggled[2] && g_Player)
        g_Player->healthComp->curHealth = g_Player->healthComp->maxHealth;

    g_Player->collisionComp->fullInvuln = menuTabs[0].tabToggled[4];//Invuln

    ignoreOobDeath = menuTabs[2].tabToggled[3];

    float drawPos[3] = {g_Player->posX,g_Player->posY, 60.0};
    if(lastPos[0] != g_Player->posX || lastPos[1] != g_Player->posY
    || lastSkew != g_Player->skew
    || lastVel[0] != g_Player->velX || lastVel[1] != g_Player->velY)
    {
        lastPos[0] = g_Player->posX;
        lastPos[1] = g_Player->posY;
        lastSkew   = g_Player->skew;
        lastVel[0] = g_Player->velX;
        lastVel[1] = g_Player->velY;
    }

    for(int idx = 0; idx < maxIndexes; idx++){//clear out currently drawn text
        if(infoIndexes[idx] == -1)
            continue;

        if(menuText[infoIndexes[idx]].ptr){
            if(*(float*)(menuText[infoIndexes[idx]].ptr + 0x8))
                *(float*)(menuText[infoIndexes[idx]].ptr + 0x8) = 0.0;
            menuText[infoIndexes[idx]].ptr = 0x0;
            infoIndexes[idx] = -1;
        }
    }

    if(menuTabs[4].tabToggled[3] || showMenu){//Always showing? or is menu open
        drawPos[0] = g_Player->posX;
        drawPos[1] = g_Player->posY;
        if(menuTabs[4].tabToggled[0]){
            infoIndexes[0] = drawTextOnScreen(lastPos[0], *g_floatText, drawPos, drawStyle, 0);
            drawPos[1] -= 25.0;
            infoIndexes[1] = drawTextOnScreen(lastPos[1], *g_floatText, drawPos, drawStyle, 0);
            drawPos[1] -= 25.0;
        }
        
        if(menuTabs[4].tabToggled[1]){
            infoIndexes[2] = drawTextOnScreen(lastSkew, *g_floatText, drawPos, drawStyle, 0);
            drawPos[1] -= 25.0;
        }
        
        if(menuTabs[4].tabToggled[2]){
            infoIndexes[3] = drawTextOnScreen(lastVel[0], *g_floatText, drawPos, drawStyle, 0);
            drawPos[1] -= 25.0;
            infoIndexes[4] = drawTextOnScreen(lastVel[1], *g_floatText, drawPos, drawStyle, 0);
            drawPos[1] -= 25.0;
        }
    }
    
    if(showMenu){
        if(menuText[menuTabTextIdx].ptr){
            if(*(float*)(menuText[menuTabTextIdx].ptr + 0x8))
                *(float*)(menuText[menuTabTextIdx].ptr + 0x8) = 0.0;
            menuText[menuTabTextIdx].ptr = 0x0;
            menuTabTextIdx = -1;
        }
        
        memset(fancySubtext, 0, (sizeof(wchar_t) * 64));
        if(currentSubtab == -1){
            sizeOfTitle = wcslen(menuTabs[currentTab].tabTitle);
            memcpy(fancySubtext, menuTabs[currentTab].tabTitle, sizeof(wchar_t) * sizeOfTitle);

            tabStyle[0] = menuTabs[currentTab].defaultColor[0];
            tabStyle[1] = menuTabs[currentTab].defaultColor[1];
            tabStyle[2] = menuTabs[currentTab].defaultColor[2];
        } else {
            sizeOfTitle = wcslen(menuTabs[currentSubtab].tabTitle);
            sizeOfSub = wcslen(menuTabs[currentSubtab].tabSubtitles[currentTab]);
            memcpy(fancySubtext, menuTabs[currentSubtab].tabTitle, sizeof(wchar_t) * sizeOfTitle);
            memcpy(&fancySubtext[sizeOfTitle], fancyDivider, sizeof(wchar_t) * sizeOfDiv);
            memcpy(&fancySubtext[(sizeOfTitle + sizeOfDiv)], menuTabs[currentSubtab].tabSubtitles[currentTab], (sizeof(wchar_t) * sizeOfSub) + 4);
            
            tabStyle[0] = menuTabs[currentSubtab].currentColor[0];
            tabStyle[1] = menuTabs[currentSubtab].currentColor[1];
            tabStyle[2] = menuTabs[currentSubtab].currentColor[2];
        }
        menuTabTextIdx = drawTextOnScreen(0.0, *g_floatText, drawPos, tabStyle, fancySubtext);
    }

    //Keep menu items alive and prevent floating, or destroy them if menu closed
    for(int i = 0; i < menuEntriesMax; i++){
        if(menuText[i].ptr){
            if(showMenu){
                *(float*)(menuText[i].ptr + 0xc) = g_Player->posX + menuText[i].offs[0];
                *(float*)(menuText[i].ptr + 0x10) = g_Player->posY + menuText[i].offs[1];

                if(*(float*)(menuText[i].ptr + 0x8))
                    *(float*)(menuText[i].ptr + 0x8) = 1.0;
            } else {
                if(menuTabs[4].tabToggled[3]){
                    if(menuTabTextIdx != -1){
                        if(menuText[menuTabTextIdx].ptr){
                            if(*(float*)(menuText[menuTabTextIdx].ptr + 0x8))
                                *(float*)(menuText[menuTabTextIdx].ptr + 0x8) = 0.0;
                            menuText[menuTabTextIdx].ptr = 0x0;
                            menuTabTextIdx = -1;
                        }
                    }
                } else {
                    *(float*)(menuText[i].ptr + 0x8) = 0.0;
                    menuText[i].ptr = 0x0;
                }
            }
        }
    }
    
    if(!showMenu){
        currentTab = 0;
        currentSubtab = -1;
        menuTabTextIdx = -1;
        memset(fancySubtext, 0, (sizeof(wchar_t) * 64));
    }
}

bool snapShotCreated = false;
char* snapshotID;
char* checkpointKey;
bool checkInputs(){
    //Store "Last Frames" inputs to make Frame Advance work
    storeForFA = comboButtons;

    if(isNoclip){
        noclipDif[0] += ((g_NPad.analog_stick_r.x * 40) / 0x7FFF);
        noclipDif[1] += ((g_NPad.analog_stick_r.y * 40) / 0x7FFF);
        
        g_Player->posX = noclipPos[0] + noclipDif[0];
        g_Player->posY = noclipPos[1] + noclipDif[1];
        if(g_Morph){
            g_Morph->posX = noclipPos[2] + noclipDif[0];
            g_Morph->posY = noclipPos[3] + noclipDif[1];
        }
    } else {
        noclipDif[0] = 0;
        noclipDif[1] = 0;
    }

    if(repeatInput >= 1){
        repeatInput--;
        return true;
    }

    if(showMenu){
        if(g_ButtonState(HidNpadButton_Up) || g_ButtonState(HidNpadButton_Down)){
            if(g_ButtonState(HidNpadButton_Up)){
                currentTab--;
                if(currentTab < 0){
                    if(currentSubtab != -1)
                        currentTab = (menuTabs[currentSubtab].tabEntriesMax) - 1;
                    else
                        currentTab = menuTabsMax - 1;
                }
            } else {
                currentTab++;
                if(currentSubtab != -1){
                    if(currentTab >= menuTabs[currentSubtab].tabEntriesMax)
                        currentTab = 0;
                } else {
                    if(currentTab >= menuTabsMax)
                        currentTab = 0;
                }
            }
            entryUpdate = true;
        }
        if(g_ButtonState(HidNpadButton_A)){
            if(currentSubtab == -1){
                currentSubtab = currentTab;
                currentTab = 0;
            } else {
                if(menuTabs[currentSubtab].tabTogglables[currentTab]){
                    menuTabs[currentSubtab].tabToggled[currentTab] = !menuTabs[currentSubtab].tabToggled[currentTab];
                } else {
                    switch(currentSubtab){
                        case(0):
                            switch(currentTab){
                                case(0):
                                    outFuncs::recoverPlayerLife();
                                    break;
                                case(1):
                                    outFuncs::recoverPlayerMissiles();
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case(1):
                            switch(currentTab){
                                case(0):
                                    SavePlayerPos(&telePos);
                                    break;
                                case(1):
                                    LoadPlayerPos(telePos);
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case(2):
                            switch(currentTab){
                                case(0):
                                    givePlayerItems();
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case(3):
                            switch(currentTab){
                                case(0):
                                    outFuncs::unk_dc47a0_func(*g_GameManager);
                                    break;
                                case(1):
                                    outFuncs::killPlayerFunc();
                                    break;
                                case(2):
                                    outFuncs::killAllEnemies();
                                    break;
                                case(3):
                                    outFuncs::killCurrentBoss();
                                    break;
                                case(4):
                                    outFuncs::killCurrentEmmi();
                                    break;
                                default:
                                    break;
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
            entryUpdate = true;
        }
        if(g_ButtonState(HidNpadButton_B)){
            if(currentSubtab != -1){
                currentTab = currentSubtab;
                currentSubtab = -1;
            } else {
                showMenu = false;
            }
            entryUpdate = true;
        }
        repeatInput = entryUpdate * 8;
        if(entryUpdate){
            if(currentSubtab != -1){
                menuTabs[currentSubtab].currentColor[0] = menuTabs[currentSubtab].defaultColor[0];
                menuTabs[currentSubtab].currentColor[1] = menuTabs[currentSubtab].defaultColor[1];
                menuTabs[currentSubtab].currentColor[2] = menuTabs[currentSubtab].defaultColor[2];
                if(menuTabs[currentSubtab].tabTogglables[currentTab]){
                    if(menuTabs[currentSubtab].tabToggled[currentTab]){
                        menuTabs[currentSubtab].currentColor[0] = menuTabs[currentSubtab].enableColor[0];
                        menuTabs[currentSubtab].currentColor[1] = menuTabs[currentSubtab].enableColor[1];
                        menuTabs[currentSubtab].currentColor[2] = menuTabs[currentSubtab].enableColor[2];
                    }
                }
            }
            return true;
        }
    }

    if(g_ButtonState(HidNpadButton_Up)){//Toggle Turbo
        turboButtons = !turboButtons;
        //testing

        //outFuncs::showGameFps(1);
        //outFuncs::killCurrentBoss(); //works
        //outFuncs::hideGameScenario(); //disables z flushing(?) like when out of bounds in a source game
        //outFuncs::TRntString256Ctor((uint64_t*)(g_BaseAddress + 0x1ff2000), (char*)"EDITOR");
        //outFuncs::ChangeGameMode((uint64_t*)(g_BaseAddress + 0x1c626b8), (uint64_t*)(g_BaseAddress + 0x1ff2000));
        
        repeatInput = 20;
        getCombo = true;
        comboButtons = 0;
        if(turboButtons){//delete testing shit later
            //outFuncs::showGameScenario(); //fixes z flushing
            svcSleepThread(waitTime);//Wait for a bit so the player can hold the button(s) they want turbo'd
        }
        return true;
    }

    if(g_ButtonXState(HidNpadButton_Right)){
        showMenu = !showMenu;
        if(showMenu){
            //justOpened = true;
        } else {
            currentTab = 0;
            currentSubtab = -1;
        }
        repeatInput = avoidRepeat;
        return true;
    }

    //if(g_ButtonXState(HidNpadButton_Left) && false){
    //    if(g_luaState && !snapShotCreated){
    //        outFuncs::SaveGameToSnapshotFunc(g_luaState, (char*)"amogus");
    //        snapShotCreated = true;
    //        repeatInput = 20;
    //        return true;
    //    }
    //    if(g_luaState && snapShotCreated){
    //        outFuncs::SaveSnapshotToCheckpointFunc(g_luaState, (char*)"amogus", (char*)"amoguscheck", "1", true);
    //        repeatInput = 20;
    //        return true;
    //    }
    //}

    if(g_ButtonState(HidNpadButton_R)){
        comboButtons = 0;
        
        if(g_ButtonState(HidNpadButton_Left)){
            comboButtons |= (HidNpadButton_R | HidNpadButton_Left);
            slomoSpeed -= 0.05;
            repeatInput = 5;
            outFuncs::setGameSpeed(slomoSpeed, 0, *g_GameManager);
            return true;
        }
        if(g_ButtonState(HidNpadButton_Right)){
            comboButtons |= (HidNpadButton_R | HidNpadButton_Right);
            slomoSpeed += 0.05;
            repeatInput = 5;
            outFuncs::setGameSpeed(slomoSpeed, 0, *g_GameManager);
            return true;
        }
        if(g_ButtonState(HidNpadButton_Minus)){
            comboButtons |= (HidNpadButton_R | HidNpadButton_Minus);
            slomoSpeed = 1;
            repeatInput = avoidRepeat;
            outFuncs::setGameSpeed(slomoSpeed, 0, *g_GameManager);
            return true;
        }
    }

    if(g_ButtonState(HidNpadButton_L) && !g_ButtonState(HidNpadButton_Down)){
        comboButtons = 0;
        if(g_ButtonState(HidNpadButton_Left)){
            comboButtons |= HidNpadButton_Left | HidNpadButton_L;
            
            repeatInput = 10;
            ToggleNoclip();
            return true;
        }
        if(g_ButtonState(HidNpadButton_Right)){
            if(isNoclip){
                LoadPlayerPos(noclipPos);
                isNoclip = false;
                menuTabs[1].tabToggled[2] = false;
                repeatInput = 10;
            }
            return true;
        }
        return false;
    }

    //If we arent trying to enter a combo or are using Frame Advance, don't listen and allow input
    if(!g_ButtonState(HidNpadButton_Down) || waitOne){
        comboButtons = 0;
        //if(g_luaState){
        //    outFuncs::setDebugMiniMap(g_luaState, true);
        //}
        return false;
    } else {
        comboButtons |= HidNpadButton_Down;
        comboButtons ^= HidNpadButton_Down;

        //If we are just holding DPAD Down still ignore inputs
        if(!g_ButtonXState(HidNpadButton_Down)){

            //Give All Items
            if(g_ButtonState(HidNpadButton_Plus)){
                givePlayerItems();
                repeatInput = avoidRepeat;
                return true;
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
                menuTabs[2].tabToggled[3] = ignoreOobDeath;
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
                    SavePlayerPos(&telePos);
                    repeatInput = avoidRepeat;
                    return true;
                }

                if(g_ButtonState(HidNpadButton_R)){
                    //Tele to saved pos
                    if(telePos[0] && telePos[1])
                        LoadPlayerPos(telePos);
                    repeatInput = avoidRepeat;
                    return true;
                }
            }

            //Tele to map cursor, TODO add a check for in menu
            if(g_ButtonState(HidNpadButton_R) && g_ButtonState(HidNpadButton_ZR)){
                float tempPos[4] = {mapCursorPos[0], mapCursorPos[1], mapCursorPos[0], mapCursorPos[1]};
                LoadPlayerPos(tempPos);
                repeatInput = avoidRepeat;
                return true;
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
                storeForWaitOne = 0;

                repeatInput = avoidRepeat;
                comboButtons |= (HidNpadButton_X | HidNpadButton_A);//Just in case
                
                return false;
            }
        }
    }
    return false;
}

void ToggleNoclip(){
    isNoclip = !isNoclip;
    menuTabs[1].tabToggled[2] = isNoclip;
    if(isNoclip){
        repeatInput = avoidRepeat;
        SavePlayerPos(&noclipPos);
    }
    return;
}

void SavePlayerPos(float (*arr)[4]){
    (*arr)[0] = g_Player->posX;
    (*arr)[1] = g_Player->posY;
    if(g_Morph){
        (*arr)[2] = g_Morph->posX;
        (*arr)[3] = g_Morph->posY;
    }
}

void LoadPlayerPos(float arr[4]){
    if(g_Player){
        g_Player->posX = arr[0];
        g_Player->posY = arr[1];
    }
    if(g_Morph){
        g_Morph->posX = arr[2];
        g_Morph->posY = arr[3];
    }
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
        } else if(comboButtons){
            comboButtons ^= HidNpadButton_Down;//Remove DPAD Down
            state->buttons ^= comboButtons;//XOR combo buttons to ignore them
            state->buttons ^= HidNpadButton_Down;//Reset DPAD Down
            comboButtons = 0;
        }
    }

    if(turboButtons && !ignoreCombo) {
        if(turboSwitcher)
            state->buttons &= ~turboCombo;
        turboSwitcher = !turboSwitcher;
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
        mapCursorPos[0] = *(float*)(param1 + 0x134);//X
        mapCursorPos[1] = *(float*)(param1 + 0x138);//Y
        mapCursorPos[2] = *(float*)(param1 + 0x13C);//Z?

        Orig(param1);
    };
};

HOOK_DEFINE_TRAMPOLINE(InstantSpeedBooster){//Instant Charge.
    static void Callback(uintptr_t speedboosterInst){
        g_SpeedBooster = speedboosterInst;

        float SpeedThreshhold = *(float*)(g_BaseAddress + tunableOffs.SpeedThreshold);//derived from the Tunable

        if(speedboosterInst && setInstantSpeed){//Is Speed Booster Instance Valid and are we using it.
            if(*(u8*)(speedboosterInst+0x394) == 1){//Is Speed Booster Charging?
                *(float*)(speedboosterInst+0x398) = SpeedThreshhold;//Set Speed Booster Time
            }
        }
        
        Orig(speedboosterInst);
    };
};

HOOK_DEFINE_TRAMPOLINE(IgnoreSubAreaDeaths){
    static void Callback(uintptr_t EntityInst){
        if(!(ignoreOobDeath | isNoclip | menuTabs[2].tabToggled[3])){
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

HOOK_DEFINE_TRAMPOLINE(UpdatePlayerPawn){//includes all moving entites
    static void Callback(long* Player, long* unkNewPos, ulong param3){
        //if(!setFps){
        //    setFps = (uint64_t*)((**(uintptr_t**)(g_BaseAddress + 0x1c62718 + (0x57A08 * g_Version))) + 0x38);
        //    frameRate(45);
        //}

        if((Player + 7) != unkNewPos){
            if(Player && !g_Player){
                g_Player = (CEntity*)Player;
            } else if(g_Player && !g_Morph)
                if(*g_GameManager)
                    if(outFuncs::GetPlayerFromGM(*g_GameManager) != g_Player)
                        g_Morph = outFuncs::GetPlayerFromGM(*g_GameManager);
        }

        if((g_Player && g_Player->unkState2 && !ILallowTp) || !g_Morph){
            ILallowTp = true;
            ignoreCycles = 5;
        }

        if(ILallowTp || ignoreCycles){
            ignoreCycles--;
            if(ignoreCycles <= 0){
                ignoreCycles = 0;
                ILallowTp = false;
            }
        }

        Orig(Player, unkNewPos, param3);
        updateMenu();

        return;
    };
};

HOOK_DEFINE_TRAMPOLINE(RoomTransitionUnk){
    static void Callback(int64_t* Player, float* unkNewPos, uint64_t param3){
        if(unkNewPos && ((int64_t*)g_Player == Player) && ILallowTp) {

            if(!ILonce){
                roomIL[0] = unkNewPos[0];
                roomIL[1] = unkNewPos[1];
                roomIL[2] = unkNewPos[2];
                ILonce = true;
            }

            if(!ILnext){
                finishIL[0] = unkNewPos[0];
                finishIL[1] = unkNewPos[1];
                finishIL[2] = unkNewPos[2];
                ILnext = true;
            }
            
            if((ILreset && ILallowTp) || ILForce || ILGauntlet) {
                if((roomIL[0] && !ILGauntlet) || ILForce)
                    return Orig(Player, roomIL, param3);

                if(finishIL[0])
                    if(((unkNewPos[0] - finishDelta) < finishIL[0]) && (finishIL[0] < (unkNewPos[0] + finishDelta)))
                        if(((unkNewPos[1] - 50) < finishIL[1]) && (finishIL[1] < (unkNewPos[1] + 50)))
                            return Orig(Player, roomIL, param3);
            }
        }
        Orig(Player, unkNewPos, param3);
    };
};

HOOK_DEFINE_TRAMPOLINE(lua_gettop){
    static int Callback(uint64_t* LuaState){
	    if (LuaState) {
	    	if (*LuaState) {
                if(!g_luaState)
                    g_luaState = LuaState;
        
	    		return Orig(LuaState);
	    	}
	    }
        return Orig(LuaState);
    };
};

//gravity doesnt protect, varia does tho? gives you all beam damage bonus but not the actual beams.
//diffusion shows the wave particles, cant use the supposedly unlocked aeion abilities or speed.
//gives you omega cannon but no stream.
HOOK_DEFINE_TRAMPOLINE(spoofAllAbilities){
    static bool Callback(int64_t param1, int64_t* param2){
        //Orig(param1, param2);
        return true;
    };
};

bool setOnce = false;
HOOK_DEFINE_TRAMPOLINE(SetupDebugMode){
    static void Callback(){
        Orig();
        if(!setOnce){
            if(g_Version){
                //*(u8*)(g_BaseAddress + 0x1d473c0) = 1;
                //*(u8*)(g_BaseAddress + 0x1d473c1) = 1;
            } else {
                //*(u8*)(g_BaseAddress + 0x1cee3c0) = 1;//GiveAllItems on start
                *(u8*)(g_BaseAddress + 0x1cee3c1) = 1;//DebugStart
                //*(u8*)(g_BaseAddress + 0x1cee3c2) = 1;//
                //*(u8*)(g_BaseAddress + 0x1cee3c3) = 1;//
                //*(u8*)(g_BaseAddress + 0x1c9c1d0) = 1;//
                
                //*(float*)(g_BaseAddress + 0x1cee3b0) = 1.0;
                //*(float*)(g_BaseAddress + 0x1cee3b4) = 1.0;

                outFuncs::TRntString256Ctor((uint64_t*)(g_BaseAddress + 0x1cee3c8), (char*)"c10_samus");//World
                outFuncs::TRntString256Ctor((uint64_t*)(g_BaseAddress + 0x1cee3f8), (char*)"s010_cave");//Scenario
                outFuncs::TRntString256Dtor((uint64_t*)(g_BaseAddress + 0x1cee428));
                outFuncs::TRntString256Ctor((uint64_t*)(g_BaseAddress + 0x1cee428), (char*)"samus");//Player
                outFuncs::TRntString256Dtor((uint64_t*)(g_BaseAddress + 0x1cee458));
                outFuncs::TRntString256Ctor((uint64_t*)(g_BaseAddress + 0x1cee458), (char*)"PRP_CV_AccessPoint001_WeightPlate");//StartPoint
            }
            setOnce = true;
        }
    };
};

HOOK_DEFINE_TRAMPOLINE(IgnoreUpdatePlayer){
    static void Callback(long* param1, long* param2, uint64_t param3){
        if(showMenu && param1 != (long*)g_Player && param1 != (long*)g_Morph)
            param1 = param2 + 0x38;

        Orig(param1, param2, param3);
    };
};

HOOK_DEFINE_TRAMPOLINE(IgnorePlayerContact){
    static ulong Callback(long* param1, long* param2){
        //Orig(param1, param2);
        return 6;
    };
};

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking enviroment. */
    exl::hook::Initialize();
    initExternFuncs(g_BaseAddress, g_Version);

    //SaveSnapShotToCheckpointLua? 7101036ea0(und8 unkParam1)
    //setFrameRateLua? 710103efb0(und8 unkParam1)
    //EnableDebugMinimap 71010534a0(bool param1)

    DisableFullKeyState::InstallAtSymbol("_ZN2nn3hid12GetNpadStateEPNS0_16NpadFullKeyStateERKj");
    DisableHandheldState::InstallAtSymbol("_ZN2nn3hid12GetNpadStateEPNS0_17NpadHandheldStateERKj");

    //IgnorePlayerContact::InstallAtOffset(0x1122640);
    //spoofAllAbilities::InstallAtOffset(0x110075c);
    IgnoreUpdatePlayer::InstallAtOffset(0x232bec);
    SetupDebugMode::InstallAtOffset(0x1760);
    GetMapCursor::InstallAtOffset(0x1b9f44 + (0x430 * g_Version));//+0x430
    IgnoreSubAreaDeaths::InstallAtOffset(0xea4e68 + (0x40720 * g_Version));//0x40720
    InstantSpeedBooster::InstallAtOffset(0x33ee94 + (0x868 * g_Version));//0x868
    ForceCoolSpark::InstallAtOffset(0x32e798 + (0x638 * g_Version));//+0x638
    UpdatePlayerPawn::InstallAtOffset(0x232bec + (0x490 * g_Version));//0x490
    RoomTransitionUnk::InstallAtOffset(0xd6a5a0 + (0x12B00 * g_Version));//0x12B00
    lua_gettop::InstallAtOffset(0x105eb80 + (0xDEAD * g_Version));

}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}