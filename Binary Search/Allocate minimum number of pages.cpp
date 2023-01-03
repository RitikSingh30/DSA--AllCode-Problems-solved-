# include <bits/stdc++.h>
using namespace std;

#define nline "\n" 
typedef long long intt;

class Solution 
{
    bool check(int a[] , int n , int M , long long int m){
        long long int ans = 0 , count = 0 , sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(a[i] > m) return false ;
            count += a[i] ;
            if(count > m){
                ans++ ;
                count = a[i] ;
            }
        }
        ans++ ;
        return (ans <= M) ;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        long long int l = 1 , r = 1e13 ;
        long long int ans = -1 ;
        while(l <= r){
            long long int m = l + (r - l) / 2 ;
            if(check(A,N,M,m)){
                ans = m ;
                r = m - 1 ;
            }
            else l = m + 1 ;
        }
        return ans ;
    }
};


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    intt n ;
    cin >> n ;
    int a[n] ;
    for(auto &x:a) cin >> x ;
    int m ;
    cin >> m ;
    Solution sol ;
    cout << sol.findPages(a,n,m) << nline ;

    return 0;
}