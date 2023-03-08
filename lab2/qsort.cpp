#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

int step(int (&a)[N], int l, int r) {
    int pivot = a[r];
    int m = l;
    for (int i = l; i < r; i++) {
        if (a[i] <= pivot) {
            swap (a[i], a[m]);
            m++;
        }
    }
    swap(a[m], a[r]);
    return m;
}
void print_array(int (&array)[N]){
    for (int i=0; i<N;i++)
        cout<<array[i]<<' ';
}
void qsort(int (&a)[N], int beg, int end) {
    if (beg >= end) {
        return;
    }
    int pivot = step(a, beg, end);
    qsort(a, beg, pivot - 1);
    qsort(a, pivot  + 1, end);
}
int main() {
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    qsort(a, 0, N-1);
    print_array(a);
    return 0;
}