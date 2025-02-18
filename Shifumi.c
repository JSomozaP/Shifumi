#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PIERRE 1
#define FEUILLE 2
#define CISEAUX 3
#define QUITTER 0

int reportho(char * reponse){
if (strcasecmp(reponse, "1") == 0 || strcasecmp(reponse, "pierre") == 0|| strcasecmp(reponse, "PIERRE") == 0 || strcasecmp(reponse, "pIeRrE") == 0 || strcasecmp(reponse, "p") == 0)
    return PIERRE;
if (strcasecmp(reponse, "2") == 0 || strcasecmp(reponse, "feuille") == 0|| strcasecmp(reponse, "FEUILLE") == 0 || strcasecmp(reponse, "FeUiLlE") == 0 || strcasecmp(reponse, "f") == 0)
    return FEUILLE;
if (strcasecmp(reponse, "3") == 0 || strcasecmp(reponse, "ciseaux") == 0|| strcasecmp(reponse, "CISEAUX") == 0 || strcasecmp(reponse, "CiSeAuX") == 0 || strcasecmp(reponse, "c") == 0)
    return CISEAUX;
if (strcasecmp(reponse, "0") == 0 || strcasecmp(reponse, "quitter") == 0|| strcasecmp(reponse, "QUITTER") == 0 || strcasecmp(reponse, "QuItTeR") == 0 || strcasecmp(reponse, "exit") ==0 || strcasecmp(reponse, "p") == 0)
    return QUITTER;
return -1;
}


int main(){

    int scorejoueur1 = 0, scorejoueur2 = 0;
    char reponse [10];
    char joueur1 [20];
    char joueur2 [20];
    int choix, resultat;

    
    printf("\n\n\n------------------ Shifumi ! ------------------\n\n\n");
    printf("\nJoueur 1, quel est votre nom ?\n\n");
   
    fgets( joueur1, sizeof(joueur1), stdin );

    printf("\nJoueur 1, votre nom est : %s\n\n", joueur1);

    printf("\nJoueur 2, quel est votre nom ?\n\n");

    fgets( joueur2, sizeof(joueur2), stdin );

    printf("\nJoueur 2, votre nom est : %s\n\n", joueur2);
    while(1) {
        printf("Pierre, Feuille ou Ciseaux ?\n");
        printf("1. Pierre\n");
        printf("2. Feuille\n");
        printf("3. Ciseaux\n");
        printf("0. Quitter\n\n");


        printf("\n %s c'est à toi !\n\n", joueur1);
        if (fgets(reponse,sizeof(reponse),stdin) == NULL) {
            printf("\nvous faites %s \n", (choix == PIERRE) ? "Pierre":"Feuille");
            break;
    }

        printf("\n %s c'est à toi !\n\n", joueur2);
        if (fgets(reponse,sizeof(reponse),stdin) == NULL) {
            printf("\nvous faites %s \n", (choix == PIERRE) ? "Pierre":"Feuille");
            break;
    }

    size_t len=strlen(reponse);
        if(len>0 && reponse[len - 1]== '\n'){
            reponse[len - 1]= '\0';
        }

    choix = reportho(reponse);

        if (choix == QUITTER) { //si l'utilisateur veut quitter
            printf ("Vous quittez le jeu\n");
            break; //effectue une sortie de boucle
        }
        
        else if (choix == -1) { //si l'entrée est invalide
            printf ("Choix invalide\n");
            continue;
        } 
}
    }
