int firstOcc(vector<int>& arr , int n , int k){
    int low = 0 , high = n - 1 , ans = -1 ;
    while(low<=high){
        int mid = low + (high-low)/2 ;
        if(arr[mid]==k){
            ans = mid ;
            high = mid - 1 ;
        }
        else if(arr[mid]<k){
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    return ans ;
}
int lastOcc(vector<int>& arr , int n , int k){
    int low = 0 , high = n - 1 , ans = -1 ;
    while(low<=high){
        int mid = low + (high-low)/2 ;
        if(arr[mid]==k){
            ans = mid ;
            low = mid + 1 ;
        }
        else if(arr[mid]<k){
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    return ans ;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int>p ;
    p.first = firstOcc(arr,n,k) ;
    p.second = lastOcc(arr,n,k) ;
    return p ;
}