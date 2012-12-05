
#include "CFont.h"
 
CFont::CFont() {
}
 
TTF_Font* CFont::OnLoad(char* File, int ptsize) {
    TTF_Font* Surf_Return = NULL;
 
    if((Surf_Return = TTF_OpenFont(File, ptsize)) == NULL) {
        return NULL;
    }

    return Surf_Return;
}


bool CFont::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }
 
    SDL_Rect DestR;
 
    DestR.x = X;
    DestR.y = Y;
 
    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);
 
    return true;
}