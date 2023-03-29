#include <iostream>

using namespace std;

enum Status
{   Continue=100,
    OK=200,
    Created=201,
    Accepted=202,
    Bad_Request=400,
    Unauthorized=401,
    Not_Found=404,
    Method_Not_Allowed=405,
    Internal_Server_Error=500,
    Not_Implemented=501,
    Bad_Gateway=502
};
void ans(int num) {
    if (num == Status::Continue) {
        cout << "Continue" << endl;
    } else if (num == Status::OK) {
        cout << "OK" << endl;
    } else if (num == Status::Created) {
        cout << "Created" << endl;
    } else if (num == Status::Accepted) {
        cout << "Accepted" << endl;
    } else if (num == Status::Bad_Request) {
        cout << "Bad Request" << endl;
    } else if (num == Status::Unauthorized) {
        cout << "Unauthorized" << endl;
    } else if (num == Status::Not_Found) {
        cout << "Not Found" << endl;
    } else if (num == Status::Method_Not_Allowed) {
        cout << "Method Not Allowed" << endl;
    } else if (num == Status::Internal_Server_Error) {
        cout << "Internal Server Error" << endl;
    } else if (num == Status::Not_Implemented) {
        cout << "Not Implemented" << endl;
    } else if (num == Status::Bad_Gateway) {
        cout << "Bad Gateway" << endl;
    }
    return;
}

int main(){
    int a;
    cin>>a;
    while (a!=0){
        ans(a);
        cin>>a;
    }
}