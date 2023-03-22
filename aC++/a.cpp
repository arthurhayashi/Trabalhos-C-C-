#include <iostream>

using namespace std;
 
 int main(){
 	int i,g,j,u;
 	i=0;
 	j=8*8;
 	u=0;
 	g=0;
 	for (i;i<j;i++){
 		g=(u^2);
 		cout << g << endl;
 		cout << "eh o valor de i " << i << endl;
 		 
		u+=g;
	 }
 }
