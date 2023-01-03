#include <bits/stdc++.h>
using namespace std ;

int main(){
    int n ;
    cin >> n ;

    vector<int> dp(n + 1,1e9) ;
    vector<vector<bool>> pre(n + 1,vector<bool>(10,0)) ;

    for (int i = 1 ; i <= n ; i++)
    {
        string s = to_string(i) ;
        int sz = s.size() ;

        for (int j = 0 ; j < sz ; j++)
        {
            pre[i][s[j] - '0'] = 1 ;
        }
        
    }

    dp[n] = 0 ;
    
    for (int i = n - 1 ; i >= 0 ; i--)
    {
        for (int j = 1 ; j <= 9 ; j++)
        {
            if((i + j) <= n && pre[i + j][j]){
                dp[i] = min(dp[i],dp[i + j] + 1) ;
            }
        }
        
    }
    
    cout << dp[0] ;

    return 0 ;
}
