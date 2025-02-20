#include <stdio.h> //pour fonction d'entrée/sortie comme printf et fgets
#include <stdlib.h> //pour les fonctions standards
#include <string.h> //pour fonction de manipulation de chaînes comme strlen et strcasecmp
#include <strings.h> //pour strcasecmp

//Definition des constantes pour les differents choix possibles
#define PIERRE 1
#define FEUILLE 2
#define CISEAUX 3
#define QUITTER 0

//Definit les possibilités orthographiques pour les differentes propositions de reponses, en sachant qu'avec strcasecmp ce n'est pas sensible à la casse 
int reportho(char * reponse){ //fonction pour interpreter la réponse utilisateur
//reportho est une fonction qui prend une chaîne de caractère (reponse) et la compare avec les differentes options possibles
//elle retourne la valeur correspondante (PIERRE, FEUILLE, CISEAUX, QUITTER) ou -1 si l'entrée est invalide
if (strcasecmp(reponse, "1") == 0 || strcasecmp(reponse, "pierre") == 0|| strcasecmp(reponse, "PIERRE") == 0 || strcasecmp(reponse, "pIeRrE") == 0 || strcasecmp(reponse, "p") == 0)
    return PIERRE; //renvoi PIERRE si la reponse correspond; Idem por les choix du dessous
if (strcasecmp(reponse, "2") == 0 || strcasecmp(reponse, "feuille") == 0|| strcasecmp(reponse, "FEUILLE") == 0 || strcasecmp(reponse, "FeUiLlE") == 0 || strcasecmp(reponse, "f") == 0)
    return FEUILLE;
if (strcasecmp(reponse, "3") == 0 || strcasecmp(reponse, "ciseaux") == 0|| strcasecmp(reponse, "CISEAUX") == 0 || strcasecmp(reponse, "CiSeAuX") == 0 || strcasecmp(reponse, "c") == 0)
    return CISEAUX;
if (strcasecmp(reponse, "0") == 0 || strcasecmp(reponse, "quitter") == 0|| strcasecmp(reponse, "QUITTER") == 0 || strcasecmp(reponse, "QuItTeR") == 0 || strcasecmp(reponse, "q") ==0 || strcasecmp(reponse, "exit") ==0 || strcasecmp(reponse, "p") == 0)
    return QUITTER;
return -1; //retour au depart si l'entrée est invalide
}

    //supprime le retour à la ligne ajouté par fgets.
    void noretour (char *str) { //noretour = fonction qui supprime retour à la ligne (\n) ajouté par fgets à la fin de la chaîne
        size_t len=strlen(str); //calcule la longueur de la chaîne
        if(len>0 && str[len - 1]== '\n'){ //verifie si le dernier caractère est un retour à la ligne
                str[len - 1]= '\0'; //remplace le retour à la ligne par un caractère nul
        }
    }

int main(){
    //initialisation des variables
    int scorejoueur1 = 0, scorejoueur2 = 0; //score des joueurs
    char reponse [10]; //chaîne pour stocker la reponse utilisateur (limite de 10 caractères)
    char joueur1 [20]; //Nom des joueurs (limite de 20 caractères pour plus de flexibilité)
    char joueur2 [20];
    int p1, p2; //variable representant le choix des deux joueurs
    


    //interface visuel pour afficher nom du jeu
    printf("\n\n\n------------------ Shifumi ! ------------------\n\n\n");
    //Effectue la demande du nom du joueur 1
    printf("\nJoueur 1, quel est ton nom ?\n\n");
    fgets( joueur1, sizeof(joueur1), stdin ); //récupère le nom du joueur 1
    noretour(joueur1); //supprime le retour à la ligne
    printf("\nJoueur 1, ton nom est : %s\n\n", joueur1);

    printf("\nJoueur 2, quel est ton nom ?\n\n");
    fgets( joueur2, sizeof(joueur2), stdin ); //récupère le nom du joueur 2
    noretour(joueur2);
    printf("\nJoueur 2, ton nom est : %s\n\n", joueur2);
    
    //Boucle principal du jeu, qui permet aux manches de s'enchaîner
    while(1) {
        printf("Pierre, Feuille ou Ciseaux ?\n"); //interface visuelle
        printf("1. Pierre\n");
        printf("2. Feuille\n");
        printf("3. Ciseaux\n");
        printf("0. Quitter\n\n");

    //lance le tour du joueur 1
        printf("\n %s c'est à toi !\n\n", joueur1);
        if (fgets(reponse,sizeof(reponse),stdin)==NULL) { //récupère la réponse du joueur 1
            printf("\nErreur de saisie; \n");
            continue;  //recommence la boucle en cas d'erreur
    }
    noretour(reponse); //effectue la suppression du retour à la ligne pour qu'il n'y ait pas de soucis avec fgets
    p1 = reportho(reponse); //l'int p1 pioche les réponses du tableaux reportho et interprète sa réponse

    if(p1==QUITTER) { //si l'utilisateur veut quitter
        printf("\n Tu quitte le jeu. \n");
        break; //effectue une sortie de boucle
    }
    else if(p1==-1) { //si l'entrée est invalide
        printf("\nChoix invalide, retente. \n");
        continue;
    }
    //tour du joueur 2
        printf("\n %s c'est à toi !\n\n", joueur2);
        if (fgets(reponse,sizeof(reponse),stdin)==NULL) {
            printf("\nErreur de saisie; \n");
            continue; 
    }

    noretour(reponse);
    p2 = reportho(reponse);

    if(p2==QUITTER) {
        printf("\nTu quitte le jeu. \n");
        break;
    }
    else if(p2==-1) {
        printf("\nChoix invalide, retente. \n");
        continue;
    }
    

    //Definit toutes les conditions de réponses pour une égalité, une victoire du joueur1 ou du joueur2
    if ((p1==PIERRE && p2==PIERRE)|| (p1==FEUILLE && p2==FEUILLE) || (p1==CISEAUX && p2==CISEAUX)) {
        scorejoueur1==0, scorejoueur2==0;
        printf("\nVous avez fait égalité !\n"); //le score ne change pas
    }
    
    if ((p1==PIERRE && p2==CISEAUX) || (p1==CISEAUX && p2==FEUILLE) || (p1==FEUILLE && p2==PIERRE)) {
          scorejoueur1++;
        printf("\n %s gagne ce duel !\n", joueur1); //incrémente le score d'1pt pour joueur1
        
    }
           
    if ((p2==PIERRE && p1==CISEAUX) || (p2==CISEAUX && p1==FEUILLE)|| (p2==FEUILLE && p1==PIERRE)) {
            scorejoueur2++;
        printf("\n %s gagne ce duel !\n", joueur2); //incrémente le score d'1pt pour joueur2
        
    }

    //affichage des scores
    printf("\nScores :\n");
    printf("%s : %d\n", joueur1, scorejoueur1);
    printf("%s : %d\n", joueur2, scorejoueur2);
    printf("-------------------------------------\n");    
}
    //Affichage final des scores
    printf("\n##### GAME OVER #####\n");
    printf("\nScores finaux :\n");
    printf("%s : %d\n", joueur1, scorejoueur1);
    printf("%s : %d\n", joueur2, scorejoueur2);

    return 0; //fin du programme
}
    
