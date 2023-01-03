# include <bits/stdc++.h>
# include "debugHeaderfile.h"
using namespace std;

#define nline "\n" 
typedef long long intt;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector<vector<int>> dp(n + 1,vector<int>(k + 1,0)) ;

    for(int i = 0 ; i <= n ; i++)
        dp[i][0] = 1 ;

    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= k ; j++)
        {
            dp[i][j] = dp[i - 1][j] ;

            if(j - arr[i - 1] >= 0){
                dp[i][j] = (dp[i][j] || dp[i - 1][j - arr[i - 1]]) ;
            }
        }
    }

    return dp[n][k] ;
    
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
    int t ;
    cin >> t ;

    while(t--){
        int n , k ;
        cin >> n >> k ;

        vector<int> arr(n) ;
        for(auto &x:arr) cin >> x ;

        cout << subsetSumToK(n,k,arr) << nline ;

    }

    return 0;
}