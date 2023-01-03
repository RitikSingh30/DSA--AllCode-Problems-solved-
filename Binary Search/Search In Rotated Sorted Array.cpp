int findPosition(vector<int>& arr, int n, int k)
{
    int low = 0 , high = n - 1 ;
    
    /* suppose humara rotated array hai [5,6,7,8,9,0,1,2,3,4] to jab hum iska mid find karenge to hume hamesha ek 
       side aisa milega jo sorted hoga eg = low = 0 , high = 9 then mid = 4 humara mid 4th index pe hai to 4 ke pehele wale bhi element
       sorted hai aur uske baad wale bhi sorted hai to aisa humesha hume ek mid aisa milega jiske ek side wala array hamesha sorted hoga
       you can try it on pen and paper*/
    while(low<=high){
        int mid = low + (high - low)/2 ;
        if(arr[mid]==k){
            return mid ;
        }
        /* agar humara left wala array sorted hai */
        else if(arr[mid]>=arr[low]){
            /* to hum pehele check karenge ki left me wo element present hai ya nahi agar hai to humara search ussme hoga high ko 
               decrease kar ke*/
            if(k>=arr[low] && k<=arr[mid]){
                high = mid - 1 ;
            }
            /* agar nahi hai to humara search right part pe hoga left wala skip kar denge low ko increment kar ke*/
            else{
                low = mid + 1 ;
            }
        }
        /* agar humara right wala array sorted hai */
        else{
            /* to hum pehele check karenge ki right me wo element present hai ya nahi agar hai to humara search ussme hoga low ko 
               increment kar ke*/
            if(k>=arr[mid] && k<=arr[high]){
                low = mid + 1 ;
            }
            /* agar nahi hai to humara search left part pe hoga right wala skip kar denge high ko decrement kar ke*/
            else{
                high = mid - 1 ;
            }
        }
        
    }
    return -1 ;

}

