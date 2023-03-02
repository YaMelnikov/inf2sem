#include <iostream>

using namespace std;

#ifndef N
#define N 2
#endif

int trace(int (&array)[N*N]){
    int sum;
    for (int i=0;i<N*N;i+=(N+1)){
        sum+=array[i];
    }
    return sum;
}
int main(){
    int a[N*N]={0};
    for (int i=0;i<(N*N);++i){
        cin>>a[i];
    }
    cout<<trace(a)<<endl;
}