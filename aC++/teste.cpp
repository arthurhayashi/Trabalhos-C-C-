#include <iostream>
#include <math.h>

using namespace std;

int main(){

	int c;
	cin >> c;

	switch(c){
		case 1: cout << "Alimento nao-perecivel" << endl;
		break;
		
		case 2 : cout << "Alimento perecivel" << endl;
		break;
		
		case 3: cout << "Alimento perecivel" << endl;
		break;
		
		case 4: cout << "Alimento perecivel" << endl;
		break;
		
		case 5: cout << "Vestuario" << endl;
		break;
		
		case 6: cout << "Vestuario" << endl;
		break;
		
		case 7: cout << "Higiene pessoal" << endl;
		break;
		
		case 8: cout << "Limpeza e utensilios domesticos" << endl;
		break;
		
		case 9: cout << "Limpeza e utensilios domesticos" << endl;
		break;
		
		case 10: cout << "Limpeza e utensilios domesticos" << endl;
		break;
		
		case 11: cout << "Limpeza e utensilios domesticos" << endl;
		break;
		
		case 12: cout << "Limpeza e utensilios domesticos" << endl;
		break;
		
		case 13: cout << "Limpeza e utensilios domesticos" << endl;
		break;
		
		case 14: cout << "Limpeza e utensilios domesticos" << endl;
		break;
		
		case 15: cout << "Limpeza e utensilios domesticos" << endl;
		break;
		
		default : cout << "Invalido" << endl;
	}
	
return 0;
}
#include <iostream>
#include <math.h>

using namespace std;

int main(){

int a, b, r;
char op [2];

cin >> op;

	if ((op[0] == '+')||(op[0] == '-')||(op[0] == '*')||(op[0] == '/')){
	
	cin >> a >> b;
	
		if (op[0] == '+') {
			r = a + b;
		}
			else if(op[0] == '-'){
				r = a - b;
			}
			
				else if (op[0] == '*'){
					r = a * b;
				}
					else if (op[0] == '/'){
						r = a / b;
					}
						
		cout << a << op << b << " = " << r << endl;
	
	}
	else{
	cin >> a;
		if(op[0] == 's' && op[1] == 'q' && op[2] == 'r'){
			r = pow(a, 0.5);
		}
			else if (op[0] == '^' && op[1] == '3'){
					r = pow(a, 3);
			}
				else if (op[0] == '^' && op[1] == '2'){
					r = pow(a, 2);
				}
				
	cout << a << op << " = " << r << endl;
	}	
	
return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main (){
	
	string a , b , vencedor;
	
	cin >> a >> b;
	
	if (b == "papel"){
		if ( a == "pedra"){
			vencedor = b;
		}
		else if(a == "tesoura"){
			vencedor = a;
		}
		else{
			vencedor = "empate";
		}
	}
	else if(b == "tesoura"){
		
			if(a == "pedra"){
				vencedor = a;
			}
			else if(a == "papel"){
				vencedor = b ;
			}
				else{
					vencedor = "empate";
				}
		}
		else if (a == "pedra"){
			vencedor = "empate";
				}
			else if (a == "papel"){
				vencedor = a;
				}
				else{
					vencedor = b;
				}
				
	
	cout << vencedor << endl;
	
	return 0;
}
