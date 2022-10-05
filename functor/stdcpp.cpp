#include <iostream>
#include <functional>
using namespace std;
class MySort{
public:
    bool operator()(int a,int b){
        return a > b;
    }
};
int main(){
    cout << MySort()(1,2) << endl;
    cout << min<int>(1,2);
}