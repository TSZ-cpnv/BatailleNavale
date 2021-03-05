#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
*
*/
void menu()
{
    printf("0 - Quitter le programme");
    printf("\n1 - Jouer");
    printf("\n2 - Règle\n\n");
}

/*
*
*/
int choixDuMenu()
{
    //Déclaration variable
    int choix;

    //Demande a l'utilisateur son choix
    do{
        printf("Veuillez choisir :");
        scanf("%d",&choix);
    } while (choix>3);
    return choix;

}

void Regle(){
        printf("\nLes regles de la bataille navale :\n");
        printf("\nVous aurez une grille de 10 sur 10 et vous devrez choisir une case");
        printf("\nUne fois une case choisit, le programme lancera un boulet dessus et vous redira si il y a vait un beateau ou non");
        printf("\n\nPoint important :\n");
        printf("\nles casse s'afficheron comme ceci : ");
        printf("\n\nUne fois une case touchée elle pourra s'afficher de 2 façon :\n\n");
        printf("Si il y avait quelque chose sur la case :  \n");
        printf("Si il n'y avait rien sur la case : █ ");
        printf("\n\nLe jeux se terminera une fois tout les bateau coullé");

};

void demandeUneCase(){
    printf("choisisez une case (Exemple : F4");
    printf("Vetical : ");




};




int main() {
    SetConsoleOutputCP(65001);


        menu();



        switch (choixDuMenu()) {
            case 0:
                return 0;

            case 1:
                demandeUneCase;
                //y aura le jeux
                break;

            case 2 :
                Regle();

                system("pause");
                break;

        }

}