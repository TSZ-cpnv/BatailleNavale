#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


const int bateaux [11][11] = {{0,0,0,0,0,0,0,0,0,0,0},
                              {0,0,1,0,0,0,0,0,0,0,0},
                              {0,0,1,0,0,0,0,0,0,0,0},
                              {0,0,1,0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,1,0,0},
                              {0,0,1,1,0,0,0,0,1,0,0},
                              {0,0,0,0,0,0,0,0,1,0,0},
                              {0,0,1,0,0,0,0,0,1,0,0},
                              {0,0,1,0,0,0,0,0,0,0,0},
                              {0,0,1,1,1,1,1,1,0,0,0},
                              {0,0,0,0,0,0,0,0,0,0,0}};


void grille(int x,int y,int tableauBateauxToucher[11][11]){
//Déclaration de variable
    int lettre=64;

    system("cls");
    //premier ligne
    printf("-------------------Légende------------------");
    printf("\n\nToucher un bateau = ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("█");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\n\nPlouf = ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    printf("█\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

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
                    printf(" ");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
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


void menu()
{
    printf("0 - Quitter le programme");
    printf("\n1 - Jouer");
    printf("\n2 - Règle\n\n");
}


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
    system("cls");
    printf("Les regles de la bataille navale :\n");
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
    printf("\n\nLe jeux se terminera une fois tout les bateau seront coullé\n\n");

};


int demandeUneCaseVertical(){
    char lettre;
    int chiffre;
    printf("\nchoisisez une case (A-J)");

    printf("\nVertical: ");
    fflush(stdin);
    scanf("%c",&lettre);

        chiffre=lettre-64;

    return chiffre;
};


int demandeUneCaseHorizontal(){
    int chiffreH;
    printf("\nchoisisez une case (1-10)");
    printf("\nHorizontal : ");
    fflush(stdin);
    scanf("%d",&chiffreH);
    return chiffreH;
}


int verifieSiToucher(int x,int y,int bateauxToucher,int tableauBateauxToucher[11][11]){
    if (x<1 || x>10 || y<1 || y>10){
        printf("\ncoordonée invalide\n\n");
        system("pause");
        return  bateauxToucher;
    }
    else if (tableauBateauxToucher[y][x]==2){
        printf("\nCette case est déja touché ^^\n\n");
        system("pause");
        return  bateauxToucher;
    }
    else if (bateaux[y][x]==1){
        printf("\nToucher ^^\n\n");
        tableauBateauxToucher[y][x]=2;
        system("pause");
        return  ++bateauxToucher;
    }else{
        printf("\nPlouf ^^\n\n");
        tableauBateauxToucher[y][x]=2;
        system("pause");
        return  bateauxToucher;
    }
}

void gagner(){
    system("cls");
    printf("Vous avez gagner, BRAVO !!!\n\n");
}




int main() {
    //setbuf(stdout,0);
    system("mode con: cols=122 lines=35");
    SetConsoleOutputCP(65001);
    //declaration de variable
    int bateauxToucher=0;
    int choix;
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

    do {
        system("cls");
        menu();
        choix = choixDuMenu();
        switch (choix) {
            case 0:
                return 0;

            case 1:

                do {

                    grille(horizontal, vertical, tableauBateauxToucher);
                    vertical = demandeUneCaseVertical();
                    horizontal = demandeUneCaseHorizontal();
                    bateauxToucher = verifieSiToucher(horizontal, vertical, bateauxToucher, tableauBateauxToucher);
                } while (bateauxToucher != 17);
                gagner();

                system("pause");
                break;

            case 2 :
                Regle();

                system("pause");
                break;
        }
    }while (choix!=0);

}
