# TinySTL
STLImplement
Implement of Own STL
## work plan and Todo List
### 6 component of STL
1. 容器(数据结构及其操作，用于存放数据)
2. 算法(排序，搜索，深/浅拷贝)
3. 迭代器
4. 仿函数(重载()方法的模板)
5. 配接器，底层以来某个特定数据结构，可以认为是容器基础上的二次开发
6. 配置器，负责内存管理

### 命名空间
命名空间用于区分多个同名函数
#### 不连续的命名空间
同一个命名空间的多个组件可以存在多个文件中，`namespace name{}`可以添加一个元素也可定义新命名空间
#### 嵌套的命名空间
#### 编译器眼中的命名空间
namespace名称通过function mangling编码到跳转目标名称中
## 开发计划和日志
### 开发计划
1. 常见数据结构`vector,string,list,deque,set,map,pair,queue,stack`(1 month)
2. type traits(1 week)
3. 空间配置器(1 week)
4. Algorithm,包括`sort,fill,find,min,max`等
5. 其它：仿函数