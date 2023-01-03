#include <iostream>
using namespace std ;

template<typename T>
class stack{
    // data member of stack class 
    T* arr ;
    int size ;
    int top ;
    
    public:
    // constructor to initiallize the data member of the class
    stack(int size){
        this->size = size ;
        arr = new T(size) ;
        top = -1 ;
    }
    // methods of the stack class 
    void push(int data){
        if(size - top <= 1){
            cout << "Stack Overflow" << endl ;
        }
        else{
            top++ ;
            arr[top] = data ;
        }
    }

    void pop(){
        if(top == -1){
            cout << "Stack is already Empty" << endl ;
        }
        else{
            arr[top] = 0 ;
            top-- ;
        }
    }

    T peek(){
        if(top == -1){
            cout << "Stack is Empty" << endl ;
            return (T) -1 ;
        }
        else{
            return arr[top] ;
        }
    }

    bool empty(){
        return (top == -1 ? 1 : 0) ;
    }
};

int main(){
    stack<int> s(5) ;
    s.push(22) ;
    cout << s.empty() << endl ;
    cout << s.peek() << endl ;
    s.pop() ;
    s.pop() ;
    return 0 ;
}