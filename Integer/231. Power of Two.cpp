class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans = 1 ;
        for(int i = 0 ; i<=30 ; i++){
            if(ans == n){
                return true ;
            }
            if(ans<INT_MAX/2)
            ans = ans * 2 ;
        }
        return false ;
    }
};


// second approach 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans = 1 ;
        for(int i = 1 ; i<=30 ; i++){
            if(ans == n){
                return true ;
            }
            ans = ans << 1 ;
        }
        if(ans == n){
            return true ;
        }
        return false ;
    }
   
};

//third approach
 public boolean isPowerOfTwo(int n) {
        return (n>0) && ((n&(n-1))==0);
    }
}