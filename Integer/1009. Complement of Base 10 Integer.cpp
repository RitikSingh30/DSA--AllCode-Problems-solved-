/* ye wala solution bits ke sath nikala hai bina vector ka use kiye
   and intresting solution hai iska */
class Solution {
public:
    /*humko 5 diya hai iska binary hota hai 101 and iska 1 ka 0 karna hai and 0 ka 1 then print karna hai
      to agar humne aise complement kiya to banega 010 = 2 yahi ans hai 
      to humne 5 ka not liye ~5 = 1111.......010 ab last me hume 10 to mil gaya but staring me 11.... bhi mila hai 
      to ab usse 0 karna hai to humne count kar liya binary me 5 ke kaunse place tk 1 aata hai to 3rd place tk aata hai 
      to humne ek 0 liya and uska last 3 place 1 kar diya OR lekar | then usse n ke sath and kar diya to hume humara ans mil gaya */
    int bitwiseComplement(int n) {
        int mask = n , count = 0 ;
        if(n==0){
            return 1 ;
        }
        n = ~n ;
        while(mask!=0){
            mask>>=1 ;
            count++ ;
        }
        int zero = 0 ;
        while(count--){
            zero = (zero<<1)|1 ;
        }
        int ans = n & zero ;
        return ans ;
    }
};

/* ye bhi solution right hai but ye easy type me hai humne issme vector ka use kar ke solve kiya hai */
class Solution {
public:
    int bitwiseComplement(int n) {
        vector<int>v ;
         if(n==0){
        return 1 ;
        }
        while(n!=0){
            int rem = n%2 ;
            v.push_back(rem) ;
            n /= 2 ;
        }
        // debug(v)
        int a = v.size() ;
        for (int i = 0; i < a ; i++)
        {
            if(v[i]==0)
                v[i] = 1 ;
            else{
                v[i] = 0 ;
            }
        }
        // debug(v)
        int ans = 0 , j = 0 ;
        for (int i = 0 ; i < a ; i++)
        {
            if(v[i]==1){
                ans += pow(2,j) ;
            }
            j++ ;
        }
        return ans ;
        
        
    }
};