#include "temp.h"
#include <iostream>
#include <typeinfo>
using namespace myname;

#define N 128
// typedef myC<typename T>::Tconst TC;

template<typename T>
myC<T>::myC(){
    ptr = new T[N];
}
template<typename T>
myC<T>::~myC(){
    delete [] ptr;
    std::cout << "Delete ptr\n";
}
template<typename T>
// const T *
typename myC<T>::Tconst
myC<T>::consptr(){
    std::cout << "Const ptr\n";
}

int main(){
    myC<int> inst;
    inst.consptr();
    std::cout << typeid(myC<int>::Tconst).name() << std::endl;
}