#include <iostream>

using namespace std;

#ifndef N
#define N 3
#endif

void print_array(int array[2*N]){
    for (int i=0; i<2*N;++i){
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
    int a[N+1]={0};
    int b[N+1]={0};
    int c[2*N]={0};
    for (int i=0;i<N;++i){
        cin>>a[i];
    }
    for (int i=0;i<N;++i){
        cin>>b[i];
    }
    a[N]=1000000;
    b[N]=1000000;
    int i=0;
    int j=0;
    while (i+j<2*N){
        if (a[i]>b[j]){
            c[i+j]=b[j];
            j++;
        }
        else {
            c[i+j]=a[i];
            i++;
        }
    }
    print_array(c);
}