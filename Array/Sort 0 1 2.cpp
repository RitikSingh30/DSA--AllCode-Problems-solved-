void sort012(int *arr, int n)
{
    int start = 0 , i = 0 , end = n - 1 ;
    while(i<=end){
        if(arr[i]==0){
            swap(arr[start],arr[i]) ;
            i++ ;
            start++ ;
        }
        else if(arr[i]==2){
            swap(arr[end],arr[i]) ;
            end-- ;
        }
        else{
            i++ ;
        }
    }
}