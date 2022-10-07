#include <iostream>
#include <stdlib.h>
using namespace std;
struct Bitmap{
    int n;
    int ptr[1];
};
int main(){
    Bitmap * bitptr = new Bitmap[2];
    for(int i = 0;i < 3;i++){
        bitptr->ptr[i] = i + 2;
    }
    for(int i = 0;i < 3;i++){
        cout << bitptr->ptr[i] << endl;
    }
    // Bitmap * bit = (Bitmap *)malloc(offsetof(Bitmap,ptr) + 10 * sizeof(int));
    // for(int i = 0;i < 10;i++){
    //     *(bit->ptr+i) = i + 2;
    // }
    // for(int i = 0;i < 10;i++){
    //     cout << bit->ptr[i] << endl;
    // }
    // cout << "sizeof type " << sizeof(Bitmap) << endl << "size of inst" << sizeof(*bit) << endl;
    
    // int * x = new ;
    // cout << offsetof(Bitmap,ptr) << endl;
    // cout << sizeof(bit) << endl <<  sizeof(*bit) << endl << sizeof(int) << endl;
    // char arr[1];
    // char c;
    // char voidarr[0];
    // cout << sizeof(voidarr) << endl;
    // cout << sizeof(c) << endl << sizeof(c) << endl;
}