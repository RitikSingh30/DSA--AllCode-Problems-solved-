// Author : RITIK 
# include <bits/stdc++.h>
using namespace std;

#define nline "\n" 
typedef long long ll;

bool check(vector<ll>&v , ll n , ll k , ll mid){
    ll cnt = 0 , sum = 0 ;
    for (int i = 0 ; i < n ; i++)
    {
        if(v[i]>mid) return false ;
        if(sum+v[i]>mid){
            cnt++ ;
            sum = 0 ; 
            sum += v[i] ;
        }else sum += v[i] ;
    }
    if(sum!=0 && sum<=mid) cnt++ ;
    return (cnt <= k) ;
    
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    ll n , k , ans ;
    cin >> n >> k ;
    vector<ll>v(n) ;
    for(auto &x:v) cin >> x ;
    ll l = 0 , r = 1e18 ;
    while(l<=r){
        ll mid = l + (r - l)/2 ;
        if(check(v,n,k,mid)){
            ans = mid ;
            r = mid - 1 ;
        }
        else l = mid + 1 ;
    }
    cout << ans << nline ;
    return 0;
}