# include <bits/stdc++.h>
using namespace std;

#define nline "\n" 
typedef long long intt;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n , m ;
    cin >> n >> m ;

    vector<int> pages(n) , value(n) ;
    vector<vector<int>> dp(n + 1,vector<int>(m + 1,0)) ;


    for(auto &x:value) cin >> x ;
    for(auto &x:pages) cin >> x ;

    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            dp[i][j] = dp[i - 1][j] ;

            if(j - value[i - 1] >= 0){
                dp[i][j] = max(dp[i][j],dp[i - 1][j - value[i - 1]] + pages[i - 1]) ;
            }
        }
    }

    cout << dp[n][m] ;
    
    return 0;
}