#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

using namespace std;

void record(long long time, unsigned n){
    ofstream out("strat_b_avg.txt", ios::app);
    if (out.is_open()){
        out << n << "\t" << time << endl;
    }
    out.close();
} 
void swap(long long a, long long b){
    if (a!=b){
        int t=a;
        a=b;
        b=t;
    }
}

void search(int* array, int size, int elem){
    for (int i = 0; i < size; i++){
        if (elem == array[i]){
            if (i!=0)
                swap(array[i-1],array[i]);
            return;
        }
    }
}

int main(){
    long long time1 = 0;
    unsigned seed = 1001;
    int c = 500;
    for (int i = 1000; i<1010000; i += 10000){
        time1 = 0;
        int* a = new int[i];
        for (int j = 0; j < i; ++j){
            a[j] = j;
        } 
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, i);

        for(int j = 0; j < c; ++j){
            auto begin = std::chrono::steady_clock::now();
            search(a, i, dstr(rng)); 
            auto end = std::chrono::steady_clock::now();
  
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            time1 += time_span.count();
            }

        record(time1/c, i);
        delete [] a;
    }

    return 0;
}
