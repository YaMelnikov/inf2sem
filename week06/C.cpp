#include <iostream>

using namespace std;

struct Time{
    int hours;
    int mins;
    int secs;
};
int main(){
    Time begin;
    Time tte;
    Time end;
    cin>>begin.hours>>begin.mins>>begin.secs;
    cin>>tte.hours>>tte.mins>>tte.secs;
    end.secs=(begin.secs+tte.secs);
    end.mins=(begin.mins+tte.mins+end.secs/60);
    end.secs%=60;
    end.hours=(begin.hours+tte.hours+end.mins/60)%24;
    end.mins%=60;
    cout<<end.hours<<":"<<end.mins<<":"<<end.secs<<endl;
    return 0;
}