#include <iostream>

using namespace std;

void swap(int& lha,int& rha){
    if (lha!=rha){
    lha-=rha;
    rha+=lha;
    lha=rha-lha;}
}

int main(){
    int n;
    int a=-1000000,b=1000000;
    int beg,end;
    cin>>n;
    for (int i=0; i<n;i++){
        cin>>beg>>end;
        if (beg>end)
            swap(beg,end);
        if (a<beg)
            swap(a,beg);
        if (b>end)
            swap(b,end);
    }
    if (a<=b)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}