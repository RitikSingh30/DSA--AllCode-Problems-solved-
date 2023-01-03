#include <bits/stdc++.h> 
class TwoStack {

public:
    int* arr ;
    int size ;
    int top1 ;
    int top2 ;
    // Initialize TwoStack.
    TwoStack(int s) {
        this->size = s ;
        arr = new int[s] ;
        top1 = -1 ;
        top2 = size ;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top1 + 1 != top2){
            top1++ ;
            arr[top1] = num ;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2 - 1 != top1){
            top2-- ;
            arr[top2] = num ;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 == -1) return -1 ;
        else{
            int ans = arr[top1] ;
            top1-- ;
            return ans ;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 == size) return -1 ;
        else{
            int ans = arr[top2] ;
            top2++ ;
            return ans ;
        }
    }
};
