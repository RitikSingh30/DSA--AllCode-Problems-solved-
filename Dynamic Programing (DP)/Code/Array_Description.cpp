# include <bits/stdc++.h>
// # include "debugHeaderfile.h"
using namespace std;

#define nline "\n" 
typedef long long intt;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    intt n , m ;
    cin >> n >> m ;
    vector<intt> arr(n) ;
    for(auto &x:arr) cin >> x ;

    intt mod = 1e9 + 7 ;

    vector<vector<intt>> dp(m + 1,vector<intt>(n,0)) ;

    if(arr[0] == 0){

        for (intt i = 1 ; i <= m ; i++)
        {
            if(n > 1){

                if(arr[1] == 0) dp[i][0] = 1 ;   
                else if(abs(arr[1] - i) <= 1) dp[i][0] = 1 ;

            }
            else dp[i][0] = 1 ;
        }
        
    }
    else dp[arr[0]][0] = 1 ;

    for (intt i = 1 ; i < n ; i++)
    {
        if(arr[i] != 0){

            dp[arr[i]][i] += (dp[arr[i] - 1][i - 1] + dp[arr[i]][i - 1]) ;

            if(arr[i] + 1 <= m){
                dp[arr[i]][i] += dp[arr[i] + 1][i - 1] ;
            }

            dp[arr[i]][i] %= mod ; 
            continue;
        }

        for (intt j = 1 ; j <= m ; j++)
        {
            if((arr[i] == 0 || abs(arr[i] - j) <= 1) && (((i + 1) < n && (arr[i + 1] == 0 || abs(arr[i + 1] - j) <= 1)) || (i + 1 <= n))){
                dp[j][i] += (dp[j - 1][i - 1] + dp[j][i - 1]) ;
            
                if(j + 1 <= m){
                    dp[j][i] += dp[j + 1][i - 1] ;
                }

                dp[j][i] %= mod ;
            }
        }
    }
    
    intt ans = 0 ;

    for (intt i = 1 ; i <= m ; i++)
    {
        ans += dp[i][n - 1] ;
        ans %= mod ; 
    }

    cout << ans << nline ;

    return 0;
}