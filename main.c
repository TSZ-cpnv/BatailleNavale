#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


const int bateaux [11][11] = {{0,0,0,0,0,0,0,0,0,0,0},
                              {0,1,1,1,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,0,0,0},
                              {0,0,0,1,0,0,0,1,0,0,0},
                              {0,0,0,1,0,0,0,1,0,0,0},
                              {0,0,0,1,0,0,0,1,0,0,0},
                              {0,0,0,0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,0,0,0}};


void grille(int x,int y,int tableauBateauxToucher[11][11]){
//Déclaration de variable

    int lettre=64;



    //premier ligne
    printf("╔");
    for (int i = 0; i < 11; ++i) {
        printf("═");
        printf("═");
        printf("═");
        if (i!=10){
            printf("╦");
        }else{
            printf("╗");
        }

    }


    for (int j = 0; j < 11; ++j) {
        printf("\n");
        //2eme ligne
        printf("║");
        for (int i = 0; i < 11; ++i) {

            if (j==0){
                if (i==10){          //enelve un espace a ka case num10
                    printf(" ");
                    printf("%d",i);

                }else if (i==0){    //fait que sa n affihce rien dans la 1er case
                    printf(" ");
                    printf(" ");
                    printf(" ");
                }else{              //fait que le chiffre de 1 a 9 s'affiche a la 1er ligne
                    printf(" ");
                    printf("%d",i);
                    printf(" ");
                }
            } else{
                if (j>0 && i== 0){
                    printf(" ");
                    printf("%c",lettre);
                    printf(" ");
                }else if (tableauBateauxToucher[j][i]==2&&bateaux[j][i]==0){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    printf(" ");
                    printf("█");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    printf(" ");
                } else if (tableauBateauxToucher[j][i]==2&&bateaux[j][i]==1){
                    printf(" ");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("█");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    printf(" ");
                }else{
                    printf(" ");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    printf("█");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    printf(" ");
                }

            }


            printf("║");
        }
        printf("\n");
        //3eme ligne
        if (j!=10){
            printf("╠");
            for (int i = 0; i < 11; ++i) {
                printf("═");
                printf("═");
                printf("═");
                if (i!=10){
                    printf("╬");
                }else{
                    printf("╣");
                }
            }
        }else{
            printf("╚");
            for (int i = 0; i < 11; ++i) {
                printf("═");
                printf("═");
                printf("═");
                if (i!=10){
                    printf("╩");
                }else{
                    printf("╝");
                }
            }
        }
        ++lettre;
    }
    printf("\n");

};



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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("█");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\n\nUne fois une case touchée elle pourra s'afficher de 2 façon :\n\n");
    printf("Si il y avait un bateau sur la case : ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("█");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\nSi il n'y avait rien sur la case : ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    printf("█");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\n\nLe jeux se terminera une fois tout les bateau coullé");

};


int demandeUneCaseVertical(){
    int chiffreV;
    printf("\nchoisisez une case (Exemple : 1-4 (1 = vertical))");
    printf("\nVertical: ");
    scanf("%d",&chiffreV);
    return chiffreV;
};
int demandeUneCaseHorizontal(){
    int chiffreH;
    printf("\nchoisisez une case (Exemple : 1-4 (4 = horizontal))");
    printf("\nHorizontal : ");
    scanf("%d",&chiffreH);
    return chiffreH;
}

int verifieSiToucher(int x,int y,int bateauxToucher){

    if (bateaux[y][x]==2){
        printf("\nDeja toucher\n");
        return  bateauxToucher;
    }
    else if (bateaux[y][x]==1){
        printf("\ntoucher\n");
        return  ++bateauxToucher;


    }else{
        printf("\ny a rien\n");
        return  bateauxToucher;
    }
}




int main() {
    SetConsoleOutputCP(65001);
    //declaration de variable
    int bateauxToucher=0;
    int horizontal=0;
    int vertical=0;
    int tableauBateauxToucher [11][11] = {{0,0,0,0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0,0,0,0}};

    menu();
    switch (choixDuMenu()) {
        case 0:
            return 0;

        case 1:

            do {
                tableauBateauxToucher[vertical][horizontal]=2;
                grille(horizontal,vertical,tableauBateauxToucher);
                vertical=demandeUneCaseVertical();
                horizontal=demandeUneCaseHorizontal();
                bateauxToucher=verifieSiToucher(horizontal,vertical,bateauxToucher);
            }while (bateauxToucher<5);
            printf("\n\nGAGNER\n\n");

            system("pause");
            break;

        case 2 :
            Regle();

            system("pause");
            break;

    }

}