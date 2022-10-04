#include "name.h"
myname::Hello::Hello(int _x){
    x = _x;
}
int myname::Hello::ret(){
    return x;
}
// class myname::Hello{
// public:
//     Hello(int _x):x(_x){}
//     int ret(){
//         return x;
//     }
// private:
//     int x;
// };