#include <iostream>
using namespace std ;

class a{
    int a ;
    public:
        ~a(){
            cout << "Destructor is called " << endl ;
        }
};

int main(){
    // statically created object ke destructor atomatically call ho jata hai
    a obj ;

    // Dynamically created object ke liye destructor manually call karna padta hai 
    a* obj1 = new a ;
    delete obj1 ;

    return 0 ;
}