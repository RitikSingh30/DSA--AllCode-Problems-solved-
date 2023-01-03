// Recursive solution 
// time complexity O(N^2) , space complexity O(N^2)
class Solution {
public:
    int find(vector<vector<int>>& matrix , int n , int m , int row_sz , vector<vector<int>>& dp){
        if(n <= 0 || m <= 0 || m > row_sz) return 1e9 ;

        if(dp[n][m] != -1e9) return dp[n][m] ;

        int x = matrix[n - 1][m - 1] + find(matrix,n-1,m,row_sz,dp) ;
        int y = matrix[n - 1][m - 1] + find(matrix,n-1,m-1,row_sz,dp) ;
        int z = matrix[n - 1][m - 1] + find(matrix,n-1,m+1,row_sz,dp) ;

        return dp[n][m] = min({x,y,z}) ;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = n ;

        vector<vector<int>> dp(n+1,vector<int>(m + 1,-1e9)) ;
        // defining the base case for dp 
        for(int i = 1 ; i <= m ; i++) dp[1][i] = matrix[0][i - 1] ;

        for(int i = 1 ; i <= m ; i++){
            dp[n][i] = find(matrix,n,i,m,dp) ;
        }

        int ans = INT_MAX ;
        for(int i = 1 ; i <= m ; i++) ans = min(ans,dp[n][i]) ;

        return ans ;
    }
};

// iterative solution 
// time complexity O(N^2) , space complexity O(N^2)
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size() ;
//         int m = n ;

//         vector<int> dp(m+1,1e9) ;

//         for(int i = 1 ; i <= m ; i++) dp[i] = matrix[0][i - 1] ;
        
//         for(int i = 2 ; i <= n ; i++){
//             vector<int> temp_dp(m + 1) ;
//             for(int j = 1 ; j <= m ; j++){
//                 int x = dp[j - 1] + matrix[i - 1][j - 1] ;
//                 int y = dp[j] + matrix[i - 1][j - 1] ;
//                 int z = (j < m ? dp[j + 1] + matrix[i - 1][j - 1] : 1e9) ;
//                 temp_dp[j] = min({x,y,z}) ;
//             }
//             dp = temp_dp ;
//         }

//         int ans = INT_MAX ;
//         for(int i = 1 ; i <= m ; i++) ans = min(ans,dp[i]) ;

//         return ans ;
//     }
// };

// iterative solution + Space optimisation 
// time complexity O(N^2) , space complexity O(N)
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size() ;
//         int m = n ;

//         vector<int> dp(m+1,1e9) ;

//         for(int i = 1 ; i <= m ; i++) dp[i] = matrix[0][i - 1] ;
       
//         for(int i = 2 ; i <= n ; i++){
//             vector<int> temp_dp(m + 1,1e9) ;
//             for(int j = 1 ; j <= m ; j++){
//                 int x = dp[j - 1] + matrix[i - 1][j - 1] ;
//                 int y = dp[j] + matrix[i - 1][j - 1] ;
//                 int z = (j < m ? dp[j + 1] + matrix[i - 1][j - 1] : 1e9) ;
//                 temp_dp[j] = min({x,y,z}) ;
//             }
//             dp = temp_dp ;
//         }

//         int ans = INT_MAX ;
//         for(int i = 1 ; i <= m ; i++) ans = min(ans,dp[i]) ;

//         return ans ;
//     }
// };