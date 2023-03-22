#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>

typedef struct tipoNo{
int info;
int soma;
struct tipoNo *prox;
int lista;
}no;
no* inic(no* lista){ // Iniciar
	lista = NULL; // Atribui NULL mostrando que a lista está vazia
	return lista;
}
void imprimeLista(no*L){
no*P;
P=L;
int soma;

printf("Exibe itens da lista\n");
    while(P!=NULL){
        printf("%d ", P->info);
        soma+= P->info;
        P=P->prox;
    }
    printf("\n");
    printf("SOMA EH: %d",soma);
}
no* remover_valor_final(no* *lista){
	no* ultimo;
	no* penultimo;
	if(*lista == NULL){
        printf("\n\n >> Lista vazia << \n\n");
        return 0;// Não faz nada
    }
    else{
        ultimo = (*lista)->prox;
		penultimo = (*lista)->prox;
        while(ultimo->prox!=NULL){
            penultimo=ultimo;
            ultimo=ultimo->prox;
        }
        penultimo->prox=NULL;
    }
}
int main(){
    no*ptrLista;
    ptrLista = inic(ptrLista);
    no*L=NULL;
    no*L1=NULL;
    no*L2=NULL;
    L=(struct tipoNo*) malloc(sizeof(struct tipoNo*));
    L->info = 10;
    L->lista =10;
    L1=(struct tipoNo*) malloc(sizeof(struct tipoNo*));
    L1->info = 20;
    L1 ->lista =20;
    L2=(struct tipoNo*) malloc(sizeof(struct tipoNo*));
    L2->info = 15;
    L2 ->lista =20;
    L->prox=L1;
    L1->prox= L2;
    L2->prox= NULL;
    if(L)
        imprimeLista(L);
        ptrLista = remover_valor_final(&ptrLista);
    return 0;
}
