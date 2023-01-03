// Author : RITIK 
# include <bits/stdc++.h>
using namespace std;

#define nline "\n" 
typedef long long ll;

vector<pair<ll,ll>>p ;
vector<bool>visited(20,0) ;
vector<vector<ll>>v(20,vector<ll>(20)) ;
ll calc(int n){

    if(p.size() == n ){
        ll ans = 0 ;
        for (int i = 0 ; i < n ; i++)
        {
            ans ^= (v[p[i].first][p[i].second]) ;
        }
        return ans ;
    }
    ll l ;
    for (int i = 0 ; i < 2*n ; i++)
    {
        if(!visited[i]){
            l = i ;
            break ;
        }
    }
    visited[l] = 1 ;
    ll x = 0 ;
    for (int i = 0 ; i < 2*n ; i++)
    {
        if(!visited[i]){
            p.push_back({l,i}) ;
            visited[i] = 1 ;
            x = max(x,calc(n)) ;
            p.pop_back() ;
            visited[i] = 0 ;
        }
    }
    visited[l] = 0 ;
    return x ;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n ;
    cin >> n ;
    for (int i = 0 ; i < 2*n ; i++)
    {
        for (int j = i + 1 ; j < 2*n ; j++)
        {
            cin >> v[i][j] ;
        }
        
    }
    cout << calc(n) << nline ;
    

    return 0;
}