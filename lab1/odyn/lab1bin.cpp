#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

using namespace std;

void record(double time, unsigned n){
    ofstream out("binmax.txt", ios::app);
    if (out.is_open()){
        out << n << "\t" << time << endl;
    }
    out.close();
} 

void bin_search(int* a, int size, double elem){
    int l = 0;
    int r = size - 1;
    int m = 0;
    while (l < r){
        m = (l + r)/2;
        if (elem == a[m]){
            return;
        }
        if (elem < a[m]){
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
} 

int main(){
    long long time1 = 0;
    unsigned seed = 1001;
    int c = 500;
    for (int i = 1000; i<1010000; i += 1000){
        time1 = 0;
        int* arr = new int[i];
        for (int j = 0; j < i; ++j){
            arr[j] = j;
        } 
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, i);

        for(int j = 0; j < c; ++j){
            auto begin = std::chrono::steady_clock::now();
            bin_search(arr, i, (dstr(rng)+0.5)); 
            auto end = std::chrono::steady_clock::now();
  
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            time1 += time_span.count();
            }

        record(time1/c, i);
        delete [] arr;
    }

    return 0;
}