class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n) ;
       
        int zero = -1 , neg_pos = -1 ;

        dp[0] = nums[0] ;
        for(int i = 1 ; i < n ; i++){
            if(dp[i - 1] != 0){
                dp[i] = dp[i - 1] * nums[i] ;
            }
            else dp[i] = nums[i] ;
        }

        int ans = -1e9 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                zero = i ;
                neg_pos = -1 ;
            }
            else if(neg_pos == -1 and nums[i] < 0) neg_pos = i ;

            if(dp[i] < 0){
                int x ;
                if(neg_pos != i) x = abs(dp[i]) / abs(dp[neg_pos]) ;
                else x = dp[i] ;
                ans = max(ans,x) ;
            }
            else ans = max(ans,dp[i]) ;
        }

        return ans ;
    }
};