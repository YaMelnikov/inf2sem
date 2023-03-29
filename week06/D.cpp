#include <iostream>

using namespace std;

struct Line{
    float begx;
    float begy;
    float endx;
   float endy;
}street1, street2;

float row(float x1,float y1,float x2,float y2,float x3,float y3){
    return ((x3-x1)/(x2-x1)-(y3-y1)/(y2-y1));
}

bool between(float x1,float x2,float x3){
    return(((x1<=x3) and (x1>=x2)) or ((x1>=x3) and (x1<=x2)));
}

bool fast_check(float x1,float y1,float x2,float y2,float x3,float y3, float x4, float y4){
    if ((x1<x3) and (x1<x4) and (x2<x3) and (x2<x4))
    return true;
    if ((x1>x3) and (x1>x4) and (x2>x3) and (x2>x4))
    return true;
    if ((y1<y3) and (y1<y4) and (y2<y3) and (y2<y4))
    return true;
    if ((y1>y3) and (y1>y4) and (y2>y3) and (y2>y4))
    return true;
    return false;
}
bool cross(float x1,float y1,float x2,float y2,float x3,float y3, float x4, float y4){
    if (x1==x2)
        return((x3-x1)*(x4-x1)<0);
    if (y1==y2)
        return((y3-y1)*(y4-y1)<0);
    if (x3==x4)
        return((x2-x3)*(x1-x3)<0);
    if (y3==y4)
        return((y1-y3)*(y2-y3)<0);
    if (((row(x1,y1,x2,y2,x3,y3)==0) and (between(x1,x2,x3))) or ((row(x1,y1,x2,y2,x4,y4)==0) and (between(x1,x2,x4)))
    or ((row(x3,y3,x4,y4,x1,y1)==0) and (between(x3,x4,x1))) or ((row(x3,y3,x4,y4,x2,y2)==0) and (between(x3,x4,x2))))
    return true;
    if (row(x1,y1,x2,y2,x3,y3)==0 or row(x1,y1,x2,y2,x4,y4)==0 or row(x3,y3,x4,y4,x1,y1)==0 or row(x3,y3,x4,y4,x2,y2)==0)
    return false;
    return(((x3-x1)/(x2-x1)-(y3-y1)/(y2-y1))*((x4-x1)/(x2-x1)-(y4-y1)/(y2-y1))<0);
}
int main(){
    cin>>street1.begx>>street1.begy>>street1.endx>>street1.endy;
    cin>>street2.begx>>street2.begy>>street2.endx>>street2.endy;
    if (fast_check(street1.begx,street1.begy,street1.endx,street1.endy,street2.begx,street2.begy,street2.endx,street2.endy))
    cout<<"YES"<<endl;
    else if (cross(street1.begx,street1.begy,street1.endx,street1.endy,street2.begx,street2.begy,street2.endx,street2.endy) 
    or cross(street1.begx,street1.begy,street2.begx,street2.begy,street1.endx,street1.endy,street2.endx,street2.endy)
    or cross(street2.begx,street2.begy,street1.endx,street1.endy,street1.begx,street1.begy,street2.endx,street2.endy))
    cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}   