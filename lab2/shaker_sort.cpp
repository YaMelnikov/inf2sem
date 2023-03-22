#include <iostream>
using namespace std;

#ifndef N
#define N 5
#endif

void forward_step(unsigned arr[], unsigned const begin_idx,unsigned const end_idx){
    if (begin_idx<end_idx){
        for (unsigned i=begin_idx;i<(end_idx);++i){
            if (arr[i]>arr[i+1])
                swap(arr[i+1],arr[i]);
        }
    }
}
void backward_step(unsigned arr[], unsigned const begin_idx,unsigned const end_idx){
    if (begin_idx<end_idx){
    for (unsigned i=end_idx;i>begin_idx;--i){
        if (arr[i]<arr[i-1])
            swap(arr[i-1],arr[i]);
    }
}
}
void shaker_sort(unsigned arr[], unsigned const begin_idx,unsigned const end_idx){
    if (begin_idx<end_idx){
        backward_step(arr,begin_idx,end_idx);
        for (int i=0;i<(end_idx-begin_idx-1);++i)
            forward_step(arr,1,end_idx-i);
    }
}
void print_array(unsigned array[N]){
    for (int i=0; i<N;++i){
        cout<<array[i]<<' ';
    }
    cout<<endl;
}
int main(){
    unsigned a[N]={0};
    for (int i=0;i<N;++i){
        cin>>a[i];
    }
    shaker_sort(a,0,N-1);
    print_array(a);
    return 0;
}