
#include "CApp.h"
 
void CApp::OnCleanup() {
	TTF_CloseFont(font);
	TTF_Quit();

	for(int i = 0;i < CEntity::EntityList.size();i++) {
		if(!CEntity::EntityList[i]) continue;
 
		CEntity::EntityList[i]->OnCleanup();
	}
 
	CEntity::EntityList.clear();
	
	SDL_FreeSurface(Surf_Background);
	SDL_FreeSurface(Surf_Display);

	
    SDL_Quit();
}