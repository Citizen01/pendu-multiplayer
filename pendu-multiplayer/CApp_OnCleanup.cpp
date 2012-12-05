
#include "CApp.h"
 
void CApp::OnCleanup() {
	TTF_CloseFont(font);
	TTF_Quit();
	
	SDL_FreeSurface(Surf_Background);
	SDL_FreeSurface(Surf_Display);

	
    SDL_Quit();
}