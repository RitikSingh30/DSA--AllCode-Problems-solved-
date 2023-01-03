#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10 ;
vector<int> tree[N] ;
int dept[N] ;

void dfs(int vertex,int parent = -1 ){
    for(auto child : tree[vertex]){
        if(child == parent)
            continue ;
        dept[child] = dept[vertex] + 1 ;
        dfs(child,vertex) ; 
    }
}

int main(){
    int n ;
    cin >> n ;
    for (int i = 0 ; i < n - 1 ; i++)
    {
        int a , b ;
        cin >> a >> b ; 
        tree[a].push_back(b) ;
        tree[b].push_back(a) ;
    }
    dfs(1) ;
    int max_dept = -1 ;
    int max_node ;

    for (int i = 1 ; i <= n ; i++)
    {
        if(max_dept < dept[i]){
            max_dept = dept[i] ;
            max_node = i ;
        }
        dept[i] = 0 ;
    }

    dfs(max_node) ;
    max_dept = -1 ;
   
    for (int i = 1 ; i <= n ; i++)
    {
        if(max_dept < dept[i]){
            max_dept = dept[i] ;
        }
    }
    cout << max_dept ;
    
    return 0;
}