#include <bits/stdc++.h> 
class Deque
{
public:
    // Initialize your data structure.
    int* arr ;
    int sz ;
    int qfront ; 
    int qback ;
    Deque(int n)
    {
        // Write your code here.
        sz = n ;
        arr = new int[sz] ;
        qfront = -1 ;
        qback = -1 ;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        int inc = qfront ;
        inc-- ;
        if(inc < 0) inc = sz - 1 ;
        if(inc == qback) return false ;
        arr[inc] = x ; 
        qfront = inc ;
        if(qback == -1) qback = qfront ; 
        return true ;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        int inc = qback ;
        inc++ ;
        if(inc >= sz) inc = 0 ;
        if(inc == qfront) return false ;
        arr[inc] = x ;
        qback = inc ;
        if(qfront == -1) qfront = qback ; 
        return true ;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(qfront == -1 and qback == -1) return -1;
        int x = arr[qfront] ;
        if(qfront == qback){
            qfront = -1 ;
            qback = -1 ;
        }
        else{
            qfront++ ;
            if(qfront >= sz){
                qfront = 0 ;
            }
        }
        return x ;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(qfront == -1 and qback == -1) return -1;
        int x = arr[qback] ;
        if(qfront == qback){
            qfront = qback = -1 ;
        }
        else{
            qback-- ;
            if(qback < 0){
                qback = sz - 1 ;
            }
        }
        return x ;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(qfront == -1 and qback == -1) return -1;
        else return arr[qfront] ;
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(qfront == -1 and qback == -1) return -1;
        else return arr[qback] ;
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(qfront == -1 and qback == -1) return true ;
        else return false ;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        int x = qfront ;
        x-- ;
        if(x < 0) x = sz - 1 ;
        if(x == qback) return true ;
        else return false ;
    }
};