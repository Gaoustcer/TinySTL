#include <iostream>
using namespace std;
enum TYPE {
    INT,
    DOUBLE,
    FLOAT
};
template<typename T>
struct typetraits{
    TYPE type = T::type;  
};

template<typename double>
struct typetraits{
    type = TYPE::DOUBLE;
};
template<typename int>
struct typetraits{
    type = TYPE::INT;
};
template<typename float>
struct typetraits{
    type = TYPE::FLOAT;
};
int main(){
    return 0;
}
