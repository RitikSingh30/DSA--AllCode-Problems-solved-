/* Insertion Sort
    insertion sort me hum 0th index pe jo element hai usko already sorted assume karte hai and 1th index se check karna chalu karte hai
    then isme hum jo bhi index lete hai usko left part me jo sorted aaray hai usse check karte hai agar wo element usse chota hai to hum 
    swap karte hai aur agar bada hai to hum break kar dete hai 
    Time Complexity :
    Worst case - O(n^2) agar array decending order me hai wo humara bahar wala loop n - 1 time chalega and andar wala loop bhi n - 1 
                time chalega 
    best case - O(n) agar array already sorted hai to bahar wala loop n-1 time chalega and and andar wala loop har i ke liye sirf ek 
                baar chalega because wo compare karega agar uske left wala element bada hai to break kar dega 
    Insetion sort is a stable soting algorith 
    stable - agar array me 2 same element raha and e.g 5 and 5' and 5 ka index 3 hai and 5' ka 6 matlab 5' array me 5 ke baad aata hai
            then array ko sort karne ke baad bhi agar 5' , 5 ke baad hi aayega to wo stable sort hai
    insertion sort is inPlace sorting algorith
    InPlace - agar hum koi array/vector/etc ko sort karne ke liye constant space ya logn space ka use kar rhe hai to wo Inplace sorting
                algorithm hai range-> O(1) <= space <= log(n)*/
    #include <iostream>
    using namespace std;
    
    int main(){
        int n ;
        cin >> n ;
        int a[n] ;
        for(auto &x:a) cin >> x ;
        for (int i = 1 ; i < n ; i++)
        {
            int temp = a[i] , j ;
            for (j = i - 1 ; j >= 0 ; j--)
            {
                if(temp<a[j])
                    a[j+1] = a[j] ;
                else break ;
            }
            a[j+1] = temp ;
            
        }
        for(auto &x:a) cout << x << ' ' ;
        

        return 0;
    }