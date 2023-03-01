#include <iostream>

using namespace std;

#ifndef N
#define N 3
#endif

void print_array(int array[N]){
    for (int i=0; i<N;++i){
        cout<<array[i]<<' ';
    }
    cout<<endl;
}

void swap(int& lha,int& rha){
    if (lha!=rha){
    lha-=rha;
    rha+=lha;
    lha=rha-lha;}
}

int main(){
    int a[N]={0};
    for (int i=0;i<N;++i){
        cin>>a[i];
    }
    for (int i=0;i<((N+1)/2);++i){
            swap(a[i],a[N-1-i]);
    }
    print_array(a);
}