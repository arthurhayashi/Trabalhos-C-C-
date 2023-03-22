#include <malloc.h>

typedef struct no{
    int num_voo;
    char tipo;
    int priorit;
    struct no *link;
}fila;

fila *iniciaFilaProvisoria(fila *L){//inicializa  a fila
    L=NULL;
    return L;
}

fila* insereFProvisoria(fila *L,int numAviao,char tip,int prioridade){// insere na fila da pistade acordo com a prioridade

    fila *N, *P, *ANT;

    N = (fila *) malloc(sizeof(fila));
    N->num_voo = numAviao;
    N->tipo = tip;
    N->priorit = prioridade;

    if (L == NULL) {
        L = N;
        N->link = NULL;
    }
    else {
        P = L;

        while ((P != NULL) && (prioridade >= P->priorit)) {
            ANT = P;
            P = P->link;
        }
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

fila* insereFilaChegada(fila *L,int numAviao,char tip,int prioridade) {//insere na fila de chegada onde será exibida para o usuário os avios que vao chegar antes ou depois
	fila *P, *N;

	N = (fila *) malloc (sizeof(fila));
	N->num_voo = numAviao;
	N->tipo = tip;
	N->priorit = prioridade;
	N->link = NULL;

	if (L == NULL){
		L = N;
	}
	else {
		P = L;

		while(P->link != NULL) {
			P = P->link;
		}
		P->link = N;
	}
	return L;
}

fila *removeFProvisoria(fila *L, int *n,char *tip ,int * prior) {//função para remover itens da fila da pista
	fila *AUX;

	if (L != NULL) {
		*n = L->num_voo;
		*tip = L->tipo;
		*prior = L->priorit;
		AUX = L;
		L = L->link;
		free(AUX);
	}
	return L;
}

int verificaFilaVazia(fila *L) {// verifica se a fila principal está vazia
	if (L == NULL)
		return 1;
	else
		return 0;
}

void exibe(fila *L)//exibe os itens que vao estar dentro a fila responsavel por representar as pistas
{
    fila *P = L;

    while (P != NULL) {
        printf("Aviao: %d-Tipo :%c-Prioridade: %d : ",P->num_voo, P->tipo, P->priorit);
        P = P->link;
    }
}
