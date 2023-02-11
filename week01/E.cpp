#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b;
    d=a*b;
    if (a>b){
        c=a;
        a=b;
        b=c;
    }
    while (b!=0){
        a=a%b;
        c=a;
        a=b;
        b=c;
    }
    cout<<d/a<<endl;
    return(0);
}
