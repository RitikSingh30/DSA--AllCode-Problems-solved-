class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size() ;
        long long low = 0 , high = n - 1 ;
        vector<pair<int,int>> v ;
        vector<int>vv ;
        for (int i = 0; i < n ; i++)
        {
            v.push_back({nums[i],i}) ;
        }
        
        sort(v.begin(),v.end()) ;
        while(low<high){
            if((v[low].first+v[high].first)==target){
                vv.push_back(v[low].second) ;
                vv.push_back(v[high].second) ;
                return vv ;
            }
            if((v[low].first+v[high].first)<target)
                low++ ;
            else 
                high-- ;
        }
        return vv ;   
    }
};