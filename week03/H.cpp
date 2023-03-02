#include <iostream>

using namespace std;

#ifndef N
#define N 3
#endif
#ifndef M
#define M 5
#endif
void print_transoposed(int (&array)[N][M]){
    for (int i=0;i<M;++i){
        for (int j=0;j<N;++j){
            cout<<array[j][i]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    int array[N][M]={0};
    for (int i=0;i<N;++i){
        for (int j=0;j<M;++j){
            cin>>array[i][j];
        }
    }
    print_transoposed(array);
}