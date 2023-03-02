#include <iostream>

using namespace std;

#ifndef N
#define N 1
#endif
#ifndef M
#define M 3
#endif

void sort2d(int (&array)[N][M]){
    for (int i=0;i<N*M+1;++i){
        for (int j=i;j<N*M;++j){
            if (array[i/M][(i%M)]>array[j/M][(j%M)]){
                int a=array[i/M][(i%M)];
                array[i/M][(i%M)]=array[j/M][(j%M)];
                array[j/M][(j%M)]=a;
            }
        }
    }
    for (int i=0;i<N;++i){
        for (int j=0;j<M;++j){
            cout<<array[i][j]<<' ';
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
    sort2d(array);
}