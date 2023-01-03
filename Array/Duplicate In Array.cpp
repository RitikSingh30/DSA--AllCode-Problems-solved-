/* using xor */
int findDuplicate(vector<int> &arr) 
{
    int ans = 0 ;
    for(int i = 0 ; i<arr.size() ; i++){
        ans ^=arr[i] ;
    }
    for(int i = 1 ; i<arr.size() ; i++){
        ans ^= i ;
    }
    return ans ;
	
}

/* using sum */
int findDuplicate(vector<int> &arr) 
{
    int ans = 0 , n = arr.size() - 1 ;
    for(int i = 0 ; i<arr.size() ; i++){
        ans +=arr[i] ;
    }
    return ans - (n*(n+1))/2 ;
	
}
