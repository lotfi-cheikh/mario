#include <stdlib.h>
#include <stdio.h>

#include "charactere.h"


void chargerMario(Personnage* mario, Map* map, SDL_Renderer *renderer)
{

    mario->image=malloc(NUMBER_IMAGE_MARIO*sizeof(SDL_Texture*));
    if (mario->image == NULL){
        printf("Erreur\n");
        exit(EXIT_FAILURE);
    }
mario->image[0]= loadImage ("img/Mario1.png", renderer);
mario->image[1]= loadImage ("img/Mario2.png", renderer);
mario->image[2]= loadImage ("img/Mario3.png", renderer);
mario->image[3]= loadImage ("img/Mario4.png", renderer);
mario->image[4]= loadImage ("img/Mario5.png", renderer);
mario->image[5]= loadImage ("img/Mario6.png", renderer);


mario->jump=0; //Si mario saute lors de la montée du saut jump = 1, sinon 0
mario->jumptime=0; //correspond à la durée depuis quand mario fait un saut, à 70 on arrête
mario->gravite=0; //vaut 1 si mario est dans les air, 0 sinon. 
mario->direction=0;
mario->dernieredirection=1; //direction vers laquelle est dirigé mario, 1 : droite, 2 : gauche, 0 : statique) 
mario->temp=0; //permet de faire varier les sprites de mario dans le temps.
mario->win=0;//vaut 1 si le personnage gagne, -1 si il perd, 0 sinon. 
mario->invisible=0; //utilisé pour les goombas quand il meurt vaut 1 dans ce cas, 0 si en vit.
mario->lvl=0;
mario->lvlperdu=0;

mario->position.w= WIDTH_MARIO;
mario->position.h= HEIGHT_MARIO;
mario->position.x = 100;
mario->position.y = 900;

}

void afficherPerso(Personnage* mario, int xscroll, int yscroll , SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer,mario->image[0],NULL,&mario->position);

   
}


//retourne soit numéro1 soit numéro2 pour alterner entre 2 sprite sur un mouvement.
int chooseSpriteMovement(Personnage* mario, int numero1, int numero2) {
    
    return numero1;
}

void freePersonnage(Personnage* mario/*, Personnage **goomba, int nbGoomba*/) {
    
}