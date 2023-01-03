#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10 ;
int dp[N] ;

int fun(int n , vector<int>& v){
    if(n == 0) return 0 ;

    if(dp[n] != -1) return dp[n] ;

    int cost = INT_MAX ;

    // way 1
    cost = min(cost,fun(n - 1,v) + abs(v[n - 1] - v[n])) ;

    // way 2 
    if(n > 1)
        cost = min(cost,fun(n - 2,v) + abs(v[n - 2] - v[n])) ;

    return dp[n] = cost ;
}

int main(){

    memset(dp,-1,sizeof(dp)) ;

    int n ;
    cin >> n ;

    vector<int> v(n) ;
    for(auto &x:v) cin >> x ;

    cout << fun(n - 1,v) ;
}