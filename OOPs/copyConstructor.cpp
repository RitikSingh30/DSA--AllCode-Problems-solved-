#include <bits/stdc++.h>
using namespace std ;

class a{
    public:
        int b ;
        char r ;
        char* name ;
        a(char arr[] ,int b){
            name = new char[5] ;
            strcpy(this->name,arr) ;
            this->b = b ;
            r = 'r' ;
        }
};

class c{
    public:
        int b ;
        char r ;
        char* name ;
        c(char arr[] ,int b){
            name = new char[5] ;
            strcpy(this->name,arr) ;
            this->b = b ;
            r = 'r' ;
        }
        c(c& temp){
            char* ch = new char[strlen(temp.name) + 1] ;
            // name = ch ;
            // strcpy ne temp.name ke andar ka content ch me dala 
            strcpy(ch,temp.name) ;
            
            // yaha pe temp.name pe jo address pada hua tha wo ch me aaya hai 
            // ch = temp.name ;

            this->name = ch ;
            // name = ch ;
            // this->name = temp.name ;
            this->b = temp.b ;
            this->r = temp.r ;
        }

};

int main(){
    char arr[] = "ritik";
    a obj1(arr,2) ;
    // making use of copy constructor 
    a obj2(obj1) ;
    cout << obj1.b << ' ' << obj1.r << ' ' << obj1.name << endl ;
    cout << obj2.b << ' ' << obj2.r << ' ' << obj2.name << endl ;

    // taking a look on shallow copy 
    obj1.name[0] = 'A' ;
    cout << obj1.b << ' ' << obj1.r << ' ' << obj1.name << endl ;
    cout << obj2.b << ' ' << obj2.r << ' ' << obj2.name << endl ;
    cout << endl ;

    // taking a look on deep copy
    cout << arr << endl ;
    c obj3(arr,3) ;
    c obj4(obj3) ;

    // obj3.name[0] = 'A' ;
    cout << obj3.b << ' ' << obj3.r << ' ' << obj3.name << endl ;
    cout << obj4.b << ' ' << obj4.r << ' ' << obj4.name << endl ;

    return 0 ;
}