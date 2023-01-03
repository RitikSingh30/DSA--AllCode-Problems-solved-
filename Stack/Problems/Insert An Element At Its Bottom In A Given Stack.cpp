#include <bits/stdc++.h> 
void put(stack<int>& s , int x){
    if(s.empty()){
        s.push(x) ;
        return ;
    }
    
    int a = s.top() ;
    s.pop() ;
    put(s,x) ;
    s.push(a) ;
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    put(myStack,x) ;
    return myStack ;
}
