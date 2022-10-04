#include <iostream>
using namespace std;
class Test{
public:
    void change(){
        x++;
    }
    int ret(){
        return x;
    }
    void print(){
        cout << "Hello world\n";
    }
    void print() const{
        cout << x << endl;

    }
private:
    int x = 0;
};
int main(){
    const Test * ptr = new Test();
    Test * p = (Test*)ptr;
    // ptr->change();
    // ptr->print();
    p->change();
    cout << p->ret() << endl;
    // cout << ptr->ret() << endl;
}