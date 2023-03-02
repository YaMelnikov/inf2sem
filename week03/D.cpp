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
    for (int i=0;i<N;++i){
        for (int j=0;j<N-1;++j){
            if ((a[j]<0) and (a[j+1]>0))
                swap(a[j],a[j+1]);
        }
    }
    print_array(a);
}