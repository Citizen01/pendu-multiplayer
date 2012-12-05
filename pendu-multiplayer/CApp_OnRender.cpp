
#include "CApp.h"
 
void CApp::OnRender() {
	CSurface::OnDraw(Surf_Display, Surf_Background, 0, 0);

 
    SDL_Flip(Surf_Display);
}