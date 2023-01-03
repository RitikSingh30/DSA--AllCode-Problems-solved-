#include <iostream>
using namespace std ;

int main(){
    char c = 'a' ;
    char* ch = &c; 
    cout << sizeof(ch) << endl ;

    int n ;
    cin >> n; 

    // variable size array 
    int* arr = new int[n] ;   
    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
    for(int i = 0 ; i < n ; i++) cout << arr[i] ;
    cout << endl ;
    // deleting the memory of array which we have created in the heap using new keyowd 
    delete []arr ;

    // created the integer in heap 
    int* i = new int ;
    *i = n ;
    cout << *i << endl ;
    // deleting the memory of integer which we have created in heap using new keyword ;
    delete i ;
    
    return 0 ;
}