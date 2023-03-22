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

		while((P != NULL) && (x <= P->info)) {
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

no *removeLO(no *L, int x){
    no *P, *ANT;

        if (L==NULL){
            printf("Pilha vazia \n");
            return L;
        }
        else{
            P=L;
            ANT=L;
            while(P->link != NULL){

                if((x==(P->info))){
                    ANT->link=P->link;
                    ANT = P;
                    P = P->link;
                    free(ANT);
                    printf("item removido com sucesso!\n");
                    continue;
                }
                ANT = P;
                P = P->link;
            }

        }
        return L;
}



