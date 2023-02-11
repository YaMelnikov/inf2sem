#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int count,i;
    cin>>i;
    count=0;
    while (i!=0){
        if (i%2==0){
            count++;
        }
        cin>>i;
    }
    cout<<count<<endl;
    return 0;
}