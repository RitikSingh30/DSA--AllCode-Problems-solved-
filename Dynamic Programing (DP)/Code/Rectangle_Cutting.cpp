// Author : RITIK 
# include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pi 3.1415926535897932384626
#define fo(i,a,b) for(intt i = a ; i < b ; i++)
#define pb push_back
#define eif else if 
#define spc  <<" "<<
#define ff first
#define ss second
#define nline "\n" 
#define vintt vector<intt>
#define vpl vector<pair<intt,intt>>
#define all(v) v.begin(), v.end()
#define mod 1000000007
#define lcm(a,b) (a*b)/__gcd(a,b)
#define sz(a) a.size()

typedef long long intt ;

#ifndef RITIK_SINGH
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef tree<intt,null_type,less<intt>,rb_tree_tag,tree_order_statistics_node_update> ordered_set ;
template<typename T>
istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i;        return is; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) { for (auto& i : v) os << i << "\n"; return os; }

void _print(intt t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned int t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T , class U = T> void _print(vector<pair<T,U>> v){cerr << "[ " ;for (auto [i,j] : v){cerr << "(" ;_print(i) ;cerr << "," ;
_print(j) ;cerr << ") " ;}cerr << "]" ;}
template<class T> void _print(vector<vector<T>> v){cerr << '\n' ;for (auto i : v){for(auto j : i){_print(j) ;cerr << " " ;}
cerr << '\n' ;}cerr << '\n' ;}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*------------------------------------------------------------------------------------------------------------------------------------------*/
intt binaryExponential(intt a , intt b){
intt ans = 1 ; while(b){ if(b&1){ ans = (ans%mod * a%mod)%mod ; } a = (a%mod*a%mod)%mod ; b>>=1 ; }
return ans ;}
void seive() { vector<intt> prime(10000007, 1); prime[0] = prime[1] = 0; for (int i = 2; i * i <= 10000007; i++)
{ if (prime[i]) { for (int j = i * i; j <= 10000007; j += i) prime[j] = 0; } }  }
bool isprime(int n) { if (n < 2) return false;
for (int i = 2; i * i <= n; i++){if (n % i == 0){return false;}}return true;}
//Time complexity O(sqrt(n))
intt factors(intt n){intt count = 0 ;for (int i = 1 ; i*i <= n ; i++){if(n%i==0){count++ ;if(n/i!=i){count++ ;}}}return count ;}
intt gcd(intt a, intt b) {if (!b)return a; return gcd(b, a % b);}
/*-------------------------------------------------TEMPLATE END----------------------------------------------------------------------------*/

void solution(){
    // dp[i][j] = minimum operation required to cut the i row , j column rectangle into square 
    // if we have a rectangle we can only cut it by vertically or horizontally so try all the possible 
    // ways 
    intt n , m ;
    cin >> n >> m ;
    vector<vector<intt>> dp(n + 1,vector<intt>(m + 1,-1)) ;

    // recursive approach 
    auto oper = [&](intt i , intt j , auto&& oper) -> intt {
        if(i <= 0 or j <= 0 or i == j) return 0 ;

        if(dp[i][j] != -1) return dp[i][j] ;

        intt less = INT_MAX ;
        for(intt k = 1 ; k < i ; k++){
            intt x = oper(k,j,oper) ;
            intt y = oper(i-k,j,oper) ;

            less = min(less,x+y+1) ;
        }

        for(intt k = 1 ; k < j ; k++){
            intt x = oper(i,k,oper) ;
            intt y = oper(i,j - k,oper) ;

            less = min(less,x+y+1) ;
        }

        return dp[i][j] = less ;
    };

    // iterative approach 
    for(intt i = 1 ; i <= n ; i++){
        for(intt j = 1 ; j <= m ; j++){
            if(i == j) dp[i][j] = 0 ;
            else{
                intt less = INT_MAX ;
                for(intt k = 1 ; k < i ; k++){
                    less = min(less,dp[k][j] + dp[i-k][j] + 1) ;
                }

                for(intt k = 1 ; k < j ; k++){
                    less = min(less,dp[i][k] + dp[i][j - k] + 1) ;
                }

                dp[i][j] = less ;
            }
        }
    }

    // cout << oper(n,m,oper) << nline ;
    cout << dp[n][m] << nline ;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    intt t = 1 ;
    // cin >> t ;
    cout << fixed << setprecision(12); 
    while(t--){
       solution();
    }
    
    return 0;
}