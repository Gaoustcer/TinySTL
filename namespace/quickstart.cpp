#include <iostream>
using namespace std;
namespace space1{
    void func(){
        cout << "This is namespace1\n";
    }
}
namespace space2{
    void func(){
        cout << "This is namespace2\n";
    }
    namespace sp{
        void func(){
            cout << "This is namespace space2 sp\n";
        }
    }
}

int main(){
    space1::func();
    space2::func();
    space2::sp::func();
}