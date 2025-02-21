#include <stdio.h> //pour fonction d'entrée/sortie comme printf et fgets
#include <stdlib.h> //pour les fonctions standards
#include <string.h> //pour fonction de manipulation de chaînes comme strlen et strcasecmp
#include <strings.h> //pour strcasecmp
#include <time.h> //gère srand et rand


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
if (strcasecmp(reponse, "0") == 0 || strcasecmp(reponse, "quitter") == 0|| strcasecmp(reponse, "QUITTER") == 0 || strcasecmp(reponse, "QuItTeR") == 0 || strcasecmp(reponse, "q") ==0 || strcasecmp(reponse, "exit") ==0)
    return QUITTER;
return -1; //retour au depart si l'entrée est invalide
}

    //supprime le retour à la ligne ajouté par fgets.
    void noretour (char *str) { //noretour = fonction qui supprime retour à la ligne (\n) ajouté par fgets à la fin de la chaîne
    //void indique que la fonction ne retourn aucune valeur
    // char * str : paramètre de la fonction. C'est un pointeur vers une chaîne de caractère (tableau de char)
    //str est l'adresse mémoire du premier caractère de la chaîne
        size_t len=strlen(str); //calcule la longueur de la chaîne
        //strlen prend un pointeur vers une chaîne (char *) en entrée, puis retourne le nombre de caractère dans la chaîne jusqu'au premier caractère nul (\0) mais sans l'inclure
        //size_t : type de donnée non signé (unsigned) utilisé pour présenter tailles et longueurs, souvent utilisé pour les fonctions de manipulation de chaîne
        //len : une variable qui stocke la longueur de la chaîne str
        if(len>0 && str[len - 1]== '\n'){ //verifie si le dernier caractère est un retour à la ligne
                str[len - 1]= '\0'; //remplace le retour à la ligne par un caractère nul
        //len>0 verifie que la chaîne n'est pas vide
        //si len est 0, cela signifie que la chaîne est vide (soit str est une chaîne vide, soit elle contient uniquement le caractère nul \0)

        //str[len-1]== '\n' : verifie si le dernier caractère de la chaîne est une retour à la ligne (\n)
        //str[len-1] accède au dernier caractère de la chaîne (car les indices commencent à 0)
        // \n est le caractère de retour à la ligne ajouté par fgets lorsque l'utilisateur appuie sur entrée
        // && est un opérateur logique "ET", les deux conditions doivent être vraies pour que le bloc if soit executé

        //dans str[len-1]= '\0'
        //str[len-1] : accède au dernier caractère de la chaîne
        //'\0' : la caractère nul, qui marque la fin d'une chaîne en C
        // au final, remplace le retour à la ligne (\n) par une caractère nul (\0)
        //cela tronque la chaîne en supprimant le retour à la ligne, ce qui est utile pour éviter les probèmes lors de la manipulation de la chaîne (par exemple lors de la comparaison avec strcmp ou strcasecmp) 
       
       // fgets inclut le retour à la ligne (\n) dans la chaîne lue. Par exemple si l'utilisateur tape "Pierre" et valide en appuyant sur entré, la chaîne sera "Pierre\n"
       //ce retour à la ligne peut interferer avec les comparaisons de chaînes ou autre opérations. Par exemple strcmp("Pierre\n", "Pierre") retournera une difference même si les chaînes sont identiques sans le \n 
       //noretour supprime ce retour à la ligne en le remplaçant par un caractère nul (\0), ce qui rend la chaîne plus facile à manipuler
       
        }
    }

