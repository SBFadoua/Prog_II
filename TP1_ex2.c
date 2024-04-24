#include <stdio.h>
#include <stdlib.h>

//---------------q1 fct alloue matrice pascal--------------------------------------------
//fct retourne un ptr vers un ptr d'entiers (int**) et prend un entier n en paramètre
/*
exemple MP / n=5 --> 5 lignes
1  i=1
11  i=2
121  i=3
1331  i=4
14641  i=5
*/
int **alloue(int n){
	// Déclaration d'un ptr vers un ptr d'entiers pr stocker la matrice.	
	int i;
	int **mat;

	//crée un tab de n ptr d'ent. Chaque ptr représente une ligne de la matrice.
	mat=(int**)malloc(n*sizeof(int*));

	//boucle pr allouer dynamiquement la ième ligne de la matrice
	for(i=0;i<n;i++){
		*(mat+i)= (int*)malloc((i+1)*sizeof(int)); // i+1 pour éviter taille nulle pr la première ligne de mat
	}
	return mat;
}

//---------------q2 fct remplit matrice pascal--------------------------------------------
void remplir(int **mat, int n){
	int i,j;
	for(i=0;i<n;i++){
		//parcourir chaque ligne i
		for(j=0;j<=i;j++){
			// les bords =1
			if((i==j)||(j==0)){
				*(*(mat+i)+j)=1;
			}
			else{
				*(*(mat+i)+j)=*(*(mat+(i-1))+(j-1))+*(*(mat+(i-1))+(j));
				//mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];	
			}
		}
	}
}
//---------------q3 fct affiche matrice pascal--------------------------------------------
void afficher(int **mat, int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			printf("%d ",*(*(mat+i)+j));
		}
		printf("\n");
	}
}
void liberer(int **mat, int n) {
    int i;
	for (i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}


int main() {
	int **mat;
	int n;
	printf("saisir n ");
	scanf("%d",&n);
	mat=alloue(n);
	remplir(mat,n);
	afficher(mat,n);
	liberer(mat,n);
	return 0;
}
