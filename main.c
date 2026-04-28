#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "game.h"

//ligne de compilation gcc main.c file.c game.c event.c charactere.c -o mario -lSDL2main -lSDL2_image -lSDL2

int init(SDL_Window **window, SDL_Renderer **renderer, int w, int h);

int main(int argc, char *argv[])
{
    if ( SDL_Init ( SDL_INIT_VIDEO ) < 0)
{
        // gestion de l ’ erreur avec SDL
        SDL_Log (" Erreur ␣ SDL_Init ␣ : ␣ %s " , SDL_GetError ());
        return EXIT_FAILURE ;
}
    // creation d ’ un renderer et d ’ une fenetre
    SDL_Window * window = NULL ;
    SDL_Renderer * renderer = NULL ;
    if (0 != SDL_CreateWindowAndRenderer(500 , 500 , SDL_WINDOW_SHOWN, &window , &renderer ))
{

        fprintf (stderr , " Erreur ␣ SDL_CreateWindowAndRenderer␣:␣ %s " ,
            SDL_GetError ());
        return -1;
}


SDL_Delay(2000);
    return 0;
}

