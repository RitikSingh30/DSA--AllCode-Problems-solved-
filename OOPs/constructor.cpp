#include <iostream>
using namespace std ;

class a{
    public:
        int b ;
        a(){
            cout << this << endl ;
            (*this).b = 1 ;
            this->b = 2 ;
        }
};

int main(){
    a obj ;
    cout << sizeof(obj) << endl ;
    cout << &obj << endl ;
    cout << obj.b << endl ;
    return 0 ;
}