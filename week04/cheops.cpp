#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

void cheops_sort(int (&a)[N], int n) {
    if (n==0)
    return;
    else {
        for (int i=n;i>=0;i--){
            if ((2*i+1<=n) and (a[2*i+1]>a[i]))
                swap(a[2*i+1],a[i]);
            if ((2*i+2<=n) and (a[2*i+2]>a[i]))
                swap(a[2*i+2],a[i]);
        }
        swap(a[n],a[0]);
        cheops_sort(a,n-1);
    }
}
void print_array(int (&array)[N]){
    for (int i=0; i<N;i++)
        cout<<array[i]<<' ';
}

int main() {
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cheops_sort(a, N - 1);
    print_array(a);
}