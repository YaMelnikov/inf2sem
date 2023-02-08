#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int a,b;
    b=1;
    cin>>a;
    if (a>=0){
    for (int i=1;i<(a+1);i++){
        b*=i;
    }
    cout<<b;
    }
}