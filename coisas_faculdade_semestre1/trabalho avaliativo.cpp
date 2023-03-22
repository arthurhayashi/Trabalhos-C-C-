#include<iostream>
#include<stdio.h>

using namespace std;
// código que lê 3 notas de 5 alunos, calcula a média, e retorna dizendo se o aluno foi aprovado ou reprovado.
int main(){
	double n1 = 0, n2 = 0, n3 = 0, media = 0;

	for(int i=0; i < 5; i++){
		printf("Digite 3 notas: ");
		cin >> n1 >> n2 >> n3;

		media = (n1 + n2 + n3) / 3;

		if(media >= 7.0){
			printf("Aluno aprovado com media: %g \n" ,media);
		}else{
			printf("Aluno reprovado com media: %g \n" ,media);
		}
	}
}
