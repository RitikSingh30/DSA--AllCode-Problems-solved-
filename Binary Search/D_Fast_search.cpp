// Author : RITIK 
# include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626
#define fo(i, n) for(ll i=0;i<n;i++)
#define pb push_back
#define pf push_front
#define eif else if 
#define fl float
#define dl double long
#define F first
#define S second
#define nline "\n" 
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define vpl vector<pair<ll,ll>>
#define alla(a,n) a, a + n
#define all(v) v.begin(), v.end()
#define mod 1000000007
#define lcm(a,b) (a*b)/__gcd(a,b)
#define gl(s) getline(cin,s);
typedef vector<vi> vvi; 
typedef pair<int,int> pii;
typedef vector<pii> vpii; 

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

#ifndef RITIK_SINGH
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

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
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
struct custom_hash {size_t operator()(uint64_t x) const {
static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
return x + FIXED_RANDOM;}};
ll binaryExponential(ll a , ll b){
ll ans = 1 ; while(b){ if(b&1){ ans = (ans%mod * a%mod)%mod ; } a = (a%mod*a%mod)%mod ; b>>=1 ; }
return ans ;}
void seive() { vector<ll> prime(10000007, 1); prime[0] = prime[1] = 0; for (int i = 2; i * i <= 10000007; i++)
{ if (prime[i]) { for (int j = i * i; j <= 10000007; j += i) prime[j] = 0; } }  }
bool isprime(int n) { if (n < 2) return false;
for (int i = 2; i * i <= n; i++){if (n % i == 0){return false;}}return true;}
ll g , x , y ;
// time complexity = O(log(max(a,b)))
void extendedEuclid(ll a , ll b){if(b==0){g = a ;x = 1 ;y = 0 ;}else{extendedEuclid(b,a%b) ;ll temp = x ;
x = y ;y = temp - (a/b) * y ;}}
//Time complexity O(sqrt(n)log(n))
ll ETF(ll n){ll ans=n;for(ll i=2 ; i<=sqrt(n) ; i++){if(n%i==0){ ans = (ans/i)*(i-1) ;}while(n%i==0) n/=i;}
if(n>1){ ans=(ans/n)*(n-1) ;}return ans ;}
//Time complexity O(sqrt(n))
ll factors(ll n){ll count = 0 ;for (int i = 1 ; i*i <= n ; i++){if(n%i==0){count++ ;if(n/i!=i){count++ ;}}}return count ;}
double myPow(double x, int n) {if(n==0) return 1.00000 ;if(n<0){
return (n%2==0)? 1.00000/myPow(x*x,abs(n/2)) : 1.000/(x*myPow(x* x,abs(n/2))) ;}else{return (n%2==0) ? myPow(x*x,n/2) : x*myPow(x*x,n/2) ;}}
bool isUnique(vector<ll> &v){sort(all(v)) ;fo(i,v.size()){ if(v[i]==v[i+1]) return false; }return true;}
/*-------------------------------------------------TEMPLATE END----------------------------------------------------------------------------*/

void solution(){
    ll n ;
    cin >> n ;
    vll v(n) ;
    for(auto &x:v) cin >> x ;
    ll q ;
    cin >> q ;
    vll ans ;
    sort(all(v)) ;
    while(q--){
        ll a , b ;
        cin >> a >> b ;
        ll i = 0 , j = 0 , low = 0 , high = n - 1 ;
        while(low<=high){
            ll mid = low + (high - low)/2 ;
            if(v[mid]>=a && v[mid]<=b){
                i = mid ;
                high = mid - 1 ;
            }
            eif(v[mid]>b){
                high = mid - 1 ;
            }
            else{
                low = mid + 1 ;
            }
        }
        low = 0 , high = n -1 ;
        while(low<=high){
            ll mid = low + (high - low)/2 ;
            if(v[mid]<=b && v[mid]>=a){
                j = mid + 1 ;
                low = mid + 1 ;
            }
            eif(v[mid]<a){
                low = mid + 1 ;
            }
            else{
                high = mid - 1 ;
            }
        }
        ans.pb(j - i) ;
        
    }
    for(auto &x:ans) cout << x << ' ' ;

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
    solution();
    return 0;
}