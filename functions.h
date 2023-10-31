int i;  //un variable globale qu'on va l'utiliser presque dans tout le programme

//une structure qui stocke la date de naisance de chaque etudiants
typedef struct date{
    char dat[10];
}Date;

//une structure qui stocke l'adresse de chaque etudiant
typedef struct adresse{
    int num;
    char ville[20];
}Add;

typedef struct etudiant{
    char nom[50],prenom[50],CNE[12];
    Date date1;
    Add Adresse1;
}Etudiant;

//Prototypes des fonctions
Etudiant* Saisie(int taille);
void Afficher(Etudiant *LEtd,int taille);
int menu();
void AfficheParCNE(Etudiant *LEtd, char cne[12], int N);
void AfficheParNOM(Etudiant *LEtd, char nom[50], int N);
void SupprimerEtdParCNE(Etudiant *LEtd, char cne[12], int *N);
void echange_Etd(int i,int j,Etudiant *LEtd);
void ajout(Etudiant *LEtd,int *taille);
void tri_selection(Etudiant *LEtd,int n);
void mod(int j, Etudiant* LEtd);
void Sauvegarder(Etudiant*T,int N);
void triparCNE(Etudiant *LEtd, int n);
Etudiant *cherchdic(Etudiant *LEtd,int N);

//Fonction Saisie() qui permet de stocker les donnees des etudiants
Etudiant* Saisie(int taille){
    Etudiant *ptr;
    ptr = (Etudiant*)malloc(taille*sizeof(Etudiant));
    for(i=0;i<taille;i++){
        printf("Veuillez saisir le nom le prenom et le CNE de l'etudiant n %d : ",i+1);
        printf("\nPrenom  : ");
        scanf("%s",(ptr+i)->prenom);
        printf("Nom : ");
        scanf("%s",(ptr+i)->nom);
        printf("CNE    : ");
        scanf("%s",(ptr+i)->CNE);
        printf("Veuillez saisir la date de naissance de l'etudiant n %d sous la forme (jour/mois/annee): ",i+1);
        scanf("%s",(ptr+i)->date1.dat);
        printf("Veuillez saisir l'adresse de l'etudiant n %d : ",i+1);
        printf("\nVille: ");
        scanf("%s",(ptr+i)->Adresse1.ville);
        printf("numero : ");
        scanf("%d",&(ptr+i)->Adresse1.num);
        printf("               ---------------------              \n");
    }
    //le retour doit etre de type Etudiant
    return ptr;

}

//fonction Afficher qui permet d'afficher les donnees des etudiants
void Afficher(Etudiant *LEtd,int taille){
    for(i=0;i<taille;i++){
        printf("\n");
        printf("\nL'etudiant n %d",i+1);
        printf("\nLe nom et le prenom : %s %s",(LEtd+i)->nom,(LEtd+i)->prenom);
        printf("\nCNE                 : %s",(LEtd+i)->CNE);
        printf("\nDate De Naissance   : %s",(LEtd+i)->date1.dat);
        printf("\nL'adresse           : ville  %s / num  %d",(LEtd+i)->Adresse1.ville,(LEtd+i)->Adresse1.num);
    }
}

int menu(){
    int choix;
    printf("\nPour afficher les informations des etudiants veuillez taper sur ---1");
    printf("\nPour afficher les informations des etudiants par CNE veuillez taper sur ---2");
    printf("\nPour afficher les informations des etudiants par nom veuillez taper sur --3");
    printf("\nPour supprimer l'un des etudiants par son CNE veuillez taper sur ---4");
    printf("\nPour faire echanger deux etudiants par indice veuillez taper sur ---5");
    printf("\nPour ajouter des autres etudiants a la liste veuillez taper sur ---6");
    printf("\nPour trier la liste des etudiants Veuillez taper sur ---7");
    printf("\nPour sauvegarder les donnees dans un fichier veuillez saisir sur ---8");
    printf("\nPour modifier les informations d'un etudiant par indice veuillez saisir sur ---9");
    printf("\nPour recherche un etudiant par dichotomie veuillez saisir sur ---10");
    printf("\nPour quitter le programme veuillez taper sur ---11\n");
    printf("\nVeuillez saisir votre choix: ");
    scanf("%d",&choix);
    return choix;
}

/*fonction qui permet d'afficher les information d'un etudiant
                   a partir de son identifiant (saisie par l'utilisateur)*/
