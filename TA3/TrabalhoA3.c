#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "FilaVoo.h"

int main(){

fila *F, *FP;
	int ut, aviao, numeracaoA, prior, i;
	char tip;
	int continua = 1;
    //Inicializa�ao das duas filas
    F=iniciaFilaProvisoria(F);//fila respons�vel pela ordem de chegada dos avi�es
    FP=iniciaFilaProvisoria(FP);//fila respons�vel pela pista dos avi�es
    // inser��o dos avi�es na fila F
	F=insereFilaChegada(F, 652,'P', 2);
	F=insereFilaChegada(F, 616,'P', 2);
	F=insereFilaChegada(F, 657,'D', 3);
	F=insereFilaChegada(F, 618,'P' ,1);
	F=insereFilaChegada(F, 639,'P', 2);
	F=insereFilaChegada(F, 720,'D',3);
	F=insereFilaChegada(F, 741,'P', 1);
	F=insereFilaChegada(F, 732,'P', 2);
	F=insereFilaChegada(F, 722,'P',2);
	F=insereFilaChegada(F, 754,'P',1);
	F=insereFilaChegada(F, 744,'D',3);
    F=insereFilaChegada(F, 222,'P', 2);
	F=insereFilaChegada(F, 322,'P',2);
	F=insereFilaChegada(F, 944,'P',2);
	F=insereFilaChegada(F, 144,'D',3);
    //exibe a ordem de chegada dos avi�es
	printf("Imprime Lista de avioes que devem chegar ou partir nesta ordem!\n");
	exibe(F);

	for(ut=1; continua ; ut++){
        printf("\n                              |                                                                                 |");
        printf("\n                              |                                                                                 |");
        printf("\n______________________________|_______________________________                    ______________________________|_______________________________");
        printf("\n                    ----\\--||___||--/----                                                             ----\\--||___||--/----");
		printf("\n                         \\ :==^==: /***********************************************************************\\ :==^==: /");
		printf("\n                          \\|  o  |/*********************  UNIDADE DE TEMPO: %d   ***************************\\|  o  |/", ut);
		printf("\n                           \\_____/***************************************************************************\\_____/");
		printf("\n                          ^/  |  \\^                                                                         ^/  |  \\^");
        printf("\n                          U   |   U                                                                         U   |   U");
        printf("\n			      U                                                                                 U");
		//exibe o layout contendo a informa��o de unidades de tempo e estilizado com uma formata��o para formar a figura do aviao
		for (aviao=1; aviao<=2; aviao++){// Apenas 2 avi�es s�o liberados para as pistas deacordo com a sua prioridade
			if (!verificaFilaVazia(F)){//� feita uma verifica��o se a fila est� vazia antes
				F=removeFProvisoria(F, &numeracaoA, &tip,&prior);//� removido os avi�es da fila de chegada que ser�o inseridos na fila da pista
				FP=insereFProvisoria(FP, numeracaoA, tip, prior);
			}
		}
		printf("\nFILA DE AVIOES A SEREM LIBERADOS: ");
		exibe(FP);
        // exibe a fila respons�vel pelas pistas
		if ((ut%3)&&(continua)){
				printf("\n..........................................................................................");
				printf("\nAGUARDANDO CONFIRMACAO PARA LIBERAR A PISTA");//tela respons�vel por segurar at� a terceira rota��o para liberar a pista
		}
		else{
			for (i=1; i<=2;i++){
				if (FP != NULL){// � verificado se a fila da pista est� vazia
					FP=removeFProvisoria(FP, &numeracaoA, &tip,&prior);// remove da pista
					printf("\n..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  .. ..  ..  ...");
					printf("\n__________________________________________________________________________________________");
					printf("\nPISTA %d: Aviao %d em partida", i,numeracaoA);// exibe os avioes que v�o ser liberados
					printf("\n__________________________________________________________________________________________");
					printf("\n..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  .. ..  ..  ...");
				}
				else{
					printf("\nTODOS OS AVIOES FORAM LIBERADOS - FILA VAZIA");// mensagem de pista vazia
					continua = 0;
				}
			}
			if (!verificaFilaVazia(FP)){
					printf("\nFILA DE AVIOES A SEREM LIBERADOS: ");// mensagem que vai aumentando os avi�es que v�o serem liberados
			        exibe(FP);
			}
		}
	}
}

