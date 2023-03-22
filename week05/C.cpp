#include <iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    int i=0;
    while (a!=0){
        int* ar;
        int* arr = new int[i];
        for (int j=0;j<i;++j)
            arr[j]=ar[j];
        arr[i]=a;
        ar = new int[i];
        for (int j=0;j<=i;++j)
            ar[j]=arr[j];
        if (i>0)
            cout<<arr[i-1]-arr[i]<<' ';
        i++;
        cin>>a;
        if (a==0){
            delete [] arr;
            delete [] ar;
        }
    }
    return 0;
}