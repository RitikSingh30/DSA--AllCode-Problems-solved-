// Author : RITIK 
# include <bits/stdc++.h>
using namespace std;

#define nline "\n" 
typedef long long ll;

const int N = 2e5 + 10 ;
vector<int> tree[N] ;
int dept[N] ;

void dfs(int i , int parent = -1){
    for(int child : tree[i]){
        if(child == parent) continue ;
        dept[child] = dept[i] + 1 ;
        dfs(child,i) ;
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n - 1 ; i++){
        int a , b ;
        cin >> a >> b ;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1) ;
    int Max_value = -1 , node ;
    for (int i = 1 ; i <= n ; i++)
    {
        if(dept[i] > Max_value){
            Max_value = dept[i] ;
            node = i ;
        }
        dept[i] = 0 ;
    }
    dfs(node) ;
    for (int i = 1 ; i <= n ; i++)
    {
        if(dept[i] > Max_value) Max_value = dept[i] ;
    }
    cout << Max_value << nline ;

    return 0;
}