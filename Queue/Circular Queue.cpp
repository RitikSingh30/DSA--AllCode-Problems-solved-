#include <bits/stdc++.h> 
class CircularQueue{
    public:
    // Initialize your data structure.
    int* arr ;
    int sz ;
    int qfront ;
    int qback ;  
    CircularQueue(int n){
        // Write your code here.
        sz = n ;
        arr = new int[sz] ;
        qfront = -1 ;
        qback = -1 ;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        qback++ ;
        if(qback >= sz) qback = 0 ;
        if(qback == qfront) return false ;
        arr[qback] = value ;
        if(qfront == -1) qfront++ ;
        if(qfront >= sz) qfront = 0 ;
        return true ;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(qfront == -1) return -1 ;
        int x = arr[qfront] ;
        qfront++ ;
        if(qfront - qback == 1){
            qfront = -1 ;
            qback = -1 ;
        }
        if(qfront >= sz) qfront = 0 ;
        return x ;
    }
};


