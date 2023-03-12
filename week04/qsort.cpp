#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

void print_array(int (&array)[N]){
    for (int i=0; i<N;i++)
        cout<<array[i]<<' ';
}
void qsort(int (&a)[N], int beg, int end) {
    if (beg >= end) {
        return;
    }
    int pivot = a[end];
    int m = beg;
    for (int i = beg; i < end; i++) {
        if (a[i] <= pivot) {
            swap (a[i], a[m]);
            m++;
        }
    }
    swap(a[m], a[end]);
    qsort(a, beg, m-1);
    qsort(a, m+1, end);
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