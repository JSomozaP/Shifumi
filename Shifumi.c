#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PIERRE 1
#define FEUILLE 2
#define CISEAUX 3
#define QUITTER 0

//Definit les possibilités orthographiques pour les differentes propositions de reponses, en sachant qu'avec strcasecmp ce n'est pas sensible à la casse 
int reportho(char * reponse){
if (strcasecmp(reponse, "1") == 0 || strcasecmp(reponse, "pierre") == 0|| strcasecmp(reponse, "PIERRE") == 0 || strcasecmp(reponse, "pIeRrE") == 0 || strcasecmp(reponse, "p") == 0)
    return PIERRE;
if (strcasecmp(reponse, "2") == 0 || strcasecmp(reponse, "feuille") == 0|| strcasecmp(reponse, "FEUILLE") == 0 || strcasecmp(reponse, "FeUiLlE") == 0 || strcasecmp(reponse, "f") == 0)
    return FEUILLE;
if (strcasecmp(reponse, "3") == 0 || strcasecmp(reponse, "ciseaux") == 0|| strcasecmp(reponse, "CISEAUX") == 0 || strcasecmp(reponse, "CiSeAuX") == 0 || strcasecmp(reponse, "c") == 0)
    return CISEAUX;
if (strcasecmp(reponse, "0") == 0 || strcasecmp(reponse, "quitter") == 0|| strcasecmp(reponse, "QUITTER") == 0 || strcasecmp(reponse, "QuItTeR") == 0 || strcasecmp(reponse, "q") ==0 || strcasecmp(reponse, "exit") ==0 || strcasecmp(reponse, "p") == 0)
    return QUITTER;
return -1;
}


int main(){

    int scorejoueur1 = 0, scorejoueur2 = 0;
    char reponse [10];
    char joueur1 [20];
    char joueur2 [20];
    int p1, p2; //int representant les deux joueurs
    int choix, resultat;


    
    printf("\n\n\n------------------ Shifumi ! ------------------\n\n\n");
    printf("\nJoueur 1, quel est votre nom ?\n\n");
   
    fgets( joueur1, sizeof(joueur1), stdin ); //récupère le nom du joueur 1

    printf("\nJoueur 1, votre nom est : %s\n\n", joueur1);

    printf("\nJoueur 2, quel est votre nom ?\n\n");

    fgets( joueur2, sizeof(joueur2), stdin ); //récupère le nom du joueur 2

    printf("\nJoueur 2, votre nom est : %s\n\n", joueur2);
    
    while(1) {
        printf("Pierre, Feuille ou Ciseaux ?\n"); //interface visuelle
        printf("1. Pierre\n");
        printf("2. Feuille\n");
        printf("3. Ciseaux\n");
        printf("0. Quitter\n\n");


        printf("\n %s c'est à toi !\n\n", joueur1);
        if (fgets(reponse,sizeof(reponse),stdin)) {
            printf("\ntu fais %s \n", (choix == PIERRE) ? "Pierre":"Feuille");
            
    }

        printf("\n %s c'est à toi !\n\n", joueur2);
        if (fgets(reponse,sizeof(reponse),stdin)) {
            printf("\ntu fais %s \n", (choix == PIERRE) ? "Pierre":"Feuille");
            
    }
    
    //supprime le retour à la ligne ajouté par fgets
    size_t len=strlen(reponse);
        if(len>0 && reponse[len - 1]== '\n'){
            reponse[len - 1]= '\0';
        }
    
    choix = reportho(reponse); //l'int choix pioche les réponses du tableaux reportho

        if (choix == QUITTER) { //si l'utilisateur veut quitter
            printf ("Vous quittez le jeu\n");
            break; //effectue une sortie de boucle
        }
        
        else if (choix == -1) { //si l'entrée est invalide
            printf ("Choix invalide\n");
            continue;
        } 

    //Definit toutes les conditions de réponses pour une égalité, une victoire du joueur1 ou du joueur2
    if ((p1==PIERRE && p2==PIERRE)|| (p1==FEUILLE && p2==FEUILLE) || (p1==CISEAUX && p2==CISEAUX)) {
        scorejoueur1==0, scorejoueur2==0;
        printf("Vous avez fait égalité !\n");
    }
    
    if ((p1==PIERRE && p2==CISEAUX) || (p1==CISEAUX && p2==FEUILLE) || (p1==FEUILLE && p2==PIERRE)) {
          scorejoueur1++;
        printf(" %s gagne ce duel !\n", joueur1);
    }
           
    if ((p2==PIERRE && p1==CISEAUX) || (p2==CISEAUX && p1==FEUILLE)|| (p2==FEUILLE && p1==PIERRE)) {
            scorejoueur2++;
        printf(" %s gagne ce duel !\n", joueur2);
        return resultat;
    }
    
}
    }
    
