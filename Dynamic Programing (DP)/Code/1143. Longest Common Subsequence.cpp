#include <bits/stdc++.h>
using namespace std ;


class Solution {
public:
    // iterative dp 
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() ;
        int m = text2.size() ;
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0)) ;

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j]++ ;
                    dp[i][j] += dp[i - 1][j - 1] ;
                }
                else dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]) ;
            }
        }

        return dp[n][m] ;
    }

    // recursive dp 
    int longestCommonSubsequenceRec(string text1 , string text2 , int i , int j , vector<vector<int>>&dp){
        if(i == text1.size() || j == text2.size()) return 0 ;

        // memoization 
        if(dp[i][j] != -1) return dp[i][j] ;

        int ans = 0 ;
        if(text1[i] == text2[j]){
            ans = 1 + longestCommonSubsequenceRec(text1,text2,i+1,j+1,dp) ;
        }
        else ans = max(longestCommonSubsequenceRec(text1,text2,i+1,j,dp) , longestCommonSubsequenceRec(text1,text2,i,j+1,dp)) ;

        return dp[i][j] = ans ;
    }

    // iterative space optimization 
    int longestCommonSubsequenceSpace_opt(string text1, string text2) {
        int n = text1.size() ;
        int m = text2.size() ;
        vector<int> prev(n + 1,0) ;

        for(int i = 1 ; i <= m ; i++){
            vector<int> cur(n + 1,0) ;
            for(int j = 1 ; j <= n ; j++){
                if(text1[j - 1] == text2[i - 1]){
                    cur[j] = 1 + prev[j - 1] ; 
                }
                else cur[j] = max(cur[j - 1],prev[j]) ;
            }
            prev = cur ;

        }

        return prev[n] ;
    }

};

int main(){
    string a , b ;
    cin >> a >> b ;
    Solution s ;
    // cout << s.longestCommonSubsequence(a,b) << endl ;
    vector<vector<int>>dp(a.size(),vector<int>(b.size(),-1)) ;
    // cout << s.longestCommonSubsequenceRec(a,b,0,0,dp) << endl ;
    cout << s.longestCommonSubsequenceSpace_opt(a,b) << endl ;
    return 0 ;
}