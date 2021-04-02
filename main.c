#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

char pseudo[15]="Inconnu";

char bateaux[11][11];

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

/**
 * Code pris à Arthur Bottemanne
 * @return
 */
int date()
{
    //time_t est un type de variable
    time_t temps = time(NULL);
    //on associe la structure de localtime dans la variable t
    struct tm tm = *localtime(&temps);
    //on met les valeurs de la date dans une table pour pouvoir plus facilement les retourner
    int dateEtHeure[] = {tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min};
    return (int) dateEtHeure;
}

/**
 * Base du code pris a Arthur Bottemanne
 * @return
 */
void logs(int typeDevenement, int coordonneesVerticalOuScore, int coordonneesH){
    int *dateEtHeure;
    char stockageLogs[150];
    FILE*fichierLogs;
    fichierLogs= fopen("Logs/Logs.txt","a");
    if (fichierLogs == NULL)
    {
        printf("\nLe dossier n'est pas trouvable\n");
        system("pause");
        return;
    }
    //insertion des valeurs de date et heure dans la table
    dateEtHeure = (int *) date();
    switch (typeDevenement)
    {
        //le joueur a commencé une partie
        case 1:
            sprintf(stockageLogs,"%s a commencé une partie le %d.%d.%d %d:%d\n\n",pseudo, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
            fputs(stockageLogs, fichierLogs);
            break;
            //le joueur a tiré
        case 2:
            sprintf(stockageLogs, "%s a tiré sur %d;%d le %d.%d.%d %d:%d\n\n", pseudo, coordonneesVerticalOuScore, coordonneesH, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
            fputs(stockageLogs, fichierLogs);
            break;
            //le joueur a gagné la partie
        case 3:
            sprintf(stockageLogs, "%s a gagné avec un score de %d le %d.%d.%d %d:%d\n\n", pseudo, coordonneesVerticalOuScore, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
            fputs(stockageLogs, fichierLogs);
            break;
            //appelle la fonction pour l'aide
        case 4:
            sprintf(stockageLogs,"%s a affiché l'aide le %d.%d.%d %d:%d\n\n",pseudo, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
            fputs(stockageLogs, fichierLogs);
            break;
            //le joueur appelle la fonction score
        case 5:
            sprintf(stockageLogs,"%s a affiché le tableau des scores le %d.%d.%d %d:%d\n\n",pseudo, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
            fputs(stockageLogs, fichierLogs);
            break;
            //le joueur s'est authentifié
        case 6:
            sprintf(stockageLogs,"L'utilisateur s'est nommé %s le %d.%d.%d %d:%d\n\n",pseudo, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
            fputs(stockageLogs, fichierLogs);
            break;
            //le joueur a quitté le programme
        case 7:
            sprintf(stockageLogs,"%s a fermé le programme le %d.%d.%d %d:%d\n\n",pseudo, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
            fputs(stockageLogs, fichierLogs);
            break;
    }
    fclose(fichierLogs);

}

int nombreAleatoire(){
    srand(time(NULL));
    int nombreAle=rand() % 5 + 1;
    return nombreAle;
}

void recupererLaGrille(){

    char cheminFichier[20];
    int nombreAle=nombreAleatoire();
    FILE*fichierGrille;
    sprintf(cheminFichier,"Grille/%d.txt",nombreAle);
    fichierGrille=fopen(cheminFichier, "r");
    if (fichierGrille == NULL)
    {
        printf("\nLe dossier n'est pas trouvable\n");
        system("pause");
        return;
    }
    fgets((char *) bateaux, 122, fichierGrille);
    fclose(fichierGrille);
}


void afficherGrille(int x, int y){
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
                if (i==10){          //enelve un espace a la case num10
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
                if (j>0 && i == 0){
                    printf(" ");
                    printf("%c",lettre);
                    printf(" ");
                }else if (tableauBateauxToucher[j][i]==2&&bateaux[j][i]==48){
                    printf(" ");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    printf("█");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    printf(" ");
                } else if (tableauBateauxToucher[j][i]==2&&bateaux[j][i]==49){
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
    printf("\n2 - Règle");
    printf("\n3 - Tableau des scores");
    printf("\n4 - Autentification\n\n");
}


int choixDuMenu()
{
    //Déclaration variable
    int choix;

    //Demande a l'utilisateur son choix
        printf("Veuillez choisir :");
        scanf("%d",&choix);
    return choix;
}


void Regle(){
    system("cls");
    printf("Les regles de la bataille navale :\n");
    printf("\nVous aurez une afficherGrille de 10 sur 10 et vous devrez choisir une case.");
    printf("\nUne fois une case choisit, le programme lancera un boulet dessus et vous redira si il y a vait un beateau ou non.");
    printf("\n Si vous toucher un bateaux, il vous raportera 100 points, si vous toucher rien, vous persez 10point.");
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


int verifieSiToucher(int x,int y,int bateauxToucher){
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
    else if (bateaux[y][x]-48==1){
        printf("\nToucher\n\n");
        tableauBateauxToucher[y][x]=2;
        system("pause");
        return  ++bateauxToucher;
    }else{
        printf("\nPlouf\n\n");
        tableauBateauxToucher[y][x]=2;
        system("pause");
        return  bateauxToucher;
    }
}

void gagner(){
    system("cls");
    printf("Vous avez gagner, BRAVO !!!\n\n");
}

int CalculeScore(int score,int bateauToucher[11][11]){

    for (int j = 0; j < 11; ++j) {
        for (int i = 0; i < 11; ++i) {
            if (bateauToucher[j][i]==2 && bateaux[j][i]-48==1){
                score=(score+100);
            }else if(bateauToucher[j][i]==2 && bateaux[j][i]-48==0){
                score=(score-10);
            }
        }
    }
    return score;
}

void reinitialiseLeTableau(){
    for (int j = 0; j < 11; ++j) {
        for (int i = 0; i < 11; ++i) {
            tableauBateauxToucher[i][j]=0;
        }

    }

}

void enregistrementDuScoreEtPseudo(int scoreNombre){
    char score[150];


    FILE* fichierScores;
    fichierScores = fopen("Score/Score.txt", "a");
    sprintf(score,"%18s%30d\n",pseudo,scoreNombre);
    if (fichierScores == NULL)
    {
        printf("\nLe dossier n'est pas trouvable\n");
        system("pause");
        return;
    }
    fputs(score,fichierScores);
    fclose(fichierScores);
}

void demandePseudo(){
    int verification;
    do {
        system("cls");
        printf("Entrer votre pseudo :\n");
        printf("Votre psuedo : ");
        scanf("%s",&pseudo);
        fflush(stdin);
        printf("\n\nVotre pseudo est %s, Etes vous sur (O/N)\n\n",pseudo);
        scanf("%c",&verification);
        fflush(stdin);
    } while (verification!=79);

}

void enTeteTableauScore(){
    system("cls");

    printf("\n                      Tableau des scores                    \n\n");
    printf("------------------------------------------------------------\n");
}

void tableauScore(){
    char caractere;
    FILE* fp;
    fp = fopen("Score/Score.txt","r");

    if (fp == NULL)
    {
        printf("\nLe dossier n'est pas trouvable\n");
        system("pause");
        return;
    }
    do
    {
        caractere = fgetc(fp);
        printf("%c", caractere);
    } while (caractere != EOF);
    fclose(fp);
    printf("\n\n");
}





int main() {
    //setbuf(stdout,0);
    system("mode con: cols=122 lines=35");
    SetConsoleOutputCP(65001);
    //declaration de variable
    int bateauxToucher=0;
    int choix = 0;
    int horizontal=0;
    int vertical=0;
    int score=0;


    do {
        system("cls");
        menu();
        choix = choixDuMenu();


        switch (choix) {
                case 0:
                    logs(7, (int) NULL, (int) NULL);
                    return 0;

                case 1:
                    recupererLaGrille();
                    logs(1, (int) NULL, (int) NULL);
                    do {

                        afficherGrille(horizontal, vertical);
                        vertical = demandeUneCaseVertical();
                        horizontal = demandeUneCaseHorizontal();
                        logs(2,vertical,horizontal);
                        bateauxToucher = verifieSiToucher(horizontal, vertical, bateauxToucher);
                    } while (bateauxToucher != 17);
                    score=CalculeScore(score, tableauBateauxToucher);
                    gagner();
                    bateauxToucher=0;
                    logs(3, score, (int) NULL);
                    enregistrementDuScoreEtPseudo(score);
                    reinitialiseLeTableau();

                    system("pause");
                    break;

                case 2 :
                    logs(4, (int) NULL, (int) NULL);
                    Regle();

                    system("pause");
                    break;
            case 3:

                enTeteTableauScore();
                tableauScore();
                logs(5, (int) NULL, (int) NULL);
                system("pause");
                break;
            case 4:

                demandePseudo();
                logs(6, (int) NULL, (int) NULL);

                break;
            default :
                return 0;
            }
        }
        while (choix != 0);




}
