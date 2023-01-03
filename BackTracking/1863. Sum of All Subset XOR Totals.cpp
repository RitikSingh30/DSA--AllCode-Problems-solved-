//using recursion 
class Solution {
public:
    void subset(vector<int>& nums , int size , vector<int>& v , vector<int>& a , int pos){
        if(pos==size){
            int b = 0 ;
            for(int i = 0 ; i<a.size() ; i++){
                b ^= a[i] ;
            }
            v.push_back(b) ;
            return ;
        }
        a.pb(nums[pos]);
        subset(nums,size,v,a,pos+1) ; // take the element 
        a.pop_back() ;
        subset(nums,size,v,a,pos+1) ; // don't take the element
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> v , a ;
        subset(nums,nums.size(),v,a,0) ;
        int sum = 0 ;
        for(int i = 0 ; i<v.size() ; i++){
            sum += v[i] ;
        }
        
        return sum ;
    }
};