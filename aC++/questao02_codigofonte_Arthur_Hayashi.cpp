#include <iostream>

using namespace std;

int main (){
	
	int P, S, B, total;
	
	cin >> P >> S >> B ;
	
	switch(P){
		case 1 : total = 180;
		break;
		
		case 2 : total = 230;
		break;
		
		case 3 : total = 250;
		break;
		
		case 4 : total = 350;
		break;
	}
	
	switch(S){
		case 1 : total += 75;
		break;
		
		case 2 : total += 110;
		break;
		
		case 3 : total += 170;
		break;
	
		case 4 : total += 200;
		break;
	}
	
	switch(B){
		case 1 : total += 20;
		break;
		
		case 2 : total += 70;
		break;
		
		case 3 : total += 100;
		break;
		
		case 4 : total += 65;
		break;
	}
	
	cout << total << " kcal" << endl;
	
return 0;	
}
