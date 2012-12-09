
#include "CApp.h"

CApp* APP = NULL;

CApp::CApp() {
	Surf_Display = NULL;
	Surf_Background = NULL;

	font = NULL;
	texte = NULL;

    Running = true;
}
 
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }
 
    SDL_Event Event;
 
    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
 
        OnLoop();
        OnRender();
    }
 
    OnCleanup();
 
    return 0;
}

SDL_Surface* getBackground()
{
	return APP->Surf_Background;
}

TTF_Font* getFont()
{
	return APP->font;
}

int main(int argc, char* argv[]) {
    CApp theApp;
	APP = &theApp;
    return theApp.OnExecute();
}