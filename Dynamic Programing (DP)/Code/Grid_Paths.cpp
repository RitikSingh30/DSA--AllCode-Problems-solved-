# include <bits/stdc++.h>
using namespace std;

using intt = long long int ;

int main(){
    int n ;
    cin >> n ;

    vector<string> arr(n) ;
    for(auto &x:arr) cin >> x ;

    vector<vector<intt>> dp(n,vector<intt>(n,0)) ;

    dp[0][0] = (arr[0][0] == '.' ? 1 : 0) ;

    intt mod = 1e9 + 7 ; 

    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            if(i - 1 >= 0 && arr[i][j] == '.' && arr[i - 1][j] == '.'){
                dp[i][j] += dp[i - 1][j] ;
                dp[i][j] = dp[i][j] % mod ;
            }
            if(j - 1 >= 0 && arr[i][j] == '.' && arr[i][j - 1] == '.'){
                dp[i][j] += dp[i][j - 1] ;
                dp[i][j] = dp[i][j] % mod ;
            }
        }
        
    }

    cout << dp[n - 1][n - 1] ;
    
    return 0 ;
}