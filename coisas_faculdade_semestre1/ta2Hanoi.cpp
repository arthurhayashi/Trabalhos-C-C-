#include <iostream>
#include <windows.h>
#include <stack>

using namespace std;

// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i); (essa função é para trocar de cor (i é um valor entre 0-15 para mudar o texto))

void printTorre(int n, stack<int> pilhaA, stack<int> pilhaB, stack<int> pilhaC){

   int i, j;
   int num[3];
   int vet[n][3] = {0};  // matriz que armazana valores das pilhas (0 para A, 1 para B e 2 para C)
                        // foram usados '0' para representar os valores vazios nas pilhas

   for(i = 0; i < 3; i++){  //remove os valores das pilhas enquando armazena em vet[n][3]
      for(j = 0; j < n; j++){
         if(i == 0){  // pega valores da pilha A  para a coluna 0
            num[i] = n - pilhaA.size();  // pula as linhas da matriz para ficar na formatação correta (repete em nas linhas 30 e 41)
            if(j == 0){
               j += num[i];
            }
            if(pilhaA.empty()){
               continue;
            }
            vet[j][i] = pilhaA.top();
            pilhaA.pop();
         }
         if(i == 1){  // pega valores da pilha B para a coluna 1
            num[i] = n - pilhaB.size();
            if(j == 0){
               j += num[i];
            }
            if(pilhaB.empty()){
               continue;
            }
            vet[j][i] = pilhaB.top();
            pilhaB.pop();
         }
         if(i == 2){  // pega valores da pilha C para a coluna 2
            num[i] = n - pilhaC.size();
            if(j == 0){
               j += num[i];
            }
            if(pilhaC.empty()){
               continue;
            }

            vet[j][i] = pilhaC.top();
            pilhaC.pop();
         }
      }
   }

   for(i = 0; i < n; i++){  // imprime a matriz[n][3]
      for(j = 0; j < 3; j++){
         if(vet[i][j] != 0){
            if(vet[i][j] >= 15){
               if(vet[i][j] % 15 == 0){  // remove a cor preto (0) para ver melhor no console)
                  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), vet[i][j] % 15 + 1);
               }else{
                  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), vet[i][j] % 15);
               }
            }else{  // colore os números com os códigos de 1-14
                  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), vet[i][j]);
            }
         }else{  // colore os números para branco se os valores forem igual a '0'
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
         }
         if(j == 2){
            cout << vet[i][j];
         }else{
            cout << vet[i][j] << "   ";
         }
      }
      cout << endl;
   }

   // volta o texto para a cor branca
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

   cout << "\nA   B   C" << endl;

   for(i = 0; i < 3; i++){  // inserindo os valores da matriz vet[n][3] novamente nas pilhas
      for(j = 0; j < n; j++){
         if(i == 0){                    // pega valores da coluna 0 para pilha A
            pilhaA.push(vet[j][i]);
         }
         if(i == 1){                    // pega valores da coluna 1 para pilha B
            pilhaB.push(vet[j][i]);
         }
         if(i == 2){                    // pega valores da coluna 2 para pilha C
            pilhaC.push(vet[j][i]);
         }
      }
   }
}

char verifPilhaE(int n, stack<int> pilhaA, stack<int> pilhaB, stack<int> pilhaC){
   char op1;  // primeira pilha
   bool acesso = false; // condição do while

   while(!acesso){
      cout << "Digite uma pilha para remover uma unidade\n>>";
      cin >> op1;

      if(op1 == 'a' || op1 == 'b' || op1 == 'c'){  // converte as letras minúsculas para maiúsculas
         op1 -= (char)32;
      }

      // Verifica se a pilha de op1 se é válida

      if(op1 == 'A'){ 
         if(!pilhaA.empty()){
            if(pilhaB.empty() || pilhaC.empty()){
               acesso = true;
            }else{
               if(pilhaA.top() < pilhaB.top() || pilhaA.top() < pilhaC.top()){
                  acesso = true;
               }
            }
         }
      }else if(op1 == 'B'){
         if(!pilhaB.empty()){
            if(pilhaA.empty() || pilhaC.empty()){
               acesso = true;
            }else{
               if(pilhaB.top() < pilhaA.top() || pilhaB.top() < pilhaC.top()){
                  acesso = true;
               }
            }
         }
      }else if(op1 == 'C'){
         if(!pilhaC.empty()){
            if(pilhaA.empty() || pilhaB.empty()){
               acesso = true;
            }else{
               if(pilhaC.top() < pilhaA.top() || pilhaC.top() < pilhaB.top()){
                  acesso = true;
               }
            }
         }
      }

      if(!acesso){
         cout << "Pilha invalida. Escolha outra\n";
      }
   }

   return op1;
}

