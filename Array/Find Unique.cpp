/* agar same number ka XOR karte hai to ans 0 atta hai*/
int findUnique(int *arr, int size)
{
    int ans = 0 ;
    for(int i = 0 ; i<size ; i++){
        ans ^=arr[i] ;
        }
    return ans ;
}