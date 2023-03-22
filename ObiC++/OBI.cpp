#include <iostream>

using namespace std;

int main(){

int N, c;
int t[100];
cin >> N;
while(N != 0){
c = 10;
for (int i = 0; i < N; i++){
cin >> t[i];
}
for (int i = 1; i < N; i++){
if(t[i] - t[i - 1] > 10){
c += 10;
}else{
c += t[i] - t[i - 1];
}
}
cout << c << endl;
cin >> N;
}
return 0;
}
