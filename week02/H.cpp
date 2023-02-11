#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int a,i,b;
    cin>>a;
    b=0;
    for (i=2;i<a;i++){
        if (a%i==0){
            b=1;
        }
    }
    if ((a==1) or (a==0)){
        cout<<"NO"<<endl;
    }
    else if (b==0){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
    return 0;
}
