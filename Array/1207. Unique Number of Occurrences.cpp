/* using map and set , TC = O(n) */
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp ;
        set<int>s ;
        int n = arr.size() ;
        for(int i = 0 ; i<n ;i++){
            mp[arr[i]]++ ;
        }
        for(auto &x:mp){
            s.insert(x.second) ;
        }
        return s.size() == mp.size() ;
    }
};

/* using map and vector , TC = O(nlogn) (due to sort function) */
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp ;
        vector<int>v ;
        int n = arr.size() ;
        for(int i = 0 ; i<n ;i++){
            mp[arr[i]]++ ;
        }
        for(auto &x:mp){
            v.push_back(x.second) ;
        }
        sort(v.begin(),v.end()) ;
        for(int i = 0 ; i<v.size()-1 ; i++){
            if(v[i]==v[i+1]){
                return false ;
            }
        }
        return true ;
    }
};