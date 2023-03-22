#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){

	int ki, l , i;
	cin >> l ;
	
	for(i=1; i<=l; i++){
		
		cin >> ki;
		if (ki <= 8000){
			cout << "Inseto!" << endl;
		}
		else {
			cout << "Mais de 8000!" << endl;
		}
	}

	return 0;

}

