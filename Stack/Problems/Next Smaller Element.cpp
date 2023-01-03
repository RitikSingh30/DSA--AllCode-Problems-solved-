#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<pair<int,int>> s ;
    vector<int> ans(n,-1) ;
    for(int i = 0 ; i < n ; i++){
        if(s.empty()) s.push({arr[i],i}) ;
        else{
            while(!s.empty() and s.top().first > arr[i]){
                ans[s.top().second] = arr[i] ;
                s.pop() ;
            }
            s.push({arr[i],i}) ;
        }
    }

    return ans ;
}