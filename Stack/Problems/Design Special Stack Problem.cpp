// Time complexity O(1) , Space complexity O(1) 
#include<stack>
#include<limits.h>
class SpecialStack {
    // Define the data members.
	stack<int> s;
    int mini = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else
        {
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }   
            else
            {
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty())
            return -1;
        
        return mini;
    }  
};

// Time complexity O(1) , Space complexity O(N) 
#include<bits/stdc++.h>
class SpecialStack {
    // Define the data members.

    /*----------------- Public Functions of SpecialStack -----------------*/
    private:
        stack<int> s , s1 ;
    public:
        
    void push(int data) {
        // Implement the push() function.
        s.push(data) ;
        if(s1.empty()) s1.push(data) ;
        else if(s1.top() >= data) s1.push(data) ;
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty()) return -1 ;
        int x = s.top() ;
        s.pop() ;
        if(x == s1.top()) s1.pop() ;
        return x ;
    }

    int top() {
        // Implement the top() function.
        if(s.empty()) return -1 ;
        return s.top() ;
    }

    bool isEmpty() {
        return s.empty() ;
    }

    int getMin() {
        if(s1.empty()) return -1 ;
        return s1.top() ;
    }  
};