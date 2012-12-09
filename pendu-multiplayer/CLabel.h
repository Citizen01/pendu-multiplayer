

#ifndef _CLABEL_H_
    #define _CLABEL_H_
 
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_TTF.h>
#include <vector>
#include <string>

 
class CLabel {
	private:
		static std::vector<CLabel> labels;

		SDL_Surface* Surf_Label;
		SDL_Rect position;
		std::string text;
		SDL_Color color;
		TTF_Font* font;


	public:
        CLabel(int X=0, int Y=0, std::string text="", int R=0, int G=0, int B=0);
		~CLabel();
 
        /*static SDL_Surface* createLabel(int X, int Y, std::string text);
		static bool destroyLabel();

		SDL_Rect getPosition();
		static bool setPosition(int X, int Y);

		std::string getText();
		static bool setText(std::string text);*/

        static bool renderLabels();
};
 
#endif
