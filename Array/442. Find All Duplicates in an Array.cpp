// 1st approach
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> mp ;
        vector<int>v ;
        for(int i = 0 ; i<nums.size() ; i++){
            mp[nums[i]]++ ;
        }
        for(auto &x:mp){
            if(x.second==2){
                v.push_back(x.first) ;
            }
        }
        return v ;
    }
};

// second approach
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> mp ;
        vector<int>v ;
        for(int i = 0 ; i<nums.size() ; i++){
            if(mp.find(nums[i])!=mp.end()){
                v.push_back(nums[i]) ;
            }
            else{
                mp[nums[i]] = i ;
            }
        }
        return v ;
    }
};