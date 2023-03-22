#include <iostream>
using namespace std;
int main(){
    double* ptr = nullptr;
    ptr = new double;
    *ptr = 0;
    cout<<ptr<<' '<<*(ptr)<<endl;
    cout<<(ptr-3)<<' '<<*(ptr-3)<<endl;
    cout<<(ptr+5)<<' '<<*(ptr+5)<<endl;
    delete ptr;
    return 0;
}