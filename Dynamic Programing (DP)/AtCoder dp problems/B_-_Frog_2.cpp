#include <bits/stdc++.h>
using namespace std;

int main(){

    int n , k ;
    cin >> n >> k ;

    vector<int> v(n) ;
    for(auto &x:v) cin >> x ;

    vector<int> dp(n,1e9) ;

    dp[0] = 0 ;

    for (int i = 1 ; i < n ; i++)
    {
        for (int j = 1 ; j <= k ; j++)
        {
            if((i - j) >= 0)
                dp[i] = min(dp[i],dp[i - j] + abs(v[i] - v[i - j])) ;
        }
    }

    cout << dp[n - 1] ;
    
}