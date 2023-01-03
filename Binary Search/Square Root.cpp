/*
    Time Complexity: O(log(N))
    Space Complexity: O(1)

    Where 'N' is the given number.
*/

/* without decimal */
int sqrtN(long long int N)
{
    long long int low = 1 , high = min((long long int)1e8,N) ;
    int ans = 0 ;
    while(low<=high){
        long long int mid = low + (high - low)/2 ;
        if(mid*mid<=N){
            ans = mid ;
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }

    }
    return ans ;
    
}

/* with decimal */
void solution(){
    int n ;
    cin >> n ;
    double low = 1 , high = n , ans = 0 ;
    for (int i = 0 ; i < 100 ; i++)
    {
        double mid = low + (high - low)/2 ;
        if(mid*mid<=n){
            ans = mid ;
            low = mid ;
        }
        else{
            high = mid ;
        }
    }
    cout << fixed << setprecision(7) ;
    cout << ans ;
    

}
