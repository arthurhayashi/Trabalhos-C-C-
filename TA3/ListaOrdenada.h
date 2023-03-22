/*
 * Lista_Ordenada.h
 * LISTA ENCADEADA ORDENADA
*/
#include <malloc.h>

typedef struct NoTag {
	int info;
	struct NoTag *link;
} no;

no *inicializaLO(no *L) {
	L = NULL;
	return L;
}

void exibeLO(no *L) {
	no *P;
	 
	P = L;	// P recebe o endereco do primeiro no da lista
	
	printf("\n Exibe itens da Lista Ordenada");	
	while(P != NULL) {
		printf("\n %d", P->info);	
		P = P->link;
	}
}

no *insereLO(no *L, int x) {
	no *N, *P, *ANT;

	N = (no *) malloc (sizeof(no));
	N->info = x;
	 
	// SE  a lista estiver vazia
	if (L == NULL){
		L = N;
		N->link = NULL;
	}
	else {
		P = L;	// P recebe o endereco do primeiro no da lista
	
		while((P != NULL) && (x >= P->info)) {
			ANT = P;
			P = P->link;
		}
		// o no sera o primeiro do lista
		if (P == L) {			
			N->link = L;
			L = N;
		}
		else {
			ANT->link = N;
			N->link = P;
		}
	} 
	return L;
}



