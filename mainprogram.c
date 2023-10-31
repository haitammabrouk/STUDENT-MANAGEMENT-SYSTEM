#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int i;

int main()
{
    int N,q=0;//N represente la taille de la liste
    int j;//un indice
    char cne[12];
    char NOM[50];
    int ch;//choix
    Etudiant *p,*etu;//"p" un pointeur pointe sur l'etudiant
    printf("Veuillez saisir le nombre des etudiants du classe : ");
    scanf("%d",&N);
    p = malloc(N*sizeof(Etudiant));//on utilise la fonction malloc pour allouer un tableau dynamiquement
    if(p == NULL){
        printf("La memoire n'est pas alloue");
        exit(0);
    }
    else{
        p = Saisie(N);
        printf("------------------------------------\n");
        do{
            ch = menu();
            switch(ch){
                case 1 : Afficher(p,N);
                         break;
                case 2 : printf("\nVeuillez saisir l'identifiant de l'etudiant: ");
                         scanf("%s",cne);
                         AfficheParCNE(p,cne,N);
                         break;
                case 3 : printf("\nVeuillez saisir le nom de l'etudiant: ");
                         scanf("%s",NOM);
                         AfficheParNOM(p,NOM,N);
                         break;
                case 4 : printf("\nVeuillez saisir l'identifiant de l'etudiant que vous voulez supprimer : ");
                         scanf("%s",cne);
                         SupprimerEtdParCNE(p,cne,&N);
                         break;
                case 5 : printf("\nVeuillez saisir le premier indice: ");
                         scanf("%d",&i);
                         printf("\nVeuillez saisir le deuxieme indice: ");
                         scanf("%d",&j);
                         if(i>N || j>N){
                            printf("\nL'echange est impossible !\n");
                            break;
                         }
                         echange_Etd(i-1,j-1,p);
                         break;
                case 6 : ajout(p,&N);
                         printf("\n=ajoute avec succes=\n");
                         break;
                case 7 : tri_selection(p,N);
                         break;
                case 8 : Sauvegarder(p,N);
                         break;
                case 9 : printf("Veuillez saisir l'indice de l'etudiant: ");
                         scanf("%d",&j);
                         if(j > N){
                            j = N;
                         }
                         mod(j-1,p);
                         break;
                case 10 : etu = cherchdic(p,N);//Le retour de la fonction cherchdic() est de type Etudiant*
                         if(o==1){
                            printf("les information de l'etudiant \n");
                            printf("le nom               : %s\n",etu->nom);
                            printf("le prenom            : %s\n",etu->prenom);
                            printf("CNE                  : %s\n",etu->CNE);
                            printf("la date de naissance : %s\n",etu->date1.dat);
                            printf("adresse :\n");
                            printf("num                  :%d\n",etu->Adresse1.num);
                            printf("ville                :%s\n",etu->Adresse1.ville);
                         }
                         break;
                case 11 : return 0;

            }
        }while(q==0);
    }
    free(p);//fonction free() sert a restituer l'espace que l'on avait alloue dynamiquement
    return 0;
}
