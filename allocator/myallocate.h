#include <cstddef>

namespace TinySTL{
    
    template <typename T> struct myAllocator
    {
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef size_t size_type;
        typedef int difference_type;
        
        myAllocator();
        myAllocator(myAllocator<T> const&);
        template<typename U>myAllocator(myAllocator<U> const &);
        pointer allocate(size_type n,const void *p);
        void deallocate(pointer p,size_type n);
        void construct(pointer p,const T&value); // p指向堆空间，在p指向的区域构造1一个T对象，用value的引用拷贝构造之
        void destroy(pointer p,size_type n);// 调用p所指位置的析构函数，对于包含
        size_type max_size() const;// 最多能分配T的个数
        pointer address(reference x);// 返回引用的地址(返回一个指针)
        const_pointer const_address(const_reference x);
        pointer allocate(size_type n);
    };
    template<typename U> struct rebind
    {
        typedef myAllocator<U> other;
        /* data */
    };
    
}