void AfficheParCNE(Etudiant *LEtd, char cne[12], int N){
     int ex=0,j=0;
     for(i=0;i<N;i++){
        if(strcmp(cne,(LEtd+i)->CNE)==0){
            j=i;  //on utilise la fonction strcmp() pour comparer entre deux chaines de caracteres
            ex=1;
            break;
        }
     }
     if(ex==1){
     printf("\nles informations de l'etudiant N %d\n",i+1);
     printf("\nle nom               : %s\n",(LEtd+j)->nom);
     printf("le prenom            : %s\n",(LEtd+j)->prenom);
     printf("CNE                  : %s\n",(LEtd+j)->CNE);
     printf("la date de naissance : %s\n",(LEtd+j)->date1.dat);
     printf("adress :\n");
     printf("num                  :%d\n",(LEtd+j)->Adresse1.num);
     printf("ville                :%s\n",(LEtd+j)->Adresse1.ville);
     }
     else{
        printf("\nCe identifiant n'existe pas\n");
     }
  }

/*fonction qui permet d'afficher les information d'un etudiant
                   a partir de son NOM (saisie par l'utilisateur)*/
void AfficheParNOM(Etudiant *LEtd, char nom[50], int N){
     int ex=0,j=0;
     for(i=0;i<N;i++){
        if(strcmp((LEtd+i)->nom,nom)==0){
            j=i;  //on utilise la fonction strcmp() pour comparer entre deux chaines de caracteres
            ex=1;
            break;
        }
     }
     if(ex==1){
     printf("\nles informations de l'etudiant N %d\n",i+1);
     printf("\nle nom               : %s\n",(LEtd+j)->nom);
     printf("le prenom            : %s\n",(LEtd+j)->prenom);
     printf("CNE                  : %s\n",(LEtd+j)->CNE);
     printf("la date de naissance : %s\n",(LEtd+j)->date1.dat);
     printf("adresse :\n");
     printf("num                  :%d\n",(LEtd+j)->Adresse1.num);
     printf("ville                :%s\n",(LEtd+j)->Adresse1.ville);
     }
     else{
        printf("\nCe nom n'existe pas\n");
     }
  }

/*une fonction qui permet de supprimer l'un des etudiants de la liste
                 A partir de son identifiant (saisie par l'utilisateur)*/
void SupprimerEtdParCNE(Etudiant *LEtd, char cne[12], int *N){
     int ex=0,j;
     for(i=0;i<*N;i++){
        if(strcmp(cne,(LEtd+i)->CNE)==0){
            j=i;
            ex=1;
            break;
        }
     }
     if(ex==1){
     (*N)--;
     printf("\n=suprime avec succes=\n");
     for(i=j;i<*N;i++){
            *(LEtd+i)=*(LEtd+i+1);
         }
     }
     else{
         printf("\nL'etudiant voulu n'existe pas ! \n");
     }
}

//Une fonction qui permet d'echanger le positions de deux etudiants par indice
void echange_Etd(int i,int j,Etudiant *LEtd){
    Etudiant temp; //on utilise un variable temporaire pour echanger les positions des etudiants dans la liste
    if(i == j){
        printf("\nL'echange est impossible !");
    }
    else{
        temp = *(LEtd+i);
        *(LEtd+i) = *(LEtd+j);
        *(LEtd+j) = temp;
    }
}


//Une fonction qui permet d'ajouter un etudiant a la liste
void ajout(Etudiant *LEtd,int *taille){
    int j;
    Etudiant *A,P;
    A=&P;
    (*taille)++;
    LEtd = realloc(LEtd,*taille);//on utilise fonction realloc() pour modififer la taille de la liste dynamiquement
    printf("entrez l'indice du nouveau etudiant : ");
    scanf("%d",&j);
    if(j > *taille){
        j = *taille;
    }
    printf("Veuillez saisir les donnees du nouveau etudiant");
    printf("\nentrer le nom et le prenom et la CNE de la nouvelle etudiant");
    printf("\nNom : ");
    scanf("%s",A->nom);
    printf("Prenom :");
    scanf("%s",A->prenom);
    printf("CNE : ");
    scanf("%s",A->CNE);
    printf("Date De Naissance sous la forme de (jour/mois/annee)  :\n");
    scanf("%s",A->date1.dat);
    printf("l'Adresse de l'etudiant  : \n");
    printf("Num : ");
    scanf("%d",&A->Adresse1.num);
    printf("Ville : ");
    scanf("%s",A->Adresse1.ville);
    for(i=*taille;i>=j;i--){
        *(LEtd+i)=*(LEtd+i-1);
    }
    *(LEtd+j-1)=*A;
}


