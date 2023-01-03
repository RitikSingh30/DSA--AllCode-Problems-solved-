// recursive dp solution 
class Solution {
public:
    // dp[i][j] = can we reach the end point from i if our previous move was j 
    bool reach(vector<int>& stones , int pos , int prevpos , set<int>& s , map<pair<int,int>,bool>&dp){
        if(pos == stones.back()) return 1 ;
        else if(pos > stones.back() || s.find(pos) == s.end()) return 0 ;

        if(dp.find({pos,prevpos}) != dp.end()) return dp[{pos,prevpos}] ;
        bool x = 0 ;
        if(pos == 0) x = reach(stones,pos+1,1,s,dp) ; 
        else{
            x = reach(stones,pos+prevpos,prevpos,s,dp) ;
            if(prevpos - 1 > 0) x = x or reach(stones,pos+prevpos-1,prevpos-1,s,dp) ;
            x = x or reach(stones,pos+prevpos+1,prevpos+1,s,dp) ;

        }
        return dp[{pos,prevpos}] = x ;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size() ;
        map<pair<int,int>,bool> dp ;

        set<int> s ;
        for(auto &x:stones) s.insert(x) ;

        return reach(stones,0,0,s,dp) ;        
    }
};

// without using dp 
// class Solution {
// public:
//     bool canCross(vector<int>& stones) {
//         int n = stones.size() ;
//         vector<set<int>> dp(n) ;
//         dp[0].insert(1) ;
//         for(int i = 1 ; i < n ; i++){
//             for(int j = i - 1 ; j >= 0 ; j--){
//                 int x = stones[i] - stones[j] ;
//                 if(dp[j].find(x) != dp[j].end()){
//                     dp[i].insert(x - 1) ;
//                     dp[i].insert(x) ;
//                     dp[i].insert(x + 1) ;
//                 }
//             }
//         }
//         return !dp[n - 1].empty() ;       
//     }
// };