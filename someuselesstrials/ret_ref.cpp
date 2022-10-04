#include <iostream>
using namespace std;
int x = 10;
int & retref(){
    int &y = x;
    return y;
}

class private_ref{
public:
    private_ref(int _x):x(_x){}
    int judgevalue(){
        return x;
    }
    int &privateref(){
        int &y = x;
        return y;
    }
    int *privaterefp(){
        return &x;
    }
private:
    int x;
};
const int* ref(){

}

int main(){
    private_ref pri(11);
    int & ref_p = pri.privateref();
    ref_p = 123;
    cout << pri.judgevalue() << endl;
    int * p = pri.privaterefp();
    *p = 1234;
    cout << pri.judgevalue() << endl;
    // int &test = retref();
    // test = 1024;
    // cout << "test is " << test << endl;
}
