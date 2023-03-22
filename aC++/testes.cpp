#include<iostream>


using namespace std;

int main(){
	int i, T, l, tempo, PA, PB;
	double TA, TB;

	cin >> T;
	for(i=0; i<T;i++){
		tempo=0;
		cin >> PA >> PB >> TA >> TB;
		while(PA <= PB){
			PA+=(PA*((TA)/100));
			PB+=(PB*(TB/100));
			tempo++;
		}
		if(tempo > 100){
			cout << "Mais de 1 seculo" << endl;
		} else {
			cout << tempo << " anos" << endl;
		}
		tempo=0;
		l++;
	}

return 0;
}
