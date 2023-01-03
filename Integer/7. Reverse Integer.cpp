class Solution {
public:
    int reverse(int x) {
        string s = to_string(x) ;
        int n ;
        if(s[0]=='-'){
            n = s.size() - 2 ;
        }
        else{
            n = s.size() - 1 ;
        }
        int ans = 0 ;
        while(x!=0){
            int rem = x%10 ;
            if(ans<=INT_MIN || ans>=INT_MAX){
                return 0 ;
            }
            ans += (rem*pow(10,n)) ;
            x /= 10 ;
            n-- ;
        }
        return ans ;
    }
};