void tri_selection(Etudiant *LEtd,int n){
    Etudiant temp;
    int min_idx,j;
    for(i=0;i<n-1;i++){
        min_idx = i;
        for(j=i+1;j<n;j++){
            if(strcmp((LEtd+j)->nom,(LEtd+min_idx)->nom)<0){
                min_idx = j;
            }
            else if(strcmp((LEtd+j)->nom,(LEtd+min_idx)->nom)==0 && strcmp((LEtd+j)->CNE,(LEtd+min_idx)->CNE)<0){
                    min_idx = j;
                    }
        }
        temp = *(LEtd+i);
        *(LEtd+i) = *(LEtd+min_idx);
        *(LEtd+min_idx) = temp;
    }
}

//Une fonction qui permet d'acceder aux informations d'un certain etudiant et les modifier
void mod(int j, Etudiant* LEtd){
    printf("entrez le nom et le prenom et la CNE de l'etudiant n %d",j+1);
    printf("\nNom : ");
    scanf("%s",(LEtd+j)->nom);
    printf("Prenom : ");
    scanf("%s",(LEtd+j)->prenom);
    printf("CNE : ");
    scanf("%s",(LEtd+j)->CNE);
    printf("entrez la date de naissance de l'etudiant n %d sous la forme de (jour/mois/annee) \n",j+1);
    scanf("%s",(LEtd+j)->date1.dat);
    printf("entrez la numero : \n",j+1);
    printf("num : ");
    scanf("%d",&(LEtd+j)->Adresse1.num);
    printf("ville : ");
    scanf("%s",(LEtd+j)->Adresse1.ville);
}

//Une fonction qui permet de sauvegarder les donnees des etudiants dans un fichier
void Sauvegarder(Etudiant*T,int N){
    FILE *ptr;
    int chr;
    printf("confirmer?\nsi oui entrer 1: ");
    scanf("%d",&chr);
    if(chr==1){
    ptr=fopen("file01.txt","a");//on utilise le mode "a" (appending) pour creer et ajouter du texte a la fin du fichier
    if(ptr==NULL){//On doit verifier s'il a assez d'espace dans la memoire ,sinon il va sortir du programme
        printf("La memoire n'est pas alloue\n");
        exit(0);
    }
    fprintf(ptr,"%s\n","les information des etudiant  : ");
    for(i=0;i<N;i++){
        fprintf(ptr,"-----------------------------\n");//la fonction fprintf() nous permettre d'ecrire  dans un fichier
        fprintf(ptr,"%s","le nom :");
        fprintf(ptr,"%s\n",(T+i)->nom);
        fprintf(ptr,"%s","le prenom : ");
        fprintf(ptr,"%s\n",(T+i)->prenom);
        fprintf(ptr,"%s","le CNE :");
        fprintf(ptr,"%s\n",(T+i)->CNE);
        fprintf(ptr,"%s","le date de naissance : ");
        fprintf(ptr,"%s\n",(T+i)->date1.dat);
        fprintf(ptr,"%s\n","l'adresse : ");
        fprintf(ptr,"%s","num :");
        fprintf(ptr,"%d\n",(T+i)->Adresse1.num);
        fprintf(ptr,"%s","la ville : ");
        fprintf(ptr,"%s\n",(T+i)->Adresse1.ville);
    }
    printf("\nLes donnees sont sauvegardes\n");
    fclose(ptr);//fclose() permet de fermer un flux prealablement ouvert
    }
    else
    printf("\nsauvegarde annule\n");
}

void triparCNE(Etudiant *LEtd, int n){
     int min_idx,j;
     Etudiant temp;
     for(int i = 0 ; i < n-1 ; i++)
     {
         min_idx = i;
         for( j = i+1 ; j < n ; j++){
             if( strcmp((LEtd+j)->CNE,(LEtd+min_idx)->CNE)<0)
             min_idx= j;
         }
         temp = *(LEtd+i);
         *(LEtd+i)=*(LEtd+min_idx);
         *(LEtd+min_idx)=temp;
     }
}

int o;
Etudiant *cherchdic(Etudiant *LEtd,int N){
   int a=0,b=N,m;
   o = 0;
   char cne[12];
   triparCNE(LEtd,N);//pour qu'on peut utilise le recherche dichotomoque il faut que la liste doit etre deja triee (Par CNE)
   printf("\nentrez le CNE d'etudiant : ");
   scanf("%s",cne);
   while(a<=b){
    m=(a+b)/2;
    if(strcmp((LEtd+m)->CNE,cne)==0){
        o = 1;
        return LEtd+m;
    }
    else if(strcmp((LEtd+m)->CNE,cne)<0)
        a=m+1;
    else if(strcmp((LEtd+m)->CNE,cne)>0)
         b=m-1;
   }
    if(a>b)
    printf("\nCe etudiant n'existe pas!");
}
