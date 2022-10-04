#include <iostream>
using namespace std;
// const int* ptr;
class test{
public:
    int variable = 3;

};
const test * p = new test;

int main(){
    cout << p->variable << endl;
    p->variable = 2;

}