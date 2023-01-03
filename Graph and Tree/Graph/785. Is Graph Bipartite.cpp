class Solution {
public:
    bool dfs(vector<bool>& visited , vector<vector<int>>& graph , int i , vector<int>& color , int c = 1){
        bool fang = true ;
        color[i] = c ;
        visited[i] = 1 ;
        for(auto &child : graph[i]){
            if(visited[child] && color[child] == color[i]) return false ;
            if(visited[child]) continue;
            fang &= dfs(visited,graph,child,color,3 - c) ;
        }
        return fang ;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<bool>visited(n,0) ;
        bool is_bipartite = true ;
        vector<int> color(n) ;
        for (int i = 0 ; i < n ; i++)
        {
            if(visited[i]) continue;
            else{
                is_bipartite &= dfs(visited,graph,i,color) ;
            }
        }
        return is_bipartite ;
    }
};