#include <iostream>


using namespace std;

int main(){
	
	int M, D, C, U;
	
	cin >> M >> D >> C >> U;
	
	if ((M == U) && (D == C)){
		cout << "Capicua" << endl;
	}
	else {
		cout << "Nao eh uma capicua" << endl;
	}
	
	return 0;
}
