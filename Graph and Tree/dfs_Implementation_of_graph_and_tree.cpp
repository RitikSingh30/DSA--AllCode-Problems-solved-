#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<int> g[N] ;
bool vis[N] ;

void dfs(int vertex){
    // cout << vertex << endl ;    --> this line is only for visualize the recursion 
    /* Take action on vertex after entering the vertex */
    vis[vertex] = 1 ;
    for(int child : g[vertex]){ 
        // cout << "par " << vertex << ' ' << "child " << child << endl ; --> this line is only for visualize the recursion 
        /* Take action on child before entering the child node*/
        if(vis[child]) continue ;
        dfs(child) ;
        /* Take action on child after exiting the child node*/
    }
    /* Take action on vertex before exiting the vertex */
}
/* time complexity of this recusive code 
    O(v+e) hoti hai na v = number of vertex and e = number of edges 
    v = jitne vertex hai utne ke liye recusive funtion call ho rha hai 
    e = jitne edes hai utne time for loop chal rha hai */
int main(){
    int n , m ;
    cin >> n >> m ;
    for(int i = 0 ; i<m ; i++){
        int a , b ;
        cin >> a >> b ;
        g[a].push_back(b) ;
        g[b].push_back(a) ;
    }
    dfs(1) ;

 
    return 0;
}