#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_net.h>
#include <SDL_ttf.h>
#include <fmod.h>
 
int main(int argc, char *argv[])
{
    IPaddress ip, *ipadd;
    TCPsocket tcpserveur, tcpsocket;
    char buf[1024];
    unsigned int result;

    if(SDL_Init(SDL_INIT_TIMER) != 0) {
        fprintf(stderr, "Erreur d'initialisation\n");
        return EXIT_FAILURE;
    }

    if(SDLNet_Init() != 0) {
        fprintf(stderr, "Erreur d'initialisation de SDL_Net\n");
        return EXIT_FAILURE;
    }

	/* Creation du serveur */
    if(SDLNet_ResolveHost(&ip,NULL,12345) != 0) {
        printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
        return EXIT_FAILURE;
    }

    tcpserveur = SDLNet_TCP_Open(&ip);

    if(tcpserveur == NULL) {
        fprintf(stderr, "Erreur d'initialisation de la socket\n");
        return EXIT_FAILURE;
    }

	 /* On accepte un client */
    printf("En attente\n");
    tcpsocket = SDLNet_TCP_Accept(tcpserveur);
    while(tcpsocket == NULL) {
        SDL_Delay(1000);
        tcpsocket = SDLNet_TCP_Accept(tcpserveur);
    }

	ipadd = SDLNet_TCP_GetPeerAddress(tcpsocket);

    if(ipadd != NULL) {
        printf("Client connecte : %s\n", SDLNet_ResolveIP(ipadd));
    }

	while(fgets(buf, sizeof(buf), stdin) != NULL) {
        /* Si c'est une ligne vide */
        if(strlen(buf) <= 1) {
            break;
        }

        /* Envoi de ce message */
        result = SDLNet_TCP_Send(tcpsocket, buf, sizeof(buf));

        if(result < sizeof(buf)) {
            break;
        }

        /* On recoit l'accuse de reception */
        result = SDLNet_TCP_Recv(tcpsocket, buf, sizeof(buf));

        if(result < sizeof(buf)) {
            break;
        }
    }

	SDLNet_TCP_Close(tcpsocket);
    SDLNet_TCP_Close(tcpserveur);

    SDLNet_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}