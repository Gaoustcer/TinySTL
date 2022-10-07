# 空间配置器
## 简介
容器(数据结构调用)，完成内存配置与释放，对象构造和析构。数据结构内存实例化一个`allocator`。常用数据结构实体化不仅需要提供类型名作为实例化参数，还需要提供allocator

## trait技术
现在有若干数据结构`int,double,myclass`，希望用统一的参数接口`encoder()`处理它们
### 方法1：函数重载
```cpp
encoder(int x);
encoder(double x);
encoder(myclass x);
```
希望将若干类型打包到一起，通过单一接口处理
### 方法二：模板函数+内部字段
定义一个模板函数，同时在所有类中增加一个public属性Type，类型是一个枚举变量
> int等自带类型无法添加字段

### 方法三：trait模板类
同样为类增加TYPE字段，对于内置数据类型，定义模板类的特化生成独有的type_traits，这样只需要在`encoder`模板函数内部针对传入的类型T实例化`type_traits`对象判断其类型参数即可
> 感觉没什么用，通过函数特化或者typeid可以有效解决

## allocator标准接口
### type_traits成员
```cpp
allocator::value_type
allocator::pointer
allocator::const_pointer
allocator::reference
allocator::const_reference
allocator::size_type
allocator::difference
```
### 构造函数-拷贝构造函数和析构函数
```cpp
allocator::allocator() // 默认构造函数
allocator::allocator(const allocator&) // 拷贝构造函数
template <class U>allocator::allocator(const allocator<U>&) // 泛化的拷贝构造函数
allocator::~allocator() // 析构函数

```
### 返回某个对象或const对象的地址
```cpp
pointer allocator::address(reference x) const
// 返回某个const对象的地址，a.address(x)等同于&x
const_pointer allocator::address(const_reference x) const
```
### 配置空间
```cpp
// 配置空间，足以存储n个T对象。第二个参数是个提示。实现上可能会利用它来增进区域性(locality)，或完全忽略之
pointer allocator::allocate(size_type n, const void* = 0)
// 释放先前配置的空间
void allocator::deallocate(pointer p, size_type n)

```
### 可配置空间的最大值，构造/析构一个对象
```cpp
// 返回可成功配置的最大量
size_type allocator:maxsize() const

// 调用对象的构造函数，等同于 new((void*)p) T(x)
void allocator::construct(pointer p, const T& x)
// 调用对象的析构函数，等同于 p->~T()
void allocator::destroy(pointer p)

```

## 工作流程
### 分配空间
1. 调用operator new配置内存(allocate)
2. 调用构造函数实例化对象(类型的构造函数，将所属空间填上值，`construct`)

### 回收空间
1. 调用每个对象的析构函数，避免对象内部分配了堆空间(destroy)
2. 调用operator delete(deallocate)
 
### 关键问题
1. 分配器调用开销
2. 内存碎片

### 双层配置器
1. 第一级配置器，直接使用malloc/free配置大内存(>128bytes)
2. 第二级配置器，内存池

### 第一级配置器
**处理内存不足**应该由调用者实现

### 第二级配置器
内存池+自由链表避免碎片化，包含16个元素的自由链表，每个链表是指针和数据的union(减少内存使用)
> 这里有一个神奇的魔法：关于某些复合类型中包含长度为1的数组，这实际上是为了兼容C下没动态数组的不得已之举
