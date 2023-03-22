#include <stdio.h>
#include <stdlib.h>
#include "FilaPrioridadesLE.h"

int main(void)
{
   	no *F, *FP;
	int ut, cliente, data, prior, i;
	int continua = 1;
	
    F=inicializaFP(F);    	
    FP=inicializaFP(FP);
    
	F=insereFilaChegada(F, 65, 1);
	F=insereFilaChegada(F, 66, 2);
	F=insereFilaChegada(F, 67, 2);
	F=insereFilaChegada(F, 68, 1);
	F=insereFilaChegada(F, 69, 1);
	F=insereFilaChegada(F, 70, 2);
	F=insereFilaChegada(F, 71, 1);
	F=insereFilaChegada(F, 72, 2);
	F=insereFilaChegada(F, 73, 2);
	F=insereFilaChegada(F, 74, 2);

	printf("Imprime Lista de Clientes que devem chegar ao banco nesta ordem!\n");
	exibe(F);

	for(ut=1; continua ; ut++){
		printf("\n*******************************************************************************************");
		printf("\n***********************************  UNIDADE DE TEMPO: %d   ********************************", ut);
		printf("\n*******************************************************************************************");
		for (cliente=1; cliente<=2; cliente++){
			if (!verificaSeVazia(F)){
				F=removeFP(F, &data, &prior);
				FP=insereFP(FP, data, prior);
			}
		}
		printf("\nFILA DE CLIENTES A SEREM ATENDIDOS: ");
		exibe(FP);
		
		if ((ut%2)&&(continua)){
			for (i=1; i<=2;i++){
				if (FP != NULL){
					FP=removeFP(FP, &data, &prior);
					printf("\n..........................................................................................");
					printf("\nCAIXA %d: atendimento do cliente %c", i,data);
					printf("\n..........................................................................................");
				}
				else{
					printf("\nTODOS OS CLIENTES FORAM ATENDIDOS - FILA VAZIA");
					continua = 0;
				}
			}
			if (!verificaSeVazia(FP)){
					printf("\nFILA DE CLIENTES A SEREM ATENDIDOS: ");
			        exibe(FP);
			}
		}
		else{
				printf("\n..........................................................................................");
				printf("\nCAIXAS EM ATENDIMENTO");
		}
	}
}
