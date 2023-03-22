#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a, b, c, v_aux; //declarando variáveis
	
	cin >> a >> b >> c; //requesitando valores
	
	if ((a == b)&&(b == c)){ //a,b,c
		cout << a <<","<< b <<","<< c << endl;
		return 0;
	}
	
	if ((a == b)&&(c > b)){
		cout << a <<","<< b <<","<< c << endl;
		return 0;
	}
	
	if ((a == b)&&(b > c)){
		v_aux=c;
		c=b;
		b=a;
		a=v_aux;
		cout << a <<","<< b <<","<< c << endl;
		return 0;
	}
	
	if ((a > b)&&(b == c)){
		v_aux=a;
		a=b;
		b=c;
		c=v_aux;
		cout << a <<","<< b <<","<< c << endl;
		return 0;
	}
	
	if ((b > a)&&(b == c)){
		cout << a <<","<< b <<","<< c << endl;
		return 0;
	}
	
	if ((a==c)&&(c>b)){
		v_aux=a;
		a=b;
		b=v_aux;
		cout << a <<","<< b <<","<< c << endl;
		return 0;
	}
	
	if ((a==c)&&(b>c)){
		v_aux=b;
		b=c;
		c=v_aux;
		cout << a <<","<< b <<","<< c << endl;
		return 0;
	}
	
	if ((a > b)&&(b > c)){ //c,b,a
		v_aux=a;
		a=c;
		c=v_aux;
		cout << a <<","<< b <<","<< c << endl;
		return 0;
	}
	
	if ((b > a) && (b < c)){ //a,b,c
		cout << a <<","<< b <<","<< c << endl;
		return 0;
	}
	
	if ((b > a) &&(a > c)){ //c,a,b
		v_aux=a;
		a=c;
		c=b;
		b=v_aux;
		cout << a <<","<< b <<","<< c << endl;
		return 0;
	}
	
	
	if ((c > a) && (b > c)){ //a,c,b
		v_aux=b;
		b=c;
		c=v_aux;
		cout << a <<","<< b <<","<< c << endl;
		return 0;
	}
	
	if ((c > b) && (a > c)){ //b,c,a
		v_aux=a;
		a=b;
		b=c;
		c=v_aux;
		cout << a <<","<< b <<","<< c <<endl;
		return 0;
	}


 } 
