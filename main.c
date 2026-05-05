#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "game.h"

//ligne de compilation gcc main.c file.c game.c event.c charactere.c -o mario -lSDL2main -lSDL2_image -lSDL2

int init(SDL_Window **window, SDL_Renderer **renderer, int w, int h);

int main(int argc, char *argv[]){
    if ( SDL_Init ( SDL_INIT_VIDEO ) < 0)
{
        // gestion de l ’ erreur avec SDL
        SDL_Log (" Erreur ␣ SDL_Init ␣ : ␣ %s " , SDL_GetError ());
        return EXIT_FAILURE ;
}
    // creation d ’ un renderer et d ’ une fenetre
    SDL_Window * window = NULL ;
    SDL_Renderer * renderer = NULL ;
    if (0 != SDL_CreateWindowAndRenderer(1000 , 1000 , SDL_WINDOW_SHOWN, &window , &renderer ))
{

        fprintf (stderr , " Erreur ␣ SDL_CreateWindowAndRenderer␣:␣ %s " ,
            SDL_GetError ());
        return -1;
    
    
}

        SDL_Texture *textureMenu = loadImage("img/menu.jpg" ,renderer);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,textureMenu,NULL,NULL);
        SDL_RenderPresent(renderer);


    int continuer = 1;
    SDL_Event events;

    while(continuer){ //coeur du jeu ici, les actions seront repété pour faire le déplacement des différentes images, ...
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN : // on a appuye sur une touche
                switch ( events.key.keysym.sym) // liste des touches a p p u y
                {
                    case SDLK_1 :
                        jouer(renderer);
                        break;
                        // on a appuye sur la touche 1
                    case SDLK_2 :
                        SDL_RenderClear(renderer);
                        SDL_Texture *textureMenu = loadImage("img/goomba1.png" ,renderer);
                        SDL_RenderCopy(renderer,textureMenu,NULL,NULL);
                        SDL_RenderPresent(renderer);
                        break;

                }
				
            }
        }
    }
    return 0;
}

