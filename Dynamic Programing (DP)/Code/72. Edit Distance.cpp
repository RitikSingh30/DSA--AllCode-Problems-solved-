// recursive solution 
// time complexity O(N*M) and space complexity O(N*M) 
// we have not calculated the stack space , stack space + me something hoga so usko calculate nahi kiya
class Solution {
public:
    int computeMin(int n , int m , string word1 , string word2 , vector<vector<int>>& dp){

        // base case if the length of first string is 0 then return the length of second string if the length of second string 
        // is 0 then return the first string 
        if(n <= 0) return m ;
        if(m <= 0) return n ;

        if(dp[n][m] != -1) return dp[n][m] ;

        int x = INT_MAX , y = INT_MAX , z = INT_MAX , w = INT_MAX ;
        if(word1[n - 1] == word2[m - 1]) x = computeMin(n-1,m-1,word1,word2,dp) ;
        y = 1 + computeMin(n-1,m-1,word1,word2,dp) ;
        z = 1 + computeMin(n-1,m,word1,word2,dp) ;
        w = 1 + computeMin(n,m-1,word1,word2,dp) ;

        return dp[n][m] = min({x,y,z,w}) ;
    }
    int minDistance(string word1, string word2) {
        int n = word1.length() ;
        int m = word2.length() ;

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1)) ;   

        return computeMin(n,m,word1,word2,dp) ;   
    }
};

// iterative solution 
// time complexity O(N*M) and space complexity O(N*M) 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length() ;
        int m = word2.length() ;

        vector<vector<int>> dp(n+1,vector<int>(m+1)) ;

        // base case if the length of first string is 0 then return the length of second string if the length of second string 
        // is 0 then return the first string 
        for(int i = 0 ; i <= n ; i++){
            dp[i][0] = i ;
        }
        for(int j = 0 ; j <= m ; j++){
            dp[0][j] = j ;
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                int x = INT_MAX ;
                if(word1[i - 1] == word2[j - 1]) x = dp[i - 1][j - 1] ;
                int y = 1 + dp[i - 1][j - 1] ;
                int z = 1 + dp[i - 1][j] ;
                int w = 1 + dp[i][j - 1] ;
                dp[i][j] = min({x,y,z,w}) ;
            }
        }   
        return dp[n][m] ;   
    }
};

// iterative solution + space optimisation 
// O(n + m) space  
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length() ;
        int m = word2.length() ;

        vector<int> dp(n+1) ;

        // base case if the length of first string is 0 then return the length of second string if the length of second string 
        // is 0 then return the first string 
        for(int i = 0 ; i <= n ; i++){
            dp[i] = i ;
        }

        for(int i = 1 ; i <= m ; i++){
            vector<int> temp_dp(n + 1) ;
            temp_dp[0] = i ;
            for(int j = 1 ; j <= n ; j++){
                int x = INT_MAX ;
                if(word1[j - 1] == word2[i - 1]) x = dp[j - 1] ;
                int y = 1 + dp[j - 1] ;
                int z = 1 + temp_dp[j - 1] ;
                int w = 1 + dp[j] ;
                temp_dp[j] = min({x,y,z,w}) ;
            }

            dp = temp_dp ;
        }   
        return dp[n] ;   
    }
};