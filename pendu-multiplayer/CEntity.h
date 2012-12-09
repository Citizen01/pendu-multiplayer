
#include <vector>
 
#include "CAnimation.h"
#include "CSurface.h"
 
class CEntity {
    public:
        static std::vector<CEntity*>    EntityList;
 
    protected:
        CAnimation      Anim_Control;
 
        SDL_Surface*    Surf_Entity;
 
    public:
        float           X;
        float           Y;
 
        int             Width;
        int             Height;
 
        int             AnimState;
 
    public:
        CEntity();
 
        virtual ~CEntity();
 
    public:
        virtual bool OnLoad(char* File, int Width, int Height, int MaxFrames);
 
        virtual void OnLoop();
 
        virtual void OnRender(SDL_Surface* Surf_Display);
 
        virtual void OnCleanup();
};