vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>>v ;
    for(int i = 0 ; i<arr.size() ; i++){
       for(int j = i+1 ; j<arr.size() ; j++){
           if(arr[i]+arr[j]==s){
         	   vector<int>vv ;
               vv.push_back(min(arr[i],arr[j])) ;
               vv.push_back(max(arr[i],arr[j])) ;
               v.push_back(vv) ;
           }
       } 
    }
    sort(v.begin(),v.end()) ;
    return v ;
}