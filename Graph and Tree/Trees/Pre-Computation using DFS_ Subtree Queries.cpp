#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10 ;
vector<int> tree[N] ;
// int sub_tree_Sum[N] , even_No[N] ;
vector<int> sub_tree_Sum(N) , even_No(N) ;

void dfs(int vertex){
    sub_tree_Sum[vertex] += vertex ;
    if(vertex%2==0)
        even_No[vertex]++ ;

    for(auto child:tree[vertex]){
        dfs(child) ;
        sub_tree_Sum[vertex] += sub_tree_Sum[child] ;
        even_No[vertex] += even_No[child] ;
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
    }
    dfs(1) ;
    for (int i = 1 ; i <= n ; i++)
    {
        cout << sub_tree_Sum[i] << ' ' << even_No[i] << endl ;
    }
    // int q ;
    // cin >> q ;
    // while(q--){
    //     int v ;
    //     cin >> v ;
    //     sub_tree_Sum.resize(N) ;
    //     even_No.resize(N) ;
    //     dfs(v) ;
    //     cout << sub_tree_Sum[v] << ' ' << even_No[v] << endl ;
    //     sub_tree_Sum.clear() ;
    //     even_No.clear() ;
    //     cout << sub_tree_Sum.size() << endl ;
    // }
    return 0;
}
/*
91 6
40 4
37 2
34 2
38 3
6 1
7 0
20 2
9 0
21 1
11 0
12 1
13 0
*/