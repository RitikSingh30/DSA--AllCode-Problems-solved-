#include <iostream>
using namespace std ;

// here ptr1 is passed to the function without reference means ptr1 ki copy pass hue hai function me to hum iss function me ptr1 
// ko kitna bhi manipulate kar le humare main function ke ptr1 ko koi bhi effect nahi hoga 
void fun(int** ptr1){
    cout << ptr1 << endl ;
    ptr1 += 1 ;
    cout << ptr1 << endl ;
}

void fun1(int **ptr1){
    // kuch change hoga -> NO 
    // ptr1 = ptr1 + 1 ;

    // Kuch change hoga -> Yes 
    // yaha pe humne bola hai ki ptr1 pe jo address pada hai and uss address pe jo value padi hai usse increment kardo to ptr1 pe ptr ka
    // address pada hua tha to wo ptr(ye ptr ke orginal memory block pe gaya hai because ptr1 ne sidha uska address diya hai) then ptr 
    // pe jo value padi hai usse increment by 1 kar diya hai to original ptr ki value bhi change hogi
    // *ptr1 = *ptr1 + 1 ;

    // kuch change hoga -> Yes
    **ptr1 = **ptr1 + 1 ;

    
}

int main(){

    int num = 5 ;
    int* ptr = &num ;
    int** ptr1 = &ptr ;

    // cout << ptr1 << endl ;
    fun(ptr1) ;

    cout << endl << endl ;
    cout << "before " << num << endl ;
    cout << "before " << ptr << endl ;
    cout << "before " << ptr1 << endl ;
    fun1(ptr1) ;
    cout << "after " << num << endl ;
    cout << "after " << ptr << endl ;
    cout << "after " << ptr1 << endl ;

    return 0 ;
}