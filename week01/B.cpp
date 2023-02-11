#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a,b,c,d;
    double e,f;
    cin>>a;
    cin>>b;
    cin>>c;
    d=(b*b-4*a*c);
    if (d==0){
    cout<<(-1)*b/(2*a)<<endl;
    }
    else if (d>0){
        e=(-b-sqrt(d))/(2*a);
        f=(-b+sqrt(d))/(2*a);
        cout<<e<<' '<<f<<endl;
    }
    else {
        cout<<'\n';
    }
return(0);
}