#include <stdio.h>
#include <stdlib.h>
#include "ListaOrdenada.h"

int main(void)
{

   no *L;
   char aux[10];
   int x;
   char choice[10];
   int c;

   L = inicializaLO(L);
   do 
   {
      printf("\n");
      printf("1 - Insere Item na Lista Ordenada\n");
      printf("2 - Lista Itens da Lista Ordenada\n");
      printf("3 - Sair\n");
      printf("\n Escolha: ");

      gets(choice);     
      c = atoi(choice);

      switch (c) {
         case 1: 
			printf(" \nEntre com o item a ser inserido: ");
			gets(aux);
			x = atoi(aux);
			L = insereLO(L,x);
            break;
         case 2: 
  		    exibeLO(L);
 			break;
         case 3: 
		    exit(0);
            break;
      };
   } while (c != 3);
}
