#include <bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector<int> prevSmallestElement(vector<int>& arr , int n){
        vector<pair<int,int>> heights ;
        for(int i = n - 1 ; i >= 0 ; i--){
            heights.push_back({arr[i],i}) ;
        }
        stack<pair<int,int>> s ;
        vector<int> ans(n,-1) ;
        for(int i = 0 ; i < n ; i++){
            if(s.empty()) s.push({heights[i].first,heights[i].second}) ;
            else{
                while(!s.empty() and s.top().first > heights[i].first){
                    ans[s.top().second] = heights[i].second ;
                    s.pop() ;
                }
                s.push({heights[i].first,heights[i].second}) ;
            }
        }
        return ans ;
    }

    vector<int> nextSmallerElement(vector<int> &heights, int n)
    {
        stack<pair<int,int>> s ;
        vector<int> ans(n,-1) ;
        for(int i = 0 ; i < n ; i++){
            if(s.empty()) s.push({heights[i],i}) ;
            else{
                while(!s.empty() and s.top().first > heights[i]){
                    ans[s.top().second] = i ;
                    s.pop() ;
                }
                s.push({heights[i],i}) ;
            }
        }
        return ans ;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ;
        vector<int> prev = prevSmallestElement(heights,n) ;
        vector<int> next = nextSmallerElement(heights,n) ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            int x , y ;
            if(prev[i] == -1) x = 0 ;
            else x = prev[i] + 1 ;
            if(next[i] == -1) y = n - 1 ;
            else y = next[i] - 1 ;
            ans = max(ans,(y - x + 1) * heights[i]) ;
        }
        return ans ;
    }
};

int main(){
    int n ;
    cin >> n ;
    vector<int> arr(n) ;
    for(auto &x:arr) cin >> x ;
    cout << largestRectangleArea(arr) << endl ;
    return 0 ;
}