#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

using namespace std;

#ifndef N
#define N 1000
#endif

int arr[N];
int counter_of_swaps=0;

void swap(int& lha,int& rha){
    if (lha!=rha){
    lha-=rha;
    rha+=lha;
    lha=rha-lha;}
}

void record_time(long long time, int n){
    ofstream out("time_record.txt", ios::app);
    if (out.is_open()){
        out << n << "\t" << time << endl;
    }
    out.close();
} 

void record_swaps(int n){
        ofstream out("swap_record.txt", ios::app);
    if (out.is_open()){
        out << n << "\t" << counter_of_swaps << endl;
    }
    out.close();
}

void randomize(int arr[], int n){
    unsigned seed = 100;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, n);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = dstr(rng);
    }
} 

void make_step(int arr[], int step, int n){
    for (int i=0;i<n-step;++i)
        if (arr[i]>arr[i+step]){
            swap(arr[i],arr[i+step]);
            counter_of_swaps++;
        }
}

void rascheska(int arr[], int n){
    int step=n/2;
    while (step>0){
        make_step(arr, step, n);
        step/=2;
    }
}

int main(){
    int timer;
    int c=500;
    for(int n=1000;n<100001;n+=1000){
    for(long long int j = 0; j < c; ++j){
        int arr[n];
        timer=0;
        auto begin = std::chrono::steady_clock::now();
        counter_of_swaps=0;
        randomize(arr, n);
        rascheska(arr, n); 
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        timer += time_span.count();
        }
    record_time(timer/c,n);
    record_swaps(n);
    }
}