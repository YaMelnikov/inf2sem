#include <iostream>

using namespace std; 

long long fact(int a){
    if (a==0){
        return 1;
    }
    else return(a*fact(--a));
}
int main(){
    int a;
    cin>>a;
    cout<<fact(a)<<endl;
    return 0;
}