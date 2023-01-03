class Solution{
    public:
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
       map<int,int>mp ;
       vector<int>v ;
       for (int i = 0 ; i < N ; i++)
       {
           mp[A1[i]]++ ;
       }
       for (int i = 0 ; i < M ; i++)
       {
           if(mp.find(A2[i])!=mp.end()){
               int count = mp[A2[i]] ;
               while(count--){
                   v.push_back(A2[i]) ;
               }
           }
           mp.erase(A2[i]) ;
       }
       for(auto &x:mp){
           int count = x.second ;
           while(count--){
               v.push_back(x.first) ;
           }
       }
       return v ;
       
    } 
};