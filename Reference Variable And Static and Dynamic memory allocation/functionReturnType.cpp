#include <iostream>
using namespace std ;

// Note: We should never return a local variable as a reference, reason being, as soon as the functions returns, local variable 
// will be erased, however, we still will be left with a reference which might be a security bug in the code.
// this is not a good practice to return a reference variable 
int& fun(int a){
    int num = a ;
    int& ans = num ;
    return ans ;
}

void foo(int& a, int& b) {
    a=1;
    std::cout << b << std::endl;
}  

int main(){
    
    int a = 5 ;
    int &b = fun(a) ;
    cout << b << endl ;
    // fun(a) ;
    int p=2;
    foo (p,p); //this will print 1 instead of 2;
    
    return 0 ;
}
