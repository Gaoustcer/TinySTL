#include <iostream>

namespace TinySTL{
template<typename T> class plus{
public:
    T operator()(T a,T b){
        return a + b;
    }
};
template<typename T> class minus{
public:
    T operator()(T a,T b) {
        return a - b;
    }
};
template<typename T> class multipliers{
public:
    T operator()(T a,T b){
        return a * b;
    }
};
template<typename T> class dividess{
public:
    T operator()(T a,T b){
        try {
            return a/b;
        }catch(const char * e){
            std::cerr << e << std::endl;
        }
    }
};
template<typename T> class modulus{
public:
    T operator()(T a,T b){
        try {
            return a%b;
        }catch(const char * e){
            std::cerr << e << std::endl;
        }
    }
};
template<typename T> class negate{
public:
    T operator()(T x){
        return -x;
    }
};
template<typename T> class equal_to{
public:
    bool operator()(T a,T b){
        return a == b;
    }
};
template<typename T> class not_equal_to{
public:
    bool operator()(T a,T b){
        return a != b;
    }
};
template<typename T> class greater{
public:
    bool operator()(T a,T b){
        return a > b;
    }
};
template<typename T> class greater_equal{
public:
    bool operator()(T a,T b){
        return a >= b;
    }
};
template<typename T> class less{
public:
    bool operator()(T a,T b){
        return a < b;
    }
};
template<typename T> class less_equal{
public:
    bool operator()(T a,T b){
        return a <= b;
    }
};
template<typename T> class logical_and{
public:
    bool operator()(T a,T b){
        return a & b;
    }
};
template<typename T> class logical_or{
public:
    bool operator()(T a,T b){
        return a | b;
    }
};
template<typename T> class logical_not{
public:
    bool operator()(T x){
        return !x;
    }
};

}