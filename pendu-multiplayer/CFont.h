
#ifndef _CFONT_H_
    #define _CFONT_H_
 
#include <SDL.h>
#include <SDL_ttf.h>
 
class CFont {
    public:
        CFont();
 
    public:
        static TTF_Font* OnLoad(char* File, int ptsize);
 
        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
};
 
#endif
