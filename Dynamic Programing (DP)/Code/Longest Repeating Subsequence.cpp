class Solution {
    public:
        int LongRepSub(string& str , int i , int j , vector<vector<int>>& dp){
            if(i < 0 || j < 0) return 0 ;

            if(dp[i][j] != -1) return dp[i][j] ;

            int x = 0 , y = 0 ;
            if(str[i] == str[j] and i != j) x = 1 + LongRepSub(str,i-1,j-1,dp) ;
            y = max(LongRepSub(str,i,j-1,dp),LongRepSub(str,i-1,j,dp)) ;

            return dp[i][j] = max(x,y) ; 
        }
        int LongestRepeatingSubsequence(string str){
            int n = str.length() ;

            vector<vector<int>> dp(n,vector<int>(n,-1)) ;
            return LongRepSub(str,n-1,n-1,dp) ;
        }

};