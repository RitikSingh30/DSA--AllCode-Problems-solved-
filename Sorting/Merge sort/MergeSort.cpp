/* Time complexity of mergesort is O(nlogn) O(logn) time mergesort wale function le rha hai jo array ko 2 part me divide kar rha hai
    and O(n) time merge wala function le rha hai wo worst case me n time chalega 
    Auxiliary Space: O(n), In merge sort all elements are copied into an auxiliary array. So N auxiliary space is 
    required for merge sort.

    inplace sorting algorithm means : jo algorithm extra space nahi leta unko hum inplace bolte hai constant extra space allowed hai
    stable sorting algorithm means : A sorting algorithm is said to be stable if two objects with equal keys appear in the same order 
    in sorted output as they appear in the input data set

    application of mergesort : mergesort can be used in external sorting 

    drawback of mergeSort : 
        Slower compared to the other sort algorithms for smaller tasks.
        The merge sort algorithm requires an additional memory space of 0(n) for the temporary array.
        It goes through the whole process even if the array is sorted.
*/

#include <iostream> 
using namespace std ;

void merge(int l , int r , int* arr){
    int mid = (l + r) >> 1 ;

    int firstSize = mid - l + 1 ;
    int secondSize = r - (mid + 1) + 1 ;

    int* arr1 = new int[firstSize];
    int* arr2 = new int[secondSize];

    for(int i = 0 , j = l ; i < firstSize ; i++ , j++){
        arr1[i] = arr[j] ;
    }

    for(int i = 0 , j = mid + 1 ; i < secondSize ; i++ , j++){
        arr2[i] = arr[j] ;
    }

    int start = 0 , start1 = 0 , place = l ; 
    while(start < firstSize && start1 < secondSize){
        arr[place] = min(arr1[start],arr2[start1]) ;
        if(arr1[start] <= arr2[start1]) start++ ;
        else start1++ ;
        place++ ;
    }

    while(start < firstSize){
        arr[place] = arr1[start] ;
        start++ ;
        place++ ;
    }

    while(start1 < secondSize){
        arr[place] = arr2[start1] ;
        start1++ ;
        place++ ;
    }

    delete []arr1 ;
    delete []arr2 ;
}

void mergeSort(int l , int r,int* arr){
    if(l >= r) return ;

    int mid = (l + r) >> 1 ;
    mergeSort(l,mid,arr);
    mergeSort(mid+1,r,arr);

    merge(l,r,arr) ;
}

int main(){
    int n ;
    cin >> n ;

    int* arr = new int[n] ;

    for (int i = 0 ; i < n ; i++)
    {
        cin >> arr[i] ;
    }
    
    mergeSort(0,n - 1,arr) ;

    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << ' ' ;
    }

    delete []arr ;
}