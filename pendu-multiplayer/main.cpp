#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <fmod.h>

#include "constantes.h"
 
int main(int argc, char *argv[])
{
	SDL_Surface *ecran = NULL, *background = NULL;
	SDL_Rect positionBackground;
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetIcon(IMG_Load("media/images/icone.png"), NULL); // L'icône doit être chargée avant SDL_SetVideoMode
	ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Pendu Evolution", NULL);
	background = IMG_Load("media/images/background.png");

	
	SDL_Event event;
	int continuer = 1;
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE: // Veut arrêter le jeu
						continuer = 0;
						break;
					case SDLK_KP1: // Demande à jouer
						break;
					case SDLK_KP2: // Demande l'éditeur de niveaux
						break;
				}
				break;
		}

		// Effacement de l'écran
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		SDL_BlitSurface(background, NULL, ecran, &positionBackground);
		SDL_Flip(ecran);
	}

	SDL_FreeSurface(background);
	SDL_Quit();

	return EXIT_SUCCESS;
}