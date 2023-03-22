#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

 void main(){
     // variáveis
     int a;
     float b;
     char c;
     bool d;

     //passando valores
     a = 8;
     b = 7.5;
     c = 'a';
     d = true; //true = a 1 e false = a 0

     //exibir os valores na tela
     printf("o valor de a eh : %d", a);
     printf("\n o valor de b eh = %.1f", b);
     printf("\n o valor de c eh = %c", c);
     printf("\n o valor de d eh = %d", d);

     //verificar os vlaores
     scanf("%d", &a);
     scanf("%.1f", &b);
     scanf(" %c", &c);
     scanf("%d", &d);

     //exibir novamente os valroes
     printf("\n o valor de a eh = %d", a);
     printf("\n o valor de b eh = %.1f", b);
     printf("\n o valor de c eh = %c", c);
     printf("\n o valor de d eh = %d", d);

     //pausando
     system("pause");

 }
