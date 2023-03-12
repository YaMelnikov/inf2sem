#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

void gnome_sort(int (&a)[N]){
    for (int i=0;i<N;i++)
        for (int j=0;j<N-1;j++)
            if (a[j]>a[j+1])
                swap(a[j],a[j+1]);
}
void print_array(int (&array)[N]){
    for (int i=0; i<N;i++)
        cout<<array[i]<<' ';
}
int main(){
    int a[N]={0};
    for (int i=0;i<N;i++)
        cin>>a[i];
        gnome_sort(a);
    print_array(a);
}