// Finding diameter of a tree using O(N^2) time complexity
# include <bits/stdc++.h>
using namespace std;

#define nline "\n" 
typedef long long ll;

const int N = 2e5 + 10 ;
vector<int> tree[N] ;
vector<int>coOrdi(N) ;
bool visited[N] ;

void dfs(int i){
    visited[i] = 1 ;
    for(auto child : tree[i]){
        if(visited[child]) continue ;
        coOrdi[child] = coOrdi[i] + 1 ;
        dfs(child) ;
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n ;
    cin >> n ;
    for (int i = 1 ; i < n ; i++)
    {
        int a , b ;
        cin >> a >> b ;
        tree[a].push_back(b) ;
        tree[b].push_back(a) ;
    }

    int Max = -1 ;
    for(int i = 1 ; i <= n ; i++){
        dfs(i) ;
        for (int j = 1 ; j <= n  ; j++)
        {
            Max = max(Max,coOrdi[j]) ;
            coOrdi[j] = 0 ;
            visited[j] = 0 ;
        }
        cout << nline ;
    }
    cout << Max << nline ;
    

    return 0;
}