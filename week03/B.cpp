#include <iostream>

using namespace std;

#ifndef N
#define N 5
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
    for (int i=1;i<N;++i){
            swap(a[N-i],a[N-i-1]);
    }
    print_array(a);
}