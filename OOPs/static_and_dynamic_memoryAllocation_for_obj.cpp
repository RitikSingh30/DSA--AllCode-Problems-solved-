#include <iostream>
using namespace std ;

class a{
    public:
        int a = 1 ;
        char c = '2' ;
};

int main(){
    // statically creation of class 
    a obj ;
    // dynamically creation of class 
    a* obj1 = new a ;
    cout << sizeof(obj) << endl ;
    cout << sizeof(*obj1) << endl ;

    // printing the variable of class which is statically created
    cout << obj.a << endl ;
    cout << obj.c << endl ;

    // printing the variable of class which is dynamically created 
    cout << (*obj1).a << endl ;
    cout << (*obj1).c << endl ;
    // alternative for printing the variable of class which is dynamically created 
    cout << obj1->a << endl ;
    cout << obj1->c << endl ;
    
    return 0 ;
}