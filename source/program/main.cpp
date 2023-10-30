//TODO add toggles for infinite missiles health etc, add toggles for invulns and other misc flags.

#include "main.h"

int64_t unkItem = 0;
int64_t unkItem2 = 0;
int64_t unkItem10 = 0;
int64_t unkDat = 0;
int64_t unkDat2 = 0;
uint64_t unkDat3 = 0;
int64_t lVar1 = 0;
uint64_t lVar2 = 0;
int64_t* plVar3 = 0;
float thisItemVal = 0;

void duplicateGiveAllItems(){
    unkItem = 0;
    unkItem2 = 0;
    unkItem10 = 0;
    unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
    unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
    unkDat3 = *(*(uint64_t**)(g_BaseAddress+0x1c626b8));
    //unkItem = dwadwa *(int64_t*)(g_BaseAddress+0x1caf988); old
    //unkDat = (g_BaseAddress + 0x1cee0e0);
    //unkDat2 = *(int64_t*)(g_BaseAddress + 0x1cee108);
    //unkDat3 = *(int64_t**)(g_BaseAddress + 0x1cee310);

    lVar1 = outFuncs::unk_db2798_func(unkDat3);
    if (lVar1) {
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

        //unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
        //unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
        //unkDat3 = *(*(uint64_t**)(g_BaseAddress+0x1c626b8));

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
if(false){
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(799.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(0.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);//not sure
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1000, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);//not sure
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1000, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1000, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1000, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(150, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(150, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(10, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(10, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
//            
//            unkItem = *(int64_t*)(g_BaseAddress+0x1caf000 + itemOffs[]);
//            unkItem2 = *(int64_t*)(unkItem+0x10);
//            unkDat = *(uint64_t*)(g_BaseAddress+0x1c626c0);
//            unkDat2 = *(*(uint64_t**)(g_BaseAddress+0x1c62698));
//
//            if (unkItem == unkDat2+0x10) {
//                outFuncs::givePlayerItem(unkItem+0x10, unkItem, unkDat);
//            }
//            outFuncs::givePlayerItem2(1.0, 0.0, lVar1, (unkItem+0x10), 0x1, 0x1, 0x1);
}
            outFuncs::unk_dc47a0_func(unkDat3);
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
        if(!waitOne){
            return true;
        }
    }

    if(g_ButtonState(HidNpadButton_Up)){//Toggle Turbo
        turboButtons = !turboButtons;
        //testing

        //outFuncs::givePlayerAllItems(); //works, 7 tanks, 150 missiles, and everything else except power bombs and hyper beam
        //outFuncs::showGameFps(); //does nothing?
        //outFuncs::killPlayerFunc(); //works
        //duplicateGiveAllItems(); //doesnt really work right now, lots of undefined reads so probably a bad typedef'd arg
        //outFuncs::setCheater(); //does nothing?
        //outFuncs::killCurrentEmmi(); //works
        //if(g_luaState)
        //    outFuncs::makePlayerInvincible(g_luaState);
        //outFuncs::killAllEnemies(); //works

        //set fps works
        //uint64_t* setFps = (uint64_t*)((**(uintptr_t**)(g_BaseAddress + 0x1c62718)) + 0x38);
        //*setFps = (uint64_t)(1000.0 / 30.0);
        
        //outFuncs::hideGameScenario(); //disables z flushing(?) like when out of bounds in a source game

        //if(g_luaState)
        //    outFuncs::isGamePaused(g_luaState);

        repeatInput = 20;
        getCombo = true;
        comboButtons = 0;
        if(turboButtons){//delete testing shit later
            //outFuncs::showGameScenario(); //fixes z flushing
            //*setFps = (uint64_t)(1000.0 / 60.0);
            svcSleepThread(waitTime);//Wait for a bit so the player can hold the button(s) they want turbo'd
        }
        return true;
    }

    if(g_ButtonState(HidNpadButton_L)){
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

    if(!g_ButtonState(HidNpadButton_Down) && !waitOne){//If we arent trying to enter a combo then obviously dont listen and allow input
        comboButtons = 0;
        return false;
    } else {
        comboButtons |= HidNpadButton_Down;
        comboButtons ^= HidNpadButton_Down;

        if(!g_ButtonXState(HidNpadButton_Down) && !waitOne){//If we are holding more than just DPAD Down

            if(g_ButtonState(HidNpadButton_Minus)){
                //Fill missiles and health
                outFuncs::recoverPlayerLife();
                outFuncs::recoverPlayerMissiles();
                repeatInput = avoidRepeat;
                return true;
            }

            if(g_ButtonState(HidNpadButton_StickL)){
                //Toggle OOB Ignore
                ignoreOobDeath = !ignoreOobDeath;
                repeatInput = avoidRepeat;
                return true;
            }

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
            if(g_ButtonState(HidNpadButton_X) && g_ButtonState(HidNpadButton_A) && !waitOne){
                //Toggle Freeze Time
                outFuncs::togglePause();

                //*(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea) = !*(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea);
                //ourFreeze = (!ourFreeze & *(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea));
                
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
                //state->analog_stick_l = (HidAnalogStickState)0;
                //state->analog_stick_r = (HidAnalogStickState)0;
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
            
            if(ourFreeze || *(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea) || !waitOne){
                //*(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea) = false;
                repeatInput = avoidRepeat;
                outFuncs::togglePause();
                waitOne = true;
                svcSleepThread(waitTime);
            }
            else{
                //*(bool*)(g_PlayerPawn+playerOffs.notUpdate3dArea) = true;
                repeatInput = 10;
                outFuncs::togglePause();
                waitOne = false;
            }
        }


        Orig(param1);
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

HOOK_DEFINE_TRAMPOLINE(GrabLuaState){
    static void Callback(int64_t param1){
        g_luaState = param1;
        return Orig(param1);
    };
};

HOOK_DEFINE_TRAMPOLINE(doSetSlomo){
    static void Callback(float param1, int64_t param2){
        if(forceCSpark)
            param1 = 0.3;

        Orig(param1, param2);
    };
};

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking enviroment. */
    exl::hook::Initialize();

    initExternFuncs();

    DisableFullKeyState::InstallAtSymbol("_ZN2nn3hid12GetNpadStateEPNS0_16NpadFullKeyStateERKj");
    DisableHandheldState::InstallAtSymbol("_ZN2nn3hid12GetNpadStateEPNS0_17NpadHandheldStateERKj");
    
    //HideScenario void 0x1041010(void)
    //ShowScenario void 0x1040fe0(void)
    //DEBUG_TESTMakePlayerInvulnerable 710103e0e0(und8 unkParam1)
    //SaveSnapShotToCheckpointLua? 7101036ea0(und8 unkParam1)
    //setFrameRateLua? 710103efb0(und8 unkParam1)
    //ShowFps 710103dfe0(void) no worky
    //RecoverPlayerLifeLua 710103ec60(void) works
    //KillEmmiLua 710103e300(void) works
    //KillAllEnemiesLua 710103e1f0(void) works
    //KillCurrentBossLua 710103e3f0(void) untested
    //TogglePauseLua? 7101036210(void) works
    //KillCurrentPlayer? 710103e1a0 works
    //GainAllItemsAndPowerups? 7101038c10(void) works
    //EnableDebugMinimap 71010534a0(lua_state)
    //SetIAmACheater 7101054de0(void) nothing?

    //doSetSlomo::InstallAtOffset(0xdbccd8); works but havent implemented fully
    //GrabLuaState::InstallAtOffset(0x103c780); I'll hook gettop or something soon
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