#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

using namespace std;

void record(long long time, unsigned n){
    ofstream out("debmax.txt", ios::app);
    if (out.is_open()){
        out << n << "\t" << time << endl;
    }
    out.close();
} 

void sum_search(int* a, int size, double sum){
    for (int i=0;i<size;++i)
        for(int j=i;j<size;++j){
            if (a[i]+a[j]==sum)
            return;
        }
} 

int main(){
    long long int time1 = 0;
    unsigned seed = 1001;
    int c = 500;
    for (long long int i = 1000; i<100000; i += 5000){
        time1 = 0;
         int* arr = new int[i];
        for (long long int j = 0; j < i; ++j){
            arr[j] = j;
        } 
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(1, 2*i);

        for(long long int j = 0; j < c; ++j){
            auto begin = std::chrono::steady_clock::now();
            sum_search(arr, i, (dstr(rng)+0.5)); 
            auto end = std::chrono::steady_clock::now();
  
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            time1 += time_span.count();
            }

        record(time1/c, i);
        delete [] arr;
    }

    return 0;
}