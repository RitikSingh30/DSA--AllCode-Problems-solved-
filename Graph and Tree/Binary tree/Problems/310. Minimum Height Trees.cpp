class Solution {
public:
    void dfs(int i , vector<int>& dept , vector<int> tree[] , int parent = -1){
        for(auto child : tree[i]){
            if(child == parent) continue;
            if(parent != -1) dept[child] = 1 + dept[i] ;
            else dept[child] = 1 ;
            dfs(child,dept,tree,i) ;
        }
    }

    void dfs_1(int i , vector<int>tree[], vector<int>& ans, vector<int>& store , int max_ind_2 , int parent = -1){
        store.push_back(i) ;
        if(ans.size() == 0 && i == max_ind_2){
            if(store.size() & 1){
                int y = store[store.size()/2] ;
                ans.push_back(y) ;
            }
            else{
                int x = store[store.size()/2 - 1] ;
                int y = store[store.size()/2] ;
                ans.push_back(x) ;
                ans.push_back(y) ;
            }
        }
        for(auto child : tree[i]){
            if(child == parent) continue;
            dfs_1(child,tree,ans,store,max_ind_2,i) ;
            store.pop_back() ;
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> tree[n] ;
        vector<int> dept(n,0) ;
        for(int i = 0 ; i < n - 1 ; i++){
            tree[edges[i][0]].push_back(edges[i][1]) ;
            tree[edges[i][1]].push_back(edges[i][0]) ;
        }
        dfs(0,dept,tree) ;
        int max_dept = -1 , max_ind ;
        for (int i = 0 ; i < n ; i++)
        {
            if(dept[i] > max_dept){
                max_dept = dept[i] ;
                max_ind = i ;
            }
            dept[i] = 0 ;
        }
        dfs(max_ind,dept,tree) ;
        int max_dept_2 = -1 , max_ind_2 ;
        for (int i = 0 ; i < n ; i++)
        {
            if(dept[i] > max_dept_2){
                max_dept_2 = dept[i] ;
                max_ind_2 = i ;
            }
        }
        vector<int> ans ;
        vector<int> store ;
        dfs_1(max_ind,tree,ans,store,max_ind_2) ;
        return ans ;
    }
};  