#include <stdio.h>
#include <stdlib.h>

// Q1
int **allouer(int n){
	int i;
	int **mat;
	//crée un tab de n ptr d'ent. Chaque ptr représente une ligne de la matrice.
	mat=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		*(mat+i)= (int*)malloc(n*sizeof(int)); 
	}
	return mat;
}

// Q2
void saisir(int **mat, int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("saisir mat[%d][%d]",i,j);
			scanf("%d",*(mat+i)+j); // &mat[i][j]
		}	
	}
}

// Q3
void afficher(int **mat, int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d \t",*(*mat+i)+j);
		}
		printf("\n");
	}
}

int magique(int **mat,int n){
	int som=0;
	int somsuiv;
	int ok=1;
	int i,j;
	// init som 
	for(j=0;j<n;j++){
		som += mat[0][j]; // 00 01 02 ...
	}
	// vérifier lignes
	i=1;
	while(ok && i<n){
		somsuiv=0;
		for(j=0;j<n;j++){
			somsuiv += mat[i][j];
		}
		if(somsuiv!=som)
		ok=0;
		i++;
	}
	// vérifier colonnes
	for(j=0;j<n;j++){
		somsuiv =0;
		for(i=0;i<n;i++){
			somsuiv += mat[i][j];
		}
		if (somsuiv!=som)
		ok=0;
		j++;
	}
	//vérifier diagonale principale
	if (ok){
	somsuiv=0;
	for(i=0;i<n;i++){
		somsuiv+=mat[i][i];
	}
	if ( somsuiv != som)
	ok=0;
	}
	//vérifier diagonale principale inverse
	if (ok){
	somsuiv=0;
	for(i=0;i<n;i++){
		somsuiv+=mat[i][n-i-1];
	}
	if ( somsuiv != som)
		ok=0;
	}
	return ok;
}


int main() {
	int **mat;
	int n,ok;
	printf("saisir dimension matrice");
	scanf("%d",&n);
	mat=allouer(n);
	saisir(mat,n);
	afficher(mat,n);
	ok = magique(mat,n);
	//printf(" %d\n",ok);
	if (ok) printf("carre magique\n");
	else printf("carre n'est pas magique\n");
	
	return 0;
}
