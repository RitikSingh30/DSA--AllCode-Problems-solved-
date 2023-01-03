const int M = 1e9 + 7 ;
void dfs(int node , int parent , vector<int>& sub_sum,vector<int> tree[],vector<int>& sum){
    sub_sum[node] += sum[node-1] ;
    for(auto &child:tree[node]){
        if(child==parent)
            continue ;
        dfs(child,node,sub_sum,tree,sum) ;
        sub_sum[node] += sub_sum[child] ;
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    vector<int> tree[A.size()+1] ;
    vector<int> sub_sum(A.size()+1,0) ;
    for (auto &edge:B)
    {
        tree[edge[0]].push_back(edge[1]) ;
        tree[edge[1]].push_back(edge[0]) ;
    }
    dfs(1,0,sub_sum,tree,A) ;

    long long ans = 0 ;
    for (int i = 2 ; i <= A.size() ; i++)
    {
        long long sum1 = sub_sum[i] ;
        long long sum2 = sub_sum[1] - sum1 ;
        ans = max(ans,(sum1*sum2)%M) ;
    }
    return ans ;
}
    