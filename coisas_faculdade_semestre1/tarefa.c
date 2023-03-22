#include <stdio.h>
#include <malloc.h>


int main(){

    int i;
    int aux0, aux1, aj;
    int *pnt;

    aux0 = 0;
    aux1 = 1;

    pnt =(int *) malloc(10 * sizeof(int));
    if(pnt == NULL){
        printf("falha na alocacao de memoria\n");
    }else{
        for(i = 0 ;i < 10; i++){
            aj = aux1 + aux0;
            aux0 = aux1;
            aux1 = aj;

            *(pnt + i) = aj;

            printf("%d\n",*(pnt+i));
        }
        free(pnt);
    }

    return 0;
}
