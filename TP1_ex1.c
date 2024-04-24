#include <stdio.h>
#include <stdlib.h>

//q1 : fonction allouer
int* Allouer(int n) {
	int* T;
	T=(int*)malloc(n*sizeof(int));
	return T; 
}
// q2 : fonction saisie
void saisie(int* T, int n) {
	int i;
	for(i=0;i<n;i++) {
		printf("saisir elt du tableau num %d :\t",i);
		scanf("%d",T+i); 
	} 
}
//q3 : fonction affiche
void affiche(int *T,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d \t",*(T+i));
	}
	
}
// q4 fonction insereValeurs
int *Reallouer (int*T, int taille) {
		T=(int *)realloc(T,taille*sizeof(int));
	return T; 
	}
void insereValeurs(int *T, int *taille, int ind, int N) {
	int i,j;
	// réallouer taille tab
	T=Reallouer(T,(*taille));
	//Vérification si l'indice est en dehors des bornes du tableau
	if((ind>*taille)||(ind<0)) printf("Insertion impossible");
	// ind est dans l'intervalle
	else{ 
		for(j=0;j<=N;j++) {				
			if (j%2!=0) { //Vérifier nbr impaires
					(*taille)++;
					T=Reallouer(T,(*taille));
					for(i=*taille-1;i>(ind-1);i--) // Décalage des éléments vers la droite
						*(T+(i+1))= *(T+i);
					*(T+ind)=j;
					ind=ind+1;
			}
		}
	}
}
//q5
void supprimeValeur(int * T, int *taille){
	int i,j; int k;
	T=Reallouer(T, (*taille));
	// Supprimer les doublons
	int fin=0; // var pr contrôler les doubles
	while (fin!=1) {
		fin=1;
		// parcourir tableau pr trouver les doublons
		for (i=0;i<(*taille)-1;i++) {
			for(j=i+1;j<(*taille);) {
				if (*(T+i)==*(T+j)) {//doublon trouvé
					//Décaler les éléments vers la gauche pour supprimer le doublon
					for (k = j; k < (*taille); k++) {
						*(T+k) = *(T+k+1); }
					fin = 0;
					(*taille)--; 
				}
				else 
					j++; //passer à l'élément suivant dans la recherche des doublons
            }
        }
	}
	T=Reallouer(T, (*taille)); 	
}


int main() {
	int n;
	printf("saisir taille tableau ");
	scanf("%d",&n);
	int* T1 = Allouer(n);
	printf("******** saisie ********* \n");
	saisie(T1,n);
	printf("******** affichage ********* \n");
	affiche(T1,n);
	printf("\n******** test insertion avec indice = 1 et N=7 ********* \n");
	insereValeurs(T1,&n,1,7);
	printf("\n affichage après insertion \n");
	affiche(T1,n);
	printf("\n\n");
	supprimeValeur(T1, &n);
	printf("\n affichage après suppression des doublons \n");
	affiche(T1,n);
	return 0;
}
