#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main()
{
    system("color 4e");
    int r=20, c=35; /*numero di righe e colonne*/
    int i=0,j=0; /*contatori multiuso*/
    int pb,lb,ppr,ppc, pbr; /*posizione barra e lunghezza barra e pallina*/
    int m; /*movimento barra*/
    int t = clock(), t1 = clock(), t2 = clock(); /*tempo*/
    int a; /* andamento pallina */
    int lose = 0, win = 0; /*perso*/
    char nome[5], avver[6], *gand = "GANDY", *musso = "MUSSO", *scal = "SCALE";
    int level = 1; /*Livello*/
    float timeg = 110;
    int timem = 105, times = 1;
    int primo = 1;

    char v[20][35]; /*griglia di gioco */

    printf("Benvenuti in HOCKEY-CUP!!         <by Luca Mazzucco>\n\n");
    printf("Il seguente programma,\ngenerera' una tavolo da gioco tipico dell'hockey da tavolo.\n");
    printf("Strutturato in 3 livelli di difficolta' dovrete battere\nin sucessione i nostri 3 professori.");
    printf("\n\nMuovi la barra con le freccie su' e giu'\nLancia il disco con un tasto qualsiasi.");
    printf("\n\nInserisci il tuo nome (4 caratteri)");
    scanf("%s", nome);

    system("color 1f");

nome[0] = toupper(nome[0]);
    nome[1] = toupper(nome[1]);
    nome[2] = toupper(nome[2]);
    nome[3] = toupper(nome[3]);

    strcpy(avver, gand);

    srand(time(NULL));
/*Inizializza la griglia*/

/*Muro*/
i = 0;
        for(j=0;j<c;j++){
            v[i][j] = '#';
        }
/*Muro*/
i = 19;
        for(j=0;j<c;j++){
            v[i][j] = '#';
        }

/*Muro*/
j = 34;
        for(i=1;i<r-1;i++){
            v[i][j] = ' ';
        }

/*Spazi vuoti*/
printf("\n");
for(i=1;i<r-1;i++){
        for(j=0;j<c-1;j++){
             v[i][j] = ' ';
        }
    }
/*posizione iniziale e lunghezza barra*/
pb = 8;
lb = 4;

/*Inizializzo la barra nella griglia*/
v[pb][0] = nome[0];
v[pb+1][0] = nome[1];
v[pb+2][0] = nome[2];
v[pb+3][0] = nome[3];

/*posizione riga e colonna iniziale della pallina*/
ppr = 9;
pbr = 9;
ppc = 1;

/*Cicla finche' non hai vinto o perso*/
while (lose==0 && win ==0){
m=0;
if(kbhit()){   /*esegui se viene premuto un tasto e immagazzinalo in m */
m = getch();

if (primo == 1){
    a = rand()%2+1;
    primo =0;}

j = 0;

/*se m vale 77 (freccia a destra) sposta ogni componente della barra di una posizione a destra*/
if (m == 80&&(pb+lb)<r-1){
pb++;
}

/*se m vale 75 (freccia a destra) sposta ogni componente della barra di una posizione a destra*/
if (m == 72&&(pb)>1){
pb--;
}
j = 0;
        for(i=1;i<r-1;i++){
            v[i][j] = ' ';
        }
v[pb][0] = nome[0];
v[pb+1][0] = nome[1];
v[pb+2][0] = nome[2];
v[pb+3][0] = nome[3];

}
/*Cicla ogni 200 millisecondi*/
if (clock()>=(t+100)){
    t = clock();
    if (level == 3 && timeg<103)
        timeg+=0.5;

/*opzioni del'andamento pallina*/
    switch(a){
        case 1:    /*verso 45°*/
            v[ppr][ppc] = ' ';


             ppr--;
             ppc++;          /*se colpisce la riga*/
            if (v[ppr][ppc]!=' '){  /*se uguale a mattone mangia, se muro fermati prima, andamento simmetrico rispetto la bisettrice dell'angolo di incidenza*/
                a = 2;
                if(v[ppr][ppc] == '#')
                ppr++;

            }

            if (ppc==34&&v[ppr][ppc]==' '){ /*se cade fuori dalla barra, perdi*/
                win =1;

                }   /*se colpisce la colonna*/
            if (v[ppr][ppc]!=' '){/*se uguale a mattone mangia, se muro fermati prima, andamento simmetrico rispetto la bisettrice dell'angolo di incidenza*/
                a = 4;
                ppc--;

            }
            v[ppr][ppc] = '@';
            break;
        case 2: /* verso 135°*/
            v[ppr][ppc] = ' ';

            ppc++;
            ppr++; /*se colpisce la colonna, muro in questo caso*/
            if (ppc==34&&v[ppr][ppc]==' '){ /*se cade fuori dalla barra, perdi*/
                win =1;

                }
            if (v[ppr][ppc]!=' '){
                a = 3;  /*cambia direzione*/
                ppc--; /*ma non mangiare muro..non buono!*/
            }
              /*se colpisce la riga*/
            if(v[ppr][ppc] == '#'){
                ppr--;
            a = 1;
            }
            v[ppr][ppc] = '@';
            break;
        case 3: /*verso 225°*/
            v[ppr][ppc] = ' ';
            ppr++;
            ppc--;    /*se colpisce la colonna, muro in questo caso*/
           if (ppc==0&&v[ppr][ppc]==' '){ /*se cade fuori dalla barra, perdi*/
                lose =1;
                break;
                }
            if (v[ppr][ppc]!=' '){
                if (ppr<(pb+2)) /*se colpisce la barra sul lato di arrivo della pallina respingila nella stessa direzione contraria altrimenti simmetrica rispetto la bisettrice*/
                a = 1;
                else{
                    if(v[ppr][ppc]==nome[2])
                        a = 5;
                    else
                        a = 2;
                }
                ppc++;
                }

            if(v[ppr][ppc] == '#'){
                ppr--;
            a = 4;
            }
            v[ppr][ppc] = '@';
            break;
        case 4: /* verso 315°*/
            v[ppr][ppc] = ' ';
            ppr--;   /*se colpisce la riga*/
            ppc--;    /*se colpisce la colonna*/
             if (ppc==0&&v[ppr][ppc]==' '){ /*se cade fuori dalla barra, perdi*/
                lose =1;
                break;
                }
            if (v[ppr][ppc]!=' '){
                if (ppr<(pb+2)) /*se colpisce la barra sul lato di arrivo della pallina respingila nella stessa direzione contraria altrimenti simmetrica rispetto la bisettrice*/
                a = 1;
                else{
                    if(v[ppr][ppc]==nome[2])
                        a = 5;
                    else
                        a = 2;
                }
                ppc++;
            }
            if(v[ppr][ppc] == '#'){
                ppr++;
            a = 3;
            }
            v[ppr][ppc] = '@';
            break;
        case 5: /*verso 90°*/
            v[ppr][ppc] = ' ';
            ppc++;  /*se colpisce la riga*/
            if (v[ppr][ppc]!=' '){
                a = 6;
                ppc--;  /*non mangiare muro*/
                v[ppr][ppc] = '@';
                break;}
            v[ppr][ppc] = '@';
            break;
        case 6: /*verso 270°*/
            v[ppr][ppc] = ' ';
            ppc--;    /*se colpisce la riga*/
            if (ppc==0&&v[ppr][ppc]==' '){ /*se finisce fuori dalla barra, perdi*/
                lose =1;
                break;
                }
            if (v[ppr][ppc]!=' '){
                if (ppc<(pb+2))/*se colpisce la barra sul lato di arrivo della pallina respingila nella stessa direzione contraria altrimenti simmetrica rispetto la bisettrice*/
                a = 1;
                else{
                    if(v[ppr][ppc]==nome[2]) /* se colpisce al centro, direzione 90°*/
                        a = 5;
                    else
                        a = 2;
                }
                ppc++;
                v[ppr][ppc] = '@';
                break;}
            v[ppr][ppc] = '@';
            break;
    }
if (clock()>t2+timeg){
        t2 = clock();
if (ppr > pbr && ppr>2 && ppr <17 )
pbr++;
if (ppr < pbr && ppr>2 && ppr <17 )
pbr--;
}
if (pbr>2 && pbr <17){
j = 34;
        for(i=1;i<r-1;i++){
            v[i][j] = ' ';
        }

v[pbr-2][34] = avver[0];
v[pbr-1][34] = avver[1];
v[pbr][34] = avver[2];
v[pbr+1][34] = avver[3];
v[pbr+2][34] = avver[4];
}
/*visualizza la griglia aggiornata*/

}

if (clock()>=(t1+100)){
        system("cls");
    t1 = clock();
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%c ", v[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n");

}
if (lose == 1) { /*se hai perso*/
    system("cls");
    system("color 4e");
    printf("\nHai perso!");}

if (win == 1){
system("cls");
 win = 0;
    if (level == 1){
            system("color 4e");
    printf("\nHai battuto Gandino!!\nPronto per il match contro Musso??\nPremi un tasto per continuare");
    ppr = getch();
    strcpy(avver, musso);
    timeg = timem;
    system("color 3b");
}
if (level == 2){
        system("color 4e");
    printf("\nSei stato bravo, hai battuto Musso!!\nMa il piu' temibile e' in arrivo...\nPronto per il match contro Scalerandi??\nPremi un tasto per continuare");
    ppr = getch();
    strcpy(avver, scal);
    timeg = times;
    system("color 5c");
}
if (level == 3){
        system("color 4e");
    printf("\nComplimenti!!!\nSei ufficialmente pronto per l'esame di Fisica I");
    win = 1;

}
    level++;
    ppr = 9;
    pbr = 9;
    ppc = 1;
    pb = 8;
    primo = 0;
}
}



    return 0;
}
