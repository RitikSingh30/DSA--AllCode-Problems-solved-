bool check(vector<int>& time , long long mid , int n){
    long long sum = 0 , count = 0 ;
    for (int i = 0 ; i < time.size() ; i++)
    {
        sum += time[i] ;
        if(time[i]>mid)
            return 0 ;
            
        if(sum>mid){
            count++ ;
            sum = time[i] ;
        }
           
    }
    count++ ;
    return count<=n ;
    
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long sum = 0 ;
    for (int i = 0; i < m ; i++)
    {
        sum += time[i] ;
    }
    long long low = 1 , high = sum , ans = 0 ;
    while(low<=high){
        long long mid = low + (high - low)/2 ;
        if(check(time,mid,n)){
            ans = mid ;
            high = mid - 1 ;
        }
        else{
            low = mid + 1 ;
        }
    }
    return ans ;
    
}