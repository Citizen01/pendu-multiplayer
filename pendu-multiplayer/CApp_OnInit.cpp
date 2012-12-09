
#include "CApp.h"
 
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
 
    if((Surf_Display = SDL_SetVideoMode(960, 696, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

	if((Surf_Background = CSurface::OnLoad("media/images/background.png")) == NULL) {
        return false;
    }

	if(TTF_Init() == -1)
	{
		return false;
	}

	if((font = TTF_OpenFont("media/fonts/mvboli.ttf", 30)) == NULL) {
        return false;
    }

	if(Entity1.OnLoad("media/images/yoshi.bmp", 64, 64, 8) == false) {
		return false;
	}
 
	if(Entity2.OnLoad("media/images/yoshi.bmp", 64, 64, 8) == false) {
		return false;
	}
 
	Entity2.X = 100;

	CLabel myLabel(100, 80, "test", 0, 0, 0);
	CLabel myLabel2(100, 400, "This is a fucking test", 0, 0, 0);
	printf("lol");

	CEntity::EntityList.push_back(&Entity1);
	CEntity::EntityList.push_back(&Entity2);

		return true;
	}