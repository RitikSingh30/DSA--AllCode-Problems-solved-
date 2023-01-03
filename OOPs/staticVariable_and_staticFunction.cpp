#include <iostream>
using namespace std ;

// declaring static variable globally 
static int mem = 8 ;

class a{
    int var = 1 ;
    public:
    // declaring static variable in class 
    static int s ;
};

class b{
    int c ;
    public:
    void fun(){
        a::s++ ;
        
    }
    const int con = 3 ;
    static void fun2(){
        // using static variable of different class in another class 
        a::s++ ;
        cout << "ritik" << endl ;
    }
};

class c{
    public:
        void fun1(){
            // using static function of different class in another class 
            b::fun2() ;
        }
};

int a::s = 5; 

int main(){
    a obj ;
    // printing static variable without object
    cout << a::s << endl ;
    // printing static variable with object 
    cout << obj.s << endl ;

    // changing the value of static varible with the help of the object 
    obj.s++ ;
    b obj2 ;
    obj2.fun() ;
    // calling static function 
    b::fun2() ; 

    a obj1 ;
    cout << obj1.s << endl ;

    c obj4 ;
    obj4.fun1() ;

    cout << mem << endl ;

    return 0 ;
}