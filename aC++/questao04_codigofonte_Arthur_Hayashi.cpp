#include <iostream>
#include <stdbool.h>

using namespace std;

int main(){
	
	bool A, B, C;
	int X, Y;
	 
	A = true;
	B = true;
	C = true;
	cin >> X;
	cin >> Y;
	
	cout << "I1" << endl;
	if (!A){
		cout << "I2" << endl;
	}
	else{
		cout << "I3" << endl;
		if(B){
			cout << "I4" << endl;
		}
		cout << "I5" << endl;
		if (C || (X > Y)){
			cout << "I6" << endl;
			cout << "I7" << endl;
		}
		else{
			cout << "I8" << endl;
		}
	}
	
	return 0; 
}
