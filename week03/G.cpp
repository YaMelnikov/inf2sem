#include <iostream>

using namespace std;

#ifndef N
#define N 3
#endif

int main(){
    int a[N]={0};
    for (int i=0;i<N;++i){
        cin>>a[i];
    }
    int res=0;
    for (int i=0;i<N;++i){
        res^=a[i];
    }
    cout<<res<<endl;
}