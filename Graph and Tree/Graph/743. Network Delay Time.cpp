class Solution {
public:
    const int N = 1e3 + 10 ;
    const int INF = 1e9 + 10 ;
    int dijkstra(vector<pair<int,int>> graph[] , int n , int k){
        int INF = 1e8 ;
        vector<bool> vis(n + 1,0) ;
        set<pair<int,int>>st ;
        vector<int> dist(n + 1,INF) ;
        dist[k] = 0 ;
        st.insert({0,k}) ;
        while(!st.empty()){
            auto node = *st.begin() ;
            int v = node.second , distance = node.first ;
            st.erase(st.begin()) ;
            if(vis[v]) continue;
            vis[v] = 1 ;
            for(auto child : graph[v]){
                int wt = child.second ;
                if(dist[v] + wt < dist[child.first]){
                    dist[child.first] = dist[v] + wt ;
                    st.insert({dist[child.first],child.first}) ;
                }
            }
        }
        int max_dis = 0 ;
        for(int i = 1 ; i <= n ; i++){
            if(dist[i] == INF) return -1 ;
            max_dis = max(max_dis,dist[i]) ;
        }
        return max_dis ;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> graph[n + 1] ;
        for(auto vec : times){
            graph[vec[0]].push_back({vec[1],vec[2]}) ;
        }
        return dijkstra(graph,n,k) ;
    }
};