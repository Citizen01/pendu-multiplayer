#ifndef _CAPP_H_
    #define _CAPP_H_
 
#include <SDL.h>
#include <SDL_ttf.h>
 
#include "CEvent.h"
#include "CSurface.h"
 
class CApp : public CEvent {
    private:
        bool            Running;
 
        SDL_Surface*    Surf_Display;
        SDL_Surface*    Surf_Background;

		TTF_Font *font;
		SDL_Surface*    texte;



 
    public:
        CApp();
 
        int OnExecute();
 
    public:
        bool OnInit();
 
        void OnEvent(SDL_Event* Event);
 
        void OnExit(); 
 
        void OnLoop();
 
        void OnRender();
 
        void OnCleanup();
};
 
#endif