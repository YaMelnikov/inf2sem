#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int a;
    cin>>a;
    while (a!=1){
        if (a%2==0){
            a/=2;
        }
        else {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if (a==1){
        cout<<"YES"<<endl;
    }
    return 0;
}