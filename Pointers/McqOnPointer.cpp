#include <iostream>
using namespace std ;

int main(){

    int arr[5] ;
    int *ptr ;

    // size fo function hum jo size deta hai wo bytes me deta hai iss case me humne size of arr print kiya hai to arr ki size hai 5
    // means wo 5 integer type ke data ko store karega and ek integer ka size hota hai 4 byte to total ans hoga 5 * 4 = 20 and ptr jo 
    // hai wo pointer hai and pointer address store karta hai to pointer ki size 4 or 8 byte hoti hai compiler to compiler vary karta
    // hai  
    cout << sizeof(arr) << ' ' << sizeof(ptr) << endl ;

    int arr1[6] = {1,2,3} ;
    // teeno same output denge because arr array ke 0th element ka address store karta hai
    cout << arr << ' ' << &arr << ' ' << &arr[0] << endl ;

    // int arr2[6] = {1,2,3} ;
    // int *ptr1 = arr2++ ;
    // arr2++ ye kaam hum yaha pe nahi kar sakte because arr humara ek array hai and array increment nahi ho sakta hum yaha pe ye nahi
    // bol sakte ki array humara ek pointer hai array ek array hai and wo pointer ki tarah kaam nahi karta 
    // arr2++ ye hota hai arr2 = arr2 + 1 jiska koi meaning nahi hai arr2 ek array hai wo koi pointer ya integer value nahi hai
    // cout << (*ptr1) << endl ; 

    // Humne yaha pe character array banaya and ek character pointer banaya jisme humne character array ke first element ka address 
    // de diya but jab ab hum uss pointer ko print karenge to ch[0] ka address print nahi hoga balki puri string print ho "abcde" 
    // character pointer and integer pointer different kaam karte hai
    char ch[] = "abcde" ;
    char* ptr3 = &ch[0] ;
    string s = "ritik" ;
    char* ptr4 = &s[0] ;
    cout << ptr3 << endl ;
    cout << *ptr3 << endl ;
    cout << ptr4 << endl ;

    // double pointer example 
    int first = 110 ;
    int *p = &first ;
    int **q = &p ;
    int second = (**q)++ + 9 ;
    cout << first << ' ' << second << endl ;

    return 0 ;
}