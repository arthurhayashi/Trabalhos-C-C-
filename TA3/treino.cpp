#include <iostream>
using namespace std;

int main (){
    int i,s,con,n,b,v;
    cin >> n;

    int a[s];


    for(i = 0; i <= n; i++){
    cin >> a[i];
    }
        for(b=0;b<=n;b++){

        if (a[b]==a[b+1]){
            con++;
        }
        else{
            con=0;
        }

    }

        if(con==2){
        cout <<"yes"<< endl;
        }
        else{
        cout<<"no"<<endl;
        }
}
