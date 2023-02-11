#include <iostream>

using namespace std; 

int fibb(int a){
    if ((a==0) or (a==1)){
        return 1;
    }
    else return(fibb(a-1)+fibb(a-2));
}
int main(){
    int a;
    cin>>a;
    cout<<fibb(a)<<endl;
    return 0;

}