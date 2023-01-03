/* BUBBLE SORT 
    Bubble sort me hum 1st element lete hai then usse sare element ke sath compare karte hai agar wo element bada hua apne neighbour se
    to hum swap kar dete hai and agar chota ya equal hua to hum uss element ko wahi pe chod dete hai and usske side wala element lekar
    bache hue elements ke sath compare karte hai to first itteration me jo humara sabse bada element hai wo last place pe chala jata hai
    then hum 2nd itteration pe chale jate hai 2nd itteration pe 2nd jo bada element hai wo last 2nd position pe chala jata hai
    aise karte karte hum array ko sort karte hai and har itteration me andar wale loop ko 1 se decrease karte rehte hai
    because piche se sare element already sorted hote hai 
    Time complexity -> O(n^2)
    Space complexity -> O(1) 
    worst case Time complexity -> O(n^2) 
    best case Time Complexity -> O(n) ye O(n) kaise hai wo niche explain kiya hai
    bubble sort is a stable soting algorith 
    stable - agar array me 2 same element raha and e.g 5 and 5' and 5 ka index 3 hai and 5' ka 6 matlab 5' array me 5 ke baad aata hai
            then array ko sort karne ke baad bhi agar 5' , 5 ke baad hi aayega to wo stable sort hai
    bubble sort is inPlace sorting algorith
    InPlace - agar hum koi array/vector/etc ko sort karne ke liye constant space ya logn space ka use kar rhe hai to wo Inplace sorting
                algorithm hai range-> O(1) <= space <= log(n) */

    #include <iostream>
    using namespace std;
    
    int main(){
        int n ; // size of array
        cin >> n ;
        int arr[n] ;
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i] ;
        }

        for (int i = 1 ; i < n ; i++)
        {
            // for round 1 to n - 1 
            for (int j = 0 ; j < n - i ; j++)
            {
                // processing till n - i index 
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]) ;
                }
            }
            
        }
        
        for (int i = 0; i < n ; i++)
        {
            cout << arr[i] << ' ' ;
        }
        

        return 0;
    }

    /* best case time complexity O(n) hoga agar array already sorted hai
        hum check kar lenge ki 2nd wale for loop me ek baar bhi swap hua hai ya nahi agar nahi hua to array already sorted hai*/ 
    #include <iostream>
    using namespace std;
    
    int main(){
        int n ; // size of array
        cin >> n ;
        int arr[n] ;
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i] ;
        }

        for (int i = 1 ; i < n ; i++)
        {
            bool sort = false ;
            // for round 1 to n - 1 
            for (int j = 0 ; j < n - i ; j++)
            {
                // processing till n - i index 
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]) ;
                    sort = true ;
                }
            }
            if(!sort){
                // already sorted 
                break ;
            }
            
        }
        
        for (int i = 0; i < n ; i++)
        {
            cout << arr[i] << ' ' ;
        }
        

        return 0;
    }