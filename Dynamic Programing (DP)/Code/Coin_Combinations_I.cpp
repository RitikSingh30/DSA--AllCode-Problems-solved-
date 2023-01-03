#include <bits/stdc++.h>
using namespace std ;

#define nline '\n' 

int main(){
    int n , money ;
    cin >> n >> money ;

    vector<int> coin(n) , dp(money + 1 , 0) ;
    for(auto &x:coin) cin >> x ;

    const int mod = 1e9 + 7 ;

    dp[0] = 1 ;

    for (int i = 1 ; i <= money ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            if((i - coin[j]) >= 0){
                dp[i] += dp[i - coin[j]] ;
                dp[i] %= mod ;
            }
        }
    }

    cout << dp[money] ;
    

    return 0 ;
}