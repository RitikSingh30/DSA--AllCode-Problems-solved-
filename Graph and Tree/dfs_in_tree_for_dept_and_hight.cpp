#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5+10;

vector<int> tree[N] ;
int height[N] , dept[N] ;

void dfs(int vertex , int parent = 0){
    // cout << vertex << endl ;    --> this line is only for visualize the recursion 
    /* Take action on vertex after entering the vertex */
    for(int child : tree[vertex]){ 
        // cout << "par " << vertex << ' ' << "child " << child << endl ; --> this line is only for visualize the recursion 
        /* Take action on child before entering the child node*/
        if(child==parent) continue ;
        dept[child] = dept[vertex] + 1 ;
        dfs(child,vertex) ;
        /* Take action on child after exiting the child node*/
        height[vertex] = max(height[vertex],height[child]+1) ;
    }
    /* Take action on vertex before exiting the vertex */
}

int main(){
    int n ;
    cin >> n ;
    for(int i = 0 ; i<n-1 ; i++){
        int a , b ;
        cin >> a >> b ;
        tree[a].push_back(b) ;
        tree[b].push_back(a) ;
    }
    dfs(1) ;
    for (int i = 1 ; i <= n ; i++)
    {
        cout << height[i] << " " << dept[i] << endl ;
    }
    

 
    return 0;
}