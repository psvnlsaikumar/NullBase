

#include "Includes.h"

//Flags
#define FL_ON_GROUND                     257
#define FL_ON_GROUND_CROUCHED             263
#define FL_IN_AIR_STAND                    256
#define FL_IN_AIR_MOVING_TO_STAND         258
#define FL_ON_GROUND_MOVING_TO_STAND     259
#define FL_IN_AIR_MOVING_TO_CROUCH         260
#define FL_ON_GROUND_MOVING_TO_CROUCH     261
#define FL_IN_AIR_CROUCHED                 262
#define FL_IN_WATER                     1280
#define FL_IN_PUDDLE                     1281
#define FL_IN_WATER_CROUCHED             1286
#define FL_IN_PUDDLE_CROUCHED             1287
#define FL_PARTIALGROUND (1 << 18)

//Team IDs
#define TEAM_ID_GOTV 1
#define TEAM_ID_T 2
#define TEAM_ID_CT 3

void bhop()
{
	//If we're holding space and the we're on the ground
	if (GetAsyncKeyState(VK_SPACE) && LocalPlayer::getLocalFlags() == FL_ON_GROUND)
	{
		//Jump!
		LocalPlayer::forceJump();
	}
}

void trigger() {
	auto crosshair = LocalPlayer::getLocalCrossID();
	if (crosshair > -1) { 
		auto insideCross = Entity::getEntBase(crosshair - 1);
		if (Entity::getEntTeam(insideCross) != LocalPlayer::getLocalTeam()) {
			
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			Sleep(10);  //was 10
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
	}
}

int main()
{
	init();
	LocalPlayer::setLocalPlayer();
	
	while (!GetAsyncKeyState(VK_F10))
	{
		//bhop();
		trigger();
		//Sleep(10); //uncomment for normal
	}

	//Close handle to csgo.exe to prevent memory leaks
	CloseHandle(hProc);
}
