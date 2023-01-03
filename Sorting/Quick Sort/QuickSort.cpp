/*
    how to use quick sort 
    1. Take a pivot element (we can take any element as pivot element whether the first element or last element of middle element)
        bas agar differet type se pivot element choose kiya to uska different tarike se partition function likhna padega 
    2. call the partition function 
    3. find the right place for pivot element and place it there by swaping the element present at that place with the pivot element
    4. position of pivot element will be currentIndexOfPivotElement + count 
    5. count all element < pivot
    6. then bring the element which are less than pivot element to lhs of pivot element and all the element which are greater than
        pivot element to rhs  
    7. after returning back from partition function make a recursive call to lhs of pivot element and rhs to pivot element to sort
        that part 

    Time complexity of Quick sort : 
        wost case : O(n^2) it occurs when all the element of the array are sorted in accending order or decending order 
        Best Case: O(nlogn) The best case occurs when the partition process always picks the middle element as the pivot
                 (eg binary search)
        average case : O(nlogn) 

    is quick sort stable ?
        The default implementation is not stable. However any sorting algorithm can be made stable by considering indexes 
        as comparison parameter. 
    
    is quick sort in-place ?
        As per the broad definition of in-place algorithm it qualifies as an in-place sorting algorithm as it uses extra space only 
        for storing recursive function calls but not for manipulating the input

    we can reduce the worst case time complexity of quick sort by using randomized version of quick sort 
    he randomized version has expected time complexity of O(nLogn). The worst case is possible in randomized version also, but worst 
    case doesn’t occur for a particular pattern (like sorted array) and randomized Quick Sort works well in practice.
*/

#include <iostream>
using namespace std ;

int partition(int l , int r , int* arr){

    int cnt = 0 ;

    // finding the element which are smaller than pivot element 
    for(int i = l + 1 ; i <= r ; i++){
        if(arr[i] <= arr[l]) cnt++ ;
    }

    // finding the index where we have to place the pivot element 
    int pivotIndex = l + cnt ;

    swap(arr[l],arr[pivotIndex]) ;

    while(l < pivotIndex && r > pivotIndex){
        while(arr[l] < arr[pivotIndex]) l++ ;
        while(arr[r] > arr[pivotIndex]) r-- ;

        if(l < pivotIndex && r > pivotIndex) swap(arr[l],arr[r]) ;
    }

    return pivotIndex ;
}

void quickSort(int l , int r , int* arr){
    if(l >= r) return ;

    int p = partition(l,r,arr) ;
    quickSort(l,p - 1,arr) ;
    quickSort(p + 1,r,arr) ; 
}

int main(){
    int n ;
    cin >> n; 

    int* arr = new int[n] ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
    quickSort(0,n-1,arr) ;
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << ' ' ;
    }

    delete []arr ;
}
