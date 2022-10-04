#include "name.h"
#include <iostream>

int main(){
    myname::func();
    myname::Hello inst(10);
    // inst.
    std::cout << inst.ret();
}