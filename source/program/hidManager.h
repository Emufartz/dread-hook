//Input stuff
#include "../switch/runtime/pad.h"

using nn::hid

namespace hidManager {
	bool getPadButtonDown(HidNPadCommonState inState, ){


		return false;
	}

	void UpdateNpadP1(){
		if(npadIdP1){
			NpadStyleSet padStyle = GetNpadStyleSet(0);
	
			if(padStyle != HidNpadIdType::HidNpadIdType_Handheld && padStyle != HidNpadIdType::HidNpadIdType_No1)
				return;


			
		}
	}
};