char verifPilhaS(int n, char op1, stack<int> pilhaA, stack<int> pilhaB, stack<int> pilhaC){
   char op2;  // segunda pilha
   bool acesso = false;

   while(!acesso){
      cout << "Digite uma pilha para adicionar uma unidade\n>>";
      cin >> op2;

      if(op2 == 'a' || op2 == 'b' || op2 == 'c'){
         op2 -= (char)32;
      }

      if(op2 == op1){
         cout << "Pilha invalida. Escolha outra\n";
         continue;
      }

      // Verifica se a pilha de op2 é válida e pode receber mais valores

      if(op2 == 'A'){
         if(pilhaA.size() < n){
            acesso = true;
         }
      }else if(op2 == 'B'){
         if(pilhaB.size() < n){
            acesso = true;
         }
      }else if(op2 == 'C'){
         if(pilhaC.size() < n){
            acesso = true;
         }
      }

      if(!acesso){
         cout << "Pilha invalida. Escolha outra\n";
         continue;
      }

      if(op1 == 'A'){  // verifica se a pilha op2 pode receber os valores da pilha op1
         if(op2 == 'B'){
            if(pilhaB.empty()){
               acesso = true;
            }else{
               if(pilhaA.top() > pilhaB.top()){
                  acesso = false;
               }
            }
         }else{
            if(pilhaC.empty()){
               acesso = true;
            }else{
               if(pilhaA.top() > pilhaC.top()){
                  acesso = false;
               }
            }
         }
      }else if(op1 == 'B'){
         if(op2 == 'A'){
            if(pilhaA.empty()){
               acesso = true;
            }else{
               if(pilhaB.top() > pilhaA.top()){
                  acesso = false;
               }
            }
         }else{
            if(pilhaC.empty()){
               acesso = true;
            }else{
               if(pilhaB.top() > pilhaC.top()){
                  acesso = false;
               }
            }
         }
      }else{
         if(op2 == 'A'){
            if(pilhaA.empty()){
               acesso = true;
            }else{
               if(pilhaC.top() > pilhaA.top()){
                  acesso = false;
               }
            }
         }else{
            if(pilhaB.empty()){
               acesso = true;
            }else{
               if(pilhaC.top() > pilhaB.top()){
                  acesso = false;
               }
            }
         }
      }

      if(!acesso){
         cout << "Pilha invalida. Escolha outra\n";
      }
   }

   return op2;
}

void printTela(){

   cout << "---------------------------------------------------------\n\n";

   cout << "                     Torre de Hanoi\n\n";

   cout << "---------------------------------------------------------\n\n";

   system("pause");  // espera uma tecla no console
   Sleep(1000);  // espera 1 segundo para continuar
   system("cls");
}

int main(){

   int i, n = 1;
   char v1, v2;

   system("cls"); // limpa a tela
   printTela();
   
   while(n <= 1) {
      cout << "Digite o tamanho da torre (maior que 1)" << "\n>>";
      cin >> n;
      system("cls");
   }

   stack<int> pilhaA, pilhaB, pilhaC; // usando a biblioteca <stack> para criar pilhas

   for(i = 0; i < n; i++){
      pilhaA.push(n - i);  // função push da biblioteca <stack>
   }

   while(1){
      printTorre(n, pilhaA, pilhaB, pilhaC);  // imprime a torre inteira (cada processo comentado na função acima)

      v1 = verifPilhaE(n, pilhaA, pilhaB, pilhaC);  // seleciona e verifica o valor para a primeira pilha e armazena em v1
      v2 = verifPilhaS(n, v1, pilhaA, pilhaB, pilhaC);  // seleciona e verifica o valor para a segunda pilha e armazena em v2

      if(v1 == 'A'){  // nós pegamos v1 e v2 e trocamos os valores das pilhas no main() porque não conseguimos representar em uma função
         if(v2 == 'B'){
            pilhaB.push(pilhaA.top());  // função top() puxa o valor do topo da pilha
            pilhaA.pop();  // função pop() retira o valor do topo da pilha
         }else{
            pilhaC.push(pilhaA.top());
            pilhaA.pop();
         }
      }else if(v1 == 'B'){
         if(v2 == 'A'){
            pilhaA.push(pilhaB.top());
            pilhaB.pop();
         }else{
            pilhaC.push(pilhaB.top());
            pilhaB.pop();
         }
      }else if (v1 == 'C'){
         if(v2 == 'A'){
            pilhaA.push(pilhaC.top());
            pilhaC.pop();
         }else{
            pilhaB.push(pilhaC.top());
            pilhaC.pop();
         }
      }

      system("cls");

      if(pilhaB.size() == n || pilhaC.size() == n){  // usando função size(), que verifica o tamanho da pilha, para verificar a vitória
         cout << "Parabens, voce conseguiu!!!" << endl;
         break;
      }
   }

   return 0;
}
