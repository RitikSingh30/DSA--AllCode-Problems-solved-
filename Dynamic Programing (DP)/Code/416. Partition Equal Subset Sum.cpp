
// recursion + memoization 
class Solution {
public:
    bool possible(vector<int>& nums , int ind , int sum , vector<vector<int>>& dp){
        if(sum == 0) return true ;
        else if(sum < 0) return false ;
        else if(ind < 0) return false ;

        if(dp[sum][ind] != -1) return dp[sum][ind] ;

        return dp[sum][ind] = (possible(nums,ind-1,sum-nums[ind],dp) or possible(nums,ind-1,sum,dp)) ;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;
        int sum = 0 ;
        for(int i = 0 ; i < n ; i++) sum += nums[i] ;
        if(sum & 1) return false ;

        int sz = sum / 2 ;
        // dp[i][j] = can we make the sum j using i elements 
        vector<vector<int>> dp(sz + 1,vector<int>(n,-1)) ;
        
        return possible(nums,n-1,sz,dp) ;
    }
};

// iterative 
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size() ;
//         int sum = 0 ;
//         for(int i = 0 ; i < n ; i++) sum += nums[i] ;
//         if(sum & 1) return false ;

//         int sz = sum / 2 ;

//         // dp[i][j] = can we make the sum j using i elements 
//         vector<vector<bool>> dp(n + 1,vector<bool>(sz + 1,false)) ;
//         for(int i = 0 ; i <= n ; i++){
//             for(int j = 0 ; j <= sz ; j++){
//                 if(j == 0){
//                     dp[i][j] = true ;
//                     continue;
//                 }
//                 else if(i == 0) continue ;

//                 // take ith element  
//                 if(j - nums[i - 1] >= 0){
//                     dp[i][j] = dp[i - 1][j - nums[i - 1]] ;
//                 }
//                 // don't take ith element 
//                 dp[i][j] = dp[i][j] or dp[i - 1][j] ;
//             }
//         }

//         return dp[n][sz] ;
//     }
// };