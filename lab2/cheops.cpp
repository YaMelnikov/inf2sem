#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

void swap(int& a,int& b){
    if (a!=b){
    a-=b;
    b+=a;
    a=b-a;}
}

void pac(int (&a)[], int n, int h) {
    if (2*n + 1 <= h and a[n] < a[2*n + 1]) {
        swap(a[n], a[2*n + 1]);
    }
    if (2*n + 2 <= h and a[n] < a[2*n + 2]) {
        swap(a[n], a[2*n + 2]);
    }
}

void cheops_sort(int (&a)[N], int n, int size) {
    if (n == 0) {
        return;
    }
    for (int i = n; i >= 0; i--) {
        pac(a, i, n);
    }
    swap(a[0], a[n]);
    cheops_sort(a, n - 1, size);
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
    cheops_sort(a, N - 1, N);
    print_array(a);
}