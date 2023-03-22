#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "FilaVoo.h"

int main(){

fila *F, *FP;
	int ut, aviao, numeracaoA, prior, i;
	char tip;
	int continua = 1;
    //Inicializaçao das duas filas
    F=iniciaFilaProvisoria(F);//fila responsável pela ordem de chegada dos aviões
    FP=iniciaFilaProvisoria(FP);//fila responsável pela pista dos aviões
    // inserção dos aviões na fila F
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
    //exibe a ordem de chegada dos aviões
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
		//exibe o layout contendo a informação de unidades de tempo e estilizado com uma formatação para formar a figura do aviao
		for (aviao=1; aviao<=2; aviao++){// Apenas 2 aviões são liberados para as pistas deacordo com a sua prioridade
			if (!verificaFilaVazia(F)){//É feita uma verificação se a fila está vazia antes
				F=removeFProvisoria(F, &numeracaoA, &tip,&prior);//é removido os aviões da fila de chegada que serão inseridos na fila da pista
				FP=insereFProvisoria(FP, numeracaoA, tip, prior);
			}
		}
		printf("\nFILA DE AVIOES A SEREM LIBERADOS: ");
		exibe(FP);
        // exibe a fila responsável pelas pistas
		if ((ut%3)&&(continua)){
				printf("\n..........................................................................................");
				printf("\nAGUARDANDO CONFIRMACAO PARA LIBERAR A PISTA");//tela responsável por segurar até a terceira rotação para liberar a pista
		}
		else{
			for (i=1; i<=2;i++){
				if (FP != NULL){// é verificado se a fila da pista está vazia
					FP=removeFProvisoria(FP, &numeracaoA, &tip,&prior);// remove da pista
					printf("\n..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  .. ..  ..  ...");
					printf("\n__________________________________________________________________________________________");
					printf("\nPISTA %d: Aviao %d em partida", i,numeracaoA);// exibe os avioes que vão ser liberados
					printf("\n__________________________________________________________________________________________");
					printf("\n..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  .. ..  ..  ...");
				}
				else{
					printf("\nTODOS OS AVIOES FORAM LIBERADOS - FILA VAZIA");// mensagem de pista vazia
					continua = 0;
				}
			}
			if (!verificaFilaVazia(FP)){
					printf("\nFILA DE AVIOES A SEREM LIBERADOS: ");// mensagem que vai aumentando os aviões que vão serem liberados
			        exibe(FP);
			}
		}
	}
}

