#include <iostream>

using namespace std;

#ifndef N
#define N 3
#endif

int binsearch(int (&array)[N]){
    int l=0;
    int r=N-1;
    while (r-l>1){
        if (array[(r+l)/2]==0)
            l=(r+l)/2;
        else r=(r+l)/2;
    }
    return(l);
}
int main(){
        int a[N]={0};
    for (int i=0;i<N;++i){
        cin>>a[i];
    }
    cout<<binsearch(a)<<endl;
}