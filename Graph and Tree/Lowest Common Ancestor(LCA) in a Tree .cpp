#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10 ;
vector<int> tree[N] ;
int par[N] ;

void dfs(int node , int parent = -1){
    par[node] = parent ;
    for(auto child:tree[node]){
        if(child==parent)
            continue ;
        dfs(child , node) ;
    }
}

vector<int> path(int node){
    vector<int> ans ;
    while(node != -1){
        ans.push_back(node) ;
        node = par[node] ;
    }
    reverse(ans.begin(),ans.end()) ;
    return ans ;
}

int main(){
    int n ;
    cin >> n ;
    for (int i = 0; i < n - 1 ; i++)
    {
        int a , b ;
        cin >> a >> b ;
        tree[a].push_back(b) ;
        tree[b].push_back(a) ;
    }
    dfs(1) ;
    int x , y ;
    cin >> x >> y ;
    vector<int> path_x = path(x) ;
    vector<int> path_y = path(y) ;

    int min_len = min(path_x.size(),path_y.size()) ;
    int LCA = -1 ;
    for (int i = 0; i < min_len ; i++)
    {
        if(path_x[i]==path_y[i]){
            LCA = path_x[i] ;
        }
        else{
            break ;
        }
    }
    cout << LCA ;
    
    
 
    return 0;
}