// without dp 
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            while(i < n - 1 and prices[i + 1] <= prices[i]) i++ ;
            int x = i ;
            while(i < n - 1 and prices[i + 1] >= prices[i]) i++ ;
            int y = i ;

            ans += prices[y] - prices[x] ;
        }

        return ans ;   
    }
};

// Recursion + memoization 
// time comlexity O(N) , space complexity O(N*2 + N) extra N is for stack space 
// class Solution {
// public:
    
//     int profit(vector<int>& prices , int ind , int buy , vector<vector<int>>& dp){
//         if(ind >= prices.size()) return 0 ;

//         if(dp[ind][buy] != -1) return dp[ind][buy] ;
//         int x = 0 , y = 0 ;
//         if(buy){
//             x = -prices[ind] + profit(prices,ind+1,0,dp) ;
//             y = profit(prices,ind+1,1,dp) ;
//         }
//         else{
//             x = prices[ind] + profit(prices,ind+1,1,dp) ;
//             y = profit(prices,ind+1,0,dp) ;
//         }

//         return dp[ind][buy] = max(x,y) ;
//     }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size() ;

//         vector<vector<int>> dp(n,vector<int>(2,-1)) ;
        
//         return profit(prices,0,1,dp) ;   
//     }
// };

// Tabulation 
// time comlexity O(N) , space complexity O(N*2)
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size() ;

//         vector<vector<int>> dp(n + 1,vector<int>(2,0)) ;
        
//         for(int i = n - 1 ; i >= 0 ; i--){
//             dp[i][1] = max(-prices[i] + dp[i + 1][0],dp[i + 1][1]) ;
//             dp[i][0] = max(dp[i + 1][1] + prices[i],dp[i + 1][0]) ;
//         }
//         return dp[0][1] ;   
//     }
// };

// Tabulation + Space Optimisation 
// time comlexity O(N) , space complexity O(1) 
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size() ;

//         vector<int> dp(2,0) ;
//         for(int i = n - 1 ; i >= 0 ; i--){
//             vector<int> prev(2) ;
//             prev[1] = max(-prices[i] + dp[0],dp[1]) ;
//             prev[0] = max(dp[1] + prices[i],dp[0]) ;
//             dp = prev ;
//         }
//         return dp[1] ;   
//     }
// };