#include <bits/stdc++.h> 
int findMinimumCost(string str) {
    int n = str.size() ;
    int ans = 0 ;
    stack<int> s ;

    if(n & 1) return -1 ;
    for(int i = n - 1 ; i >= 0 ; i--){
        if(str[i] == '}') s.push(1) ;
        else{
            if(s.empty()){
                ans++ ;
                s.push(1) ;
            }
            else s.pop() ;
        }
    }

    ans += (s.size() / 2) ;
    return ans ;
}