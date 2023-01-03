// here we have implemented the stack using doubly linked list 
#include<iostream>
using namespace std ;

class block{
    public:
        int data ;
        block* next ;
        block* prev ;
    
        block(int data){
            this->data = data ;
            this->next = NULL ;
            this->prev = NULL ;
        }
        ~block(){
            this->prev = NULL ;
        }
};

class stack{
    block* top = NULL ;
    public:
        void insert(int data){
            block* temp = new block(data) ;
            if(top == NULL){
                top = temp ;
                return ;
            }
            temp->prev = top ;
            top->next = temp ;
            top = temp ; 
        }  

        void pop(){
            if(top == NULL) cout << "There is no element to pop " << endl ;
            else{
                block* temp = top ;
                top = top->prev ;
                if(top != NULL) top->next = NULL ;
                delete temp ;
            }
        }

        void top_element(){
            if(top == NULL) cout << "There is no element to display " << endl ;
            else cout << top->data << endl ;
        }

        void empty(){
            if(top == NULL) cout << "YES" << endl ;
            else cout << "NO" << endl ;
        }
};

int main(){
    stack stc ;
    stc.insert(1) ;
    stc.insert(2) ;
    stc.top_element() ;
    stc.insert(3) ;
    stc.top_element() ;
    stc.pop();
    stc.pop() ;
    stc.top_element() ;
    stc.empty() ;
    stc.pop() ;
    stc.top_element() ;
    stc.pop() ;
    stc.empty() ;
    return 0 ;
}