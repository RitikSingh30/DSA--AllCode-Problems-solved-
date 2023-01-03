// here we have used O(S + N + N) extra space 
// O(S + 2N) 
// O(S + N)
#include <bits/stdc++.h> 
class NStack
{
    private:
        vector<pair<int,int>> st ; // the array to store the element and the index of it's previous element 
        vector<int> stTop ; // this will store the top element index of every stack 
        stack<int> ePlace ; // this will store the empty places in the array 
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        st.resize(S) ;
        stTop.resize(N + 1) ;
        for(int i = 0 ; i < S ; i++){
            ePlace.push(i) ;
        }

        for(int i = 0 ; i <= N ; i++){
            stTop[i] = -1 ;
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(ePlace.empty()) return false ;
        int ind = ePlace.top() ;
        ePlace.pop() ;
        st[ind] = {x,stTop[m]} ;
        stTop[m] = ind ;
        return true ;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(stTop[m] == -1) return -1 ;
        int ind = stTop[m] ;
        ePlace.push(ind) ;
        stTop[m] = st[ind].second ;
        return st[ind].first ;
    }
};