class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size() ;
        int ans = -1 , leftsum = 0 , sum = 0 ;
        int ans = -1 ;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i] ;
        }
        for(int i = 0 ; i < n ; i++){
            if(leftsum == (sum - leftsum - nums[i])) return i ;
            leftsum += nums[i] ;
        }
 
        return ans ;
    }
};

// second approach using prefix sum ans suffix sum 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(nums);
        for(int i=1;i<n;i++)
            prefix[i]+=prefix[i-1];
        
        vector<int>suffix(nums);
        for(int i=n-2;i>=0;i--)
            suffix[i]+=suffix[i+1];
        
        for(int i=0;i<n;i++)
            if(prefix[i]==suffix[i])
                return i;
        
        return -1;
    }
};