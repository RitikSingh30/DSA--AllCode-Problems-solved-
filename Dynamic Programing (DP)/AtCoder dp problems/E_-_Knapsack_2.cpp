# include <bits/stdc++.h>
// # include "debugHeaderfile.h"
using namespace std;

#define nline "\n" 
typedef long long intt;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
    intt n , w ;
    cin >> n >> w ;

    vector<intt> weight(n) , value(n) ;
    intt sum = 0 ;

    for (int i = 0 ; i < n ; i++)
    {
        cin >> weight[i] >> value[i] ;
        sum += value[i] ;
    }

    vector<vector<intt>> dp(n + 1,vector<intt>(sum + 1,1e18)) ;

    for (int i = 0 ; i < n ; i++)
    {
        dp[i][0] = 0 ;
    }

    for (intt i = 1 ; i <= n ; i++)
    {
        for (intt j = 1 ; j <= sum ; j++)
        {
            dp[i][j] = dp[i - 1][j] ;

            if(j - value[i - 1] >= 0){
                dp[i][j] = min(dp[i][j],dp[i - 1][j - value[i - 1]] + weight[i - 1]) ;
            }
        }
    }

    for (intt i = sum ; i >= 0 ; i--)
    {
        if(dp[n][i] <= w){
            cout << i << nline ;
            break ;
        }
    }
    
    return 0;
}