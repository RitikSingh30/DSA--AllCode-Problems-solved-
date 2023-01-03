# include <bits/stdc++.h>
using namespace std ;

#define nline "\n" 
typedef long long intt;

int main(){

    int n ;
    cin >> n ;

    vector<vector<int>> v(n,vector<int>(3)) , dp(n,vector<int>(3));

    for(auto &x:v) 
        for(auto &y:x) 
            cin >> y ;

    dp[0][0] = v[0][0] ;
    dp[0][1] = v[0][1] ;
    dp[0][2] = v[0][2] ;

    for (int i = 1 ; i < n ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            if(j == 0){
                dp[i][j] = max(dp[i - 1][1] , dp[i - 1][2]) + v[i][j] ;
            }
            else if(j == 1){
                dp[i][j] = max(dp[i - 1][0] , dp[i - 1][2]) + v[i][j] ;
            }
            else 
                dp[i][j] = max(dp[i - 1][0] , dp[i - 1][1]) + v[i][j] ;
        }
    }

    cout << max({dp[n - 1][0],dp[n - 1][1],dp[n - 1][2]}) ;
    
}