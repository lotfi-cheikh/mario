
#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"

int jouer(SDL_Renderer* renderer) {
    
	//charger image et personnage. 

    Personnage mario;
    chargerMario(&mario, 0,renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //on met le fond en blanc
    int continuer = 1;
    SDL_Event events;

    while(continuer){ //coeur du jeu ici, les actions seront repété pour faire le déplacement des différentes images, ...
        SDL_RenderClear(renderer); //efface le rendu précédent
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
                    case SDLK_LEFT :
                        mario.direction=2;
                        break;
                        // on a appuye sur la touche 1
                    case SDLK_RIGHT :
                        mario.direction=1;
                        break;
                    case SDLK_UP:
                        mario.jump=1;
                        break;

                }
                break;
                case SDL_KEYUP : // on a appuye sur une touche
                switch ( events.key.keysym.sym) // liste des touches a p p u y
                {
                    case SDLK_LEFT :
                        mario.dernieredirection=2;
                        mario.direction=0; 
                        break;
                        // on a appuye sur la touche 1
                    case SDLK_RIGHT :
                        mario.dernieredirection=1;
                        mario.direction=0;
                        break;

                }
                break;	
            }
            
        }
        
        deplacement(0, &mario, 0, 0, 0);
		//on gère les divers events.
		afficherPerso(&mario, 0, 0 ,renderer);
        SDL_RenderPresent(renderer); // affiche le tout

        
        
    }
    
	//a vous de compléter, au fur et à mesure, les deux fonctions en dessous pour bien faire le nettoyage. 
    //LibererMap(map, sprites);
    freePersonnage(&mario /*goomba, nbGoomba*/);


    return continuer;
}