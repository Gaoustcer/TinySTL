#include <iostream>
#include <stdlib.h>
#include <vector>
#include "TinySTL.h"
using namespace std;
// using namespace TinySTL;
int main(){
    cout << TinySTL::equal_to<int>()(1,2);
}