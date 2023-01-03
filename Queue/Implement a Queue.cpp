#include <bits/stdc++.h> 
class Queue {
public:
    int sz ;
    int* arr ;
    int qfront ;
    int qrare ;
    Queue() {
        sz = 100001;
        arr = new int[sz] ;
        qfront = -1 ;
        qrare = -1 ;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return (qfront == -1 ? 1 : 0) ;
    }

    void enqueue(int data) {
        if(qrare < sz - 1){
            if(qfront == -1) qfront++ ;
            qrare++ ;
            arr[qrare] = data ;
        }
    }

    int dequeue() {
        if(qfront == -1) return -1 ;
        int x = arr[qfront] ;
        qfront++ ;
        if(qfront > qrare){
            qfront = -1 ;
            qrare = -1 ;
        }
        else if(qfront == qrare){
            qfront = 0 ;
            arr[qfront] = arr[qrare] ;
            qrare = 0 ;
        }
        return x ;
    }

    int front() {
        if(qfront == -1) return -1 ;
        else return arr[qfront] ;
    }
};