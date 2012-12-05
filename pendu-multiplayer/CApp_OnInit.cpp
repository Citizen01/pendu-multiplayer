
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

	if((font = TTF_OpenFont("media/fonts/mvboli.ttf", 22)) == NULL) {
        return false;
    }

    return true;
}