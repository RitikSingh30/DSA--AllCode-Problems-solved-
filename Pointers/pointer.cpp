#include <iostream>
using namespace std ;

int main(){

    int num = 5 ;

    int* ptr = &num ;

    // dereferencing the pointer and incrementing the value of num by 1 
    (*ptr)++ ;

    cout << num << endl ;

    // ptr pointer pe jo address pada hua hai uski value de do
    cout << *ptr << endl ;

    // printing address of num variable 
    cout << &num << endl ;
    cout << ptr << endl ;

    // creating double data type pointer 
    double d = 1.23 ;
    double *ptr1 = &d ;

    cout << ptr1 << endl ;

    // printing the size of integer pointer 
    cout << sizeof(*ptr) << endl ;
    cout << sizeof(ptr) << endl ;

    // printing the size of double pointer 
    cout << sizeof(*ptr1) << endl ;
    cout << sizeof(ptr1) << endl ;

    // pointer to int created and pointing to some garbage value 
    int *ptr2 ;
    cout << *ptr2 << endl ;  

    // pointer to int created and pointing to null value 
    // int *ptr3 = 0 ;
    // cout << *ptr3 << endl ;

    // coping pointer to another pointer 
    int a = 5 ;
    int *ptr4 = &a ;
    int *ptr5 = ptr4 ;

    cout << ptr4 << ' ' << ptr5 << endl ;
    cout << *ptr4 << ' ' << *ptr5 << endl ;

    // int b[] = {1,2,3,4} ;
    // int* p = b++ ;
    // cout << *p << endl ;
    // cout << b << endl ;

    return 0 ;
}