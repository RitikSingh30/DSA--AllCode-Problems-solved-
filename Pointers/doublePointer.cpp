#include <iostream>
using namespace std ;

int main(){

    int num = 5 ;
    int* ptr = &num ;
    // This is double pointer which is used to store the address of pointer 
    int** ptr1 = &ptr ;

    // printing the value which is present in ptr the value which is present in ptr is the address of num 
    cout << ptr << endl ;

    // ptr1 ptr ka address store kar rha hai to ptr pe jo value hai hum wo print kar rhe hai (ptr and *ptr1 dono ki value same hogi)
    cout << *ptr1 << endl ; 

    // printing the value of num there are three ways to print the value of num in this code 
    cout << num << endl ;
    cout << *ptr << endl ;
    cout << **ptr1 << endl ;

    // Printing the value present inside the ptr there are three ways to print the value of ptr in this code 
    cout << &num << endl ;
    cout << ptr << endl ;
    cout << *ptr1 << endl ;

    // Printing the address of ptr there are two ways to do this in this code 
    cout << &ptr << endl ;
    cout << ptr1 << endl ;

    return 0 ;
}