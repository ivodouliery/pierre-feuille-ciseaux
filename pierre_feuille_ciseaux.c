#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PIERRE 1
#define FEUILLE PIERRE+1
#define CISEAUX FEUILLE+1
#define NBESSAIS 3
#define POINTSGAGNANTS 3 

  /* Il sera probablement n�cessaire de modifier les parametres et valeur de retour des fonctions 
    choix_ordinateur, choix_joueur, score et jeu */

  /* Les declarations actuelles permettent de compiler et d'executer le programme */

void affichage_objet(int obj){
  /* hypoth�se : obj = PIERRE ou
     obj = FEUILLE ou obj = CISEAUX
   
   affiche le nom de l'objet correspondant � obj */
  
  if (obj == PIERRE){
    printf("PIERRE");
  } else {
    if (obj == FEUILLE){
      printf("FEUILLE");
    } else {
      printf("CISEAUX");
    }
  }
}

int choix_ordinateur(void) {
/* hypoth�se : PIERRE < FEUILLE < CISEAUX
  toutes les valeurs comprises entre PIERRE et CISEAUX sont "valables"
  renvoie une valeur choisie al�atoirement entre PIERRE et CISEAUX */
  return rand()%(CISEAUX-PIERRE+1)+PIERRE;
}

int choix_joueur() {
/* hypoth�ses : PIERRE < FEUILLE < CISEAUX 
  renvoie la valeur choisie par le joueur
  v�rifie qu'elle est comprise entre PIERRE et CISEAUX 
  redemande la saisie si ce n'est pas le cas
  
  Si apr�s NBESSAIS le joueur n'a pas saisi de valeur valable,
  cette derni�re est tir�e au sort */
  int cpt=0;
  int choix;
  while (cpt<3){
  	printf("saisissez le chiffre correspondant à votre choix : \n");
    printf("\n");
  	printf("%d) Pierre\n",PIERRE);
  	printf("\n");
  	printf("%d) Feuille\n",FEUILLE);
  	printf("\n");
  	printf("%d) Ciseaux\n",CISEAUX);
  	printf("\n");
  	do{
  		printf("Votre choix : \n");
  		scanf("%d",&choix);
  		if((choix<PIERRE)||(choix>CISEAUX)){
  			printf("Saisie non valable, recommencez\n");
  			cpt++;
  		}else{
        cpt=4;
      }
  	}while(((choix<PIERRE)||(choix>CISEAUX))&&(cpt<NBESSAIS));
  	if (cpt==NBESSAIS){
  	  choix=rand()%(CISEAUX-PIERRE+1)+PIERRE;
  	}
  }
  return choix;
}

void score(int choixj, int choixo,int *scorej,int *scoreo){
  /* hypoth�ses : le coup du joueur et celui de l'ordinateur sont valables 
                  (�gaux � PIERRE, FEUILLE ou CISEAUX)
   augmente de 1 le score du joueur si le coup du joueur est gagnant
   augmente de 1 le score de l'ordinateur si le coup de l'ordinateur est gagnant */
  if (choixj==FEUILLE){
    if (choixo==PIERRE){
   		*scorej=*scorej+1;
   	}else if(choixo==CISEAUX){
   		*scoreo=*scoreo+1;
   	}
  }else if (choixj==PIERRE){
   	if (choixo==CISEAUX){
   		*scorej=*scorej+1;
   	}else if(choixo==FEUILLE){
   		*scoreo=*scoreo+1;
   	}
  }else if (choixj==CISEAUX){ 
   	if (choixo==FEUILLE){
   		*scorej=*scorej+1;
   	}else if(choixo==PIERRE){
   		*scoreo=*scoreo+1;
   	}
	}
}




void jeu() {
  /* boucle de jeu, la partie s'arr�te d�s qu'un des deux joueurs 
   atteint POINTSGAGNANTS points */
  int scorej=0;
  int scoreo=0;
  while((scorej<POINTSGAGNANTS)&&(scoreo<POINTSGAGNANTS)){
    int choixj=choix_joueur();
    int choixo=choix_ordinateur();
    printf("L'ordinateur a choisi : \n"); affichage_objet(choixo); printf("\n");
    score(choixj,choixo,&scorej,&scoreo);
    if ((scorej<2)&&(scoreo<2)){
      printf("Vous avez %d point et l'ordinateur %d point\n",scorej,scoreo);
    }else if((scorej<2)&&(scoreo>1)){
      printf("Vous avez %d point et l'ordinateur %d points\n",scorej,scoreo);
    }else if((scorej>1)&&(scoreo<2)){
      printf("Vous avez %d points et l'ordinateur %d point\n",scorej,scoreo);
    }else if((scorej>1)&&(scoreo>1)){
      printf("Vous avez %d points et l'ordinateur %d points\n",scorej,scoreo);
    }
  }
  
  if (scorej>scoreo){
    printf("Vous avez gagné !\n");
  }
  else if(scoreo>scorej){
    printf("Vous avez perdu !\n");
  }
}

int main() {
  
  srand(time(NULL));
 
  jeu();
  return 0;
}


