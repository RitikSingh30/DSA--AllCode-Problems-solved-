#include <bits/stdc++.h>
using namespace std;

int main(){

    string s , t ;
    cin >> s >> t ;

    int n = s.size() ;
    int m = t.size() ;

    vector<vector<int>> dp(n + 1,vector<int>(m + 1,0)) ;

    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            if(s[i - 1] == t[j - 1]){
                // if both the character are same 
                dp[i][j] = 1 + dp[i - 1][j - 1] ;
            }
            else{
                // if both the character's are different 
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]) ;
            }
        }
    }

    int i = n , j = m ;

    string ans ;

    while(i >= 1 && j >= 1){

        if(s[i - 1] == t[j - 1]){
            ans.push_back(s[i - 1]) ;
            i-- ;
            j-- ;
        }
        else if(dp[i - 1][j] >= dp[i][j - 1]) i-- ;
        else j-- ;
    }

    reverse(ans.begin(),ans.end()) ;

    cout << ans ;
    
    return 0 ;
}