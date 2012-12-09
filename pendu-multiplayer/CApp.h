#ifndef _CAPP_H_
    #define _CAPP_H_
 
#include <SDL.h>
#include <SDL_ttf.h>

#include "CLabel.h"
#include "CEntity.h"
#include "CAnimation.h"
#include "CEvent.h"
#include "CSurface.h"
 
class CApp : public CEvent {
    private:
        bool            Running;
 
        SDL_Surface*    Surf_Display;
        SDL_Surface*    Surf_Background;

		TTF_Font *font;
		SDL_Surface*    texte;

		CEntity         Entity1;
		CEntity         Entity2;
 

	public:
		friend SDL_Surface* getBackground();
		friend TTF_Font* getFont();


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