int main(){
    //initialisation des variables
    int scorejoueur = 0, scorepc = 0; //score des joueurs
    char reponse [10]; //chaîne pour stocker la reponse utilisateur (limite de 10 caractères)
    char joueur [20]; //Nom des joueurs (limite de 20 caractères pour plus de flexibilité)
    int choixjoueur, choixpc; //variable representant le choix des deux joueurs
    
    srand(time(NULL));

    //interface visuel pour afficher nom du jeu
    printf("\n\n\n------------------ Shifumi ! ------------------\n\n\n");
    //Effectue la demande du nom du joueur 1
    printf("\nJoueur, quel est ton nom ?\n\n");
    fgets( joueur, sizeof(joueur), stdin ); //récupère le nom du joueur 1
    noretour(joueur); //supprime le retour à la ligne
    printf("\nJoueur, ton nom est : %s\n\n", joueur);

    /*printf("\nJoueur 2, quel est ton nom ?\n\n");
    fgets( joueur2, sizeof(joueur2), stdin ); //récupère le nom du joueur 2
    noretour(joueur2);
    printf("\nJoueur 2, ton nom est : %s\n\n", joueur2);*/
    
    //Boucle principal du jeu, qui permet aux manches de s'enchaîner
    while(1) {
        printf("Pierre, Feuille ou Ciseaux ?\n"); //interface visuelle
        printf("1. Pierre\n");
        printf("2. Feuille\n");
        printf("3. Ciseaux\n");
        printf("0. Quitter\n\n");

    //lance le tour du joueur 1
        printf("\n %s c'est à toi !\n\n", joueur);
        if (fgets(reponse,sizeof(reponse),stdin)==NULL) { //récupère la réponse du joueur 1
            printf("\nErreur de saisie; \n");
            continue;  //recommence la boucle en cas d'erreur
    }
    noretour(reponse); //effectue la suppression du retour à la ligne pour qu'il n'y ait pas de soucis avec fgets
    choixjoueur = reportho(reponse); //l'int p1 pioche les réponses du tableaux reportho et interprète sa réponse

    if(choixjoueur==QUITTER) { //si l'utilisateur veut quitter
        printf("\n Tu quitte le jeu. \n");
        break; //effectue une sortie de boucle
    }
    else if(choixjoueur==-1) { //si l'entrée est invalide
        printf("\nChoix invalide, retente. \n");
        continue;
    }
   /*//tour du joueur 2
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
    } */

   //tour du pc avec génération d'un choix aléatoire
   choixpc=(rand()%3)+1; //génère un nombre entre 1 et 3, couvrant le champs de possibilité de choix

   //affichage des choix
   printf("\n%s fait %s !\n", joueur, (choixjoueur==PIERRE) ? "Pierre" : (choixjoueur==FEUILLE) ? "Feuille" : "Ciseaux");
   // "?" utilisation d'un opérateur ternaire qui permet de faire une condition en une seule ligne
   //Utilisation d'un opérateur ternaire imbriqué qui fonctionne comme une condition if-else en une seule ligne
   //première condition : choixjoueur==Pierre
   //si c'est vrai, retourne "Pierre", et si c'est faux, passe à la condition suivante
   //deuxième condition : choixjoueur==Feuille
   //si c'est vrai, retourne "Feuille", si c'est faux passe à la valeur par defaut
   //valeur par defaut : "Ciseaux", si aucune des conditions précédentes n'est vraie, retourne "Ciseaux"
   printf("PC fait %s !\n", (choixpc ==PIERRE) ? "Pierre" : (choixpc == FEUILLE) ? "Feuille" : "Ciseaux");
   //peut aussi être remplacé par un tableau de chaînes : 
   /*const char *choixnoms[]={"", "Pierre", "Feuille", "Ciseaux"};
   printf("\n%s fait %s !\n", joueur, choixnoms[choixjoueur]);
   printf("PC fait %s !\n", choixnoms[choixpc]); */
    

    //Definit toutes les conditions de réponses pour une égalité, une victoire du joueur1 ou du joueur2
    if ((choixjoueur==PIERRE && choixpc==PIERRE)|| (choixjoueur==FEUILLE && choixpc==FEUILLE) || (choixjoueur==CISEAUX && choixpc==CISEAUX)) {
        scorejoueur==0, scorepc==0;
        printf("\nVous avez fait égalité !\n"); //le score ne change pas
    }
    
    if ((choixjoueur==PIERRE && choixpc==CISEAUX) || (choixjoueur==CISEAUX && choixpc==FEUILLE) || (choixjoueur==FEUILLE && choixpc==PIERRE)) {
          scorejoueur++;
        printf("\n %s gagne ce duel !\n", joueur); //incrémente le score d'1pt pour joueur1
        
    }
           
    if ((choixpc==PIERRE && choixjoueur==CISEAUX) || (choixpc==CISEAUX && choixjoueur==FEUILLE)|| (choixpc==FEUILLE && choixjoueur==PIERRE)) {
            scorepc++;
        printf("\n PC gagne ce duel !\n"); //incrémente le score d'1pt pour joueur2
        
    }

    //affichage des scores
    printf("\nScores :\n");
    printf("%s : %d\n", joueur, scorejoueur);
    printf("PC : %d\n", scorepc);
    printf("-------------------------------------\n");    
}
    //Affichage final des scores
    printf("\n##### GAME OVER #####\n");
    printf("\nScores finaux :\n");
    printf("%s : %d\n", joueur, scorejoueur);
    printf("PC : %d\n", scorepc);

    return 0; //fin du programme
}
    
