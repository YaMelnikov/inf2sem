#include <iostream>

using namespace std;

struct Students{
    string Name;
    int avgpt;
};

int main(){
    int M;
    int c=0;
    Students data[10];
    for (int i=0;i<10;i++)
        cin>>data[i].Name>>data[i].avgpt;
    cin>>M;
    for (int i=0;i<10;i++)
        if (data[i].avgpt>=M)
            if (c==0){
                c++;
                cout<<data[i].Name;
            }
            else cout<<' '<<data[i].Name;
    cout<<endl;
    return 0;
}