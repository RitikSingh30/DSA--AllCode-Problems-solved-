/* what -> different round 
   smallest element laake usko right jagah pe place kar dena hai 
   The selection sort algorithm sorts an array by repeatedly finding 
   the minimum element (considering ascending order) from unsorted part and putting it at the beginning*/

   /* When to use selection sort ?
      -> jab humare array/vector/list ki size small ho and memory kaam use karna ho tab use kar sakte hai
         TC -> Best case O(n^2)
               worst case O(n^2)  
         insertion sort is a stable sorting algorith 
          stable - agar array me 2 same element raha and e.g 5 and 5' and 5 ka index 3 hai and 5' ka 6 matlab 5' array me 5 ke baad aata hai
            then array ko sort karne ke baad bhi agar 5' , 5 ke baad hi aayega to wo stable sort hai
    selection sort is inPlace sorting algorith
    InPlace - agar hum koi array/vector/etc ko sort karne ke liye constant space ya logn space ka use kar rhe hai to wo Inplace sorting
                algorithm hai range-> O(1) <= space <= log(n)*/

   void selectionSort(vector<int>& arr, int n)
{   
    for (int i = 0 ; i < n - 1 ; i++)
    {
       int min_index = i ;
       for (int j = i + 1 ; j < n ; j++)
       {
          if(arr[j] < arr[min_index])
            min_index = j ;
       }
       swap(arr[i],arr[min_index]) ;
       
    }
    
}