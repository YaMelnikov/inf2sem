#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int a,b;
    double c;
    cin>>a>>b;
    if ((a>0) & (b>0)){
    c=sqrt(a*a+b*b);
    }
    cout<<floor(c)<<endl;
    return 0;
}
