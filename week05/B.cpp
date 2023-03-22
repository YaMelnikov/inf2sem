#include <iostream>
using namespace std;
int main(){
    short int* ptr = nullptr;
    ptr = new short int [10];
    for (short int i=0;i<10;++i)
        ptr[i]=i;
    for (short int i=0;i<10;++i)
        cout<<&ptr[i]<<' ';
    cout<<endl;
    for (short int i=0;i<10;++i)
        cout<<ptr[i]<<' ';
    cout<<endl;
    for (short int i=0;i<10;++i){
        ptr[i]*=ptr[i];
        cout<<ptr[i]<<' ';
    }
    cout<<endl;
    delete [] ptr;
    
}