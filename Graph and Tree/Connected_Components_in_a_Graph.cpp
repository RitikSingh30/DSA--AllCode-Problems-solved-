#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10 ;
bool vis[N] ;
vector<int> graph[N] ;
vector<vector<int>>cc ;
vector<int>c ;

void dfs(int node){
    vis[node] = 1 ;
    c.push_back(node) ;
    for(auto &child:graph[node]){
        if(vis[child])
            continue ;
        dfs(child) ;
    }
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
    int count = 0 ;
    for (int i = 1 ; i <= node ; i++)
    {
        if(vis[i])
            continue ;
        c.clear() ;
        dfs(i) ;
        count++ ;
        cc.push_back(c) ;
    }
    /* how many connected component are there and which of them are there*/
    cout << count << endl ;
    for(auto &x:cc){
        for(auto &y:x){
            cout << y << ' ' ;
        }
        cout << endl ;
    }

    return 0;
}