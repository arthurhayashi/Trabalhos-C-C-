#include <iostream>
#include <stdbool.h>
#include <string>

using namespace std;

int main(){

	bool A , B;
	int X, Y;

	A = true;
	B = true;
	cin >> X; 
	cin >> Y; 

	cout << "I1" << endl;
	if (A){
		cout << "I2" << endl;

			if(B && (X<Y)){
				cout << "I3" << endl;
			}
		
			else{
				cout << "I4" << endl;
			}
	}
		else{
		if(B && (X>Y)){
			cout << "I5" << endl;
		}
		else{
			cout << "I6" << endl;
		}
		cout << "I7" << endl;
		
	return 0;
	}
}
	

