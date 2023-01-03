#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 ;
vector<int> graph[N] ;
int visited[N] ;

bool dfs(int vertex , int parent){
    visited[vertex] = 1 ;
    // cout << vertex << endl ;
    bool isloopExist = false ;
    for(auto &child:graph[vertex]){
        // cout << child << ' ' << vertex << endl ;
        if(visited[child] && child == parent)
            continue ;
        if(visited[child])
            return true ;
        isloopExist |= dfs(child,vertex) ;
    } 
    return isloopExist ;
}

int main(){
    int node , edge ;
    cin >> node >> edge ;
    for (int i = 0 ; i < edge ; i++)
    {
        int a , b ; 
        cin >> a >> b ;
        graph[a].push_back(b) ;
        graph[b].push_back(a) ;
    }
    bool isloopExist = false ;
    for (int i = 1 ; i <= node ; i++)
    {
        if(visited[i]) 
            continue ;
        if(dfs(i,0)){
            isloopExist = true ;
        }
    }
    cout << isloopExist << endl ;

    return 0;
}