#include <iostream>
using namespace std ;

class a{
    int a ; 
    int b ;
    char c ;
    double d ;
    double e ;

    public:
        void get(){
            cout << "r" << endl ;
        }
    class y{
        int z ;
    };
};
// class a{
//     char f ;
//     // int a ;
//     public: 
//         int b ;
//         char e ;
//         int c ;
//         char d ;
//         char g ;
//         // char h ;
//         a(int b , char e) : b(b) , e(e) {}
//         const void get(int a){
//             this->b = a ;
//         }
//         void set(){
//             cout << b << endl ;
//         }
// };

const int fun(int a, int b){
    return a + b ;
}
const int fun(int a){
    a++ ;
    return a ;
}


int main(){
    static a a ;
    a y c ;
    cout << sizeof(a) << endl ;
    a.get() ;
    // cout << fun(1) ;

    // a a(4,'r') ;
    // a.b++ ;
    // a.get(5) ; 
    // a.set();
    // cout << a.b << endl ;
    // cout << a.e << endl ;
    // cout << fun(2) ;

    return 0 ;
}