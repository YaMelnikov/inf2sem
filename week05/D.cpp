#include <iostream>

using namespace std;

void input_array(int* ptr, size_t N);
void reverse(int* ptr, size_t N);
void print(const int* ptr, size_t N);
void swap(int& lha,int& rha){
    if (lha!=rha){
    lha-=rha;
    rha+=lha;
    lha=rha-lha;}
}

void input_array(int* ptr, size_t N){
    for (int i=0;i<N;++i)
        cin>>ptr[i];
}
void reverse(int* ptr, size_t N){
    for (int i=0;i<(N-2)/2;++i)
        swap(ptr[i],ptr[N-1-i]);
}
void print(const int* ptr, int N){
    for (int i=0;i<N;++i){
        cout<<ptr[i]<<' ';
    }
}


int main() {
    int N = 0;
    int* ptr = nullptr;
    cin >> N;
    ptr=new int [N];
    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);
    delete [] ptr;
    return 0;
}