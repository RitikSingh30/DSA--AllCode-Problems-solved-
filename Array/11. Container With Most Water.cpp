class Solution {
public:
    int maxArea(vector<int>& height) {
        long long int n = height.size() , ans = 0 ;
        long long int low = 0 , high = n - 1 ;
        while(low<high){
            ans = max(ans,min(height[low],height[high])*(high-low)) ;
            if(height[low]<height[high]){
                low++ ;
            }
            else{
                high-- ;
            }
        }
        return ans ;
    }
};