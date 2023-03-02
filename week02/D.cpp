#include <iostream>

using namespace std; 
int recursive_power(int base, int power)
{
    if (power == 0) 
    return 1;
    else 
    return base * recursive_power(base, --power);
}
 
int main(){
    int base,power;
    cin>>base;
    cin>>power;
    cout << recursive_power(base, power) <<endl;
    return 0;
}