#include "myallocate.h"
#include <climits>
#include <iostream>

using namespace TinySTL;
// typedef TinySTL::myAllocator<T>::pointer pointer;
// template<typename T>
// myAllocator<T>::pointer myAllocator<T>::allocate
template<typename T>
typename TinySTL::myAllocator<T>::pointer
TinySTL::myAllocator<T>::allocate(size_type n,const void*p){
    pointer ptr = new value_type[n];
    if(ptr == NULL){
        return nullptr;
    }
    else{
        return ptr;
    }
}
template<typename T>
typename TinySTL::myAllocator<T>::pointer
TinySTL::myAllocator<T>::allocate(size_type n){
    return allocate(n,nullptr);
}
template <typename T>
void
TinySTL::myAllocator<T>::deallocate(pointer p,size_type n){
    if(p != nullptr && p != NULL){
        delete p;
    }
}
template <typename T>
void
TinySTL::myAllocator<T>::construct(pointer p,const T&value){
    new(p) T(value);
}
template<typename T>
void
TinySTL::myAllocator<T>::destroy(pointer p,size_type n){
    delete(p);
}
template<typename T>
typename TinySTL::myAllocator<T>::size_type
TinySTL::myAllocator<T>::max_size() const{
    return int(UINT_MAX/sizeof(T));
}
template<typename T>
typename TinySTL::myAllocator<T>::pointer
TinySTL::myAllocator<T>:: address(reference x){
    return pointer(&x);
}
template<typename T>
typename TinySTL::myAllocator<T>::const_pointer
TinySTL::myAllocator<T>::const_address(const_reference x){
    return const_pointer(&x);
}
template<typename T>
TinySTL::myAllocator<T>::myAllocator(){

}
// template<typename T>
// TinySTL::myAllocator<T>::myAllocator(myAllocator<T> const x){

// }
int main(){
    TinySTL::myAllocator<int> inst;
    // inst.allocate
    int * ptr = inst.allocate(10);
    for(int i = 0;i<10;i++){
        ptr[i] = 10 - i;
    }   
    for(int i = 1;i < 10;i++){
        std::cout << ptr[i] << std::endl;
    }
}



// template<typename T>
// void myAllocator::deallocate(){
//     return;
// }
// void myAllocator::deallocate(){
// 
// }
