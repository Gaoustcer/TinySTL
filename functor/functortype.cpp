#include <iostream>
using namespace std;
namespace mystl{
template <typename argtype,typename rettype>
struct u_function{
// public:
    typedef arg argtype;
    typedef ret rettype;
};

template <typename argtype1,typename argtype2,typename rettype>
struct b_function{
// public:
    typedef arg1 argtype1;
    typedef arg2 argtype2;
    typedef ret rettype;
};

template <typename T>
class Bigger:public u_function<T,T>{
public:
    T operator()(T x){
        return x > 0;
    }
};


}
int main(){
    mystl::Bigger<int> b;
    cout << b(-1) << endl;
}