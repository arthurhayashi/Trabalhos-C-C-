#include <stdio.h>
 
int main() {
 
   int A,B,C,D,X;
   scanf ("%d %d %d %d", &A, &B, &C, &D);
   X=A%2;
   if ((B>C)&&(D>A)&&(C+D>A+B)&&(C>0)&&(D>0)&&(X==0)){
	printf("Valores aceitos\n");
	}
	else{
		printf("Valores nao aceitos\n");
	}
	
    return 0;
}
