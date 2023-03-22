#include <stdio.h>
typedef struct{
    int codigo;
    float valor;
}Mercadoria;

    void alteravalores(Mercadoria*prd){
        prd-> codigo = 7321;
        prd-> valor = 12;
    }

int main(){
    Mercadoria produto;
    produto.codigo=31231;
    produto.valor=745.23;
    printf("Codigo do produto: %d \n", produto.codigo);
    printf("Valor do produto: %.2f \n", produto.valor);
    alteravalores(&produto);
    printf("Codigo do produto: %d \n", produto.codigo);
    printf("Valor do produto: %.2f \n", produto.valor);
    }
