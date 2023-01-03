#include <bits/stdc++.h>
using namespace std ;

int dfs(int node , int parent , vector<int> tree[] , vector<int>& subTree , vector<int>& subAns){
	int below = 0 ;
    int sub = 0 ;
	for(auto &child:tree[node]){
		if(child == parent) continue;
		below += dfs(child,node,tree,subTree,subAns) ;
        sub += subTree[child] ;
	}
 
    subTree[node] = sub + 1 ;
    subAns[node] = below + subTree[node] ;

	return subAns[node] ;   
}

void dfs_(int node , int parent , int n , vector<int> tree[] , vector<int>& subTree , vector<int>& subAns , vector<int>& dp){
    if(parent != -1){
        // dp[node] = subAns[node] + (dp[parent] - subAns[node] - subTree[node]) + n - subTree[node] ;   
        // upar wale equation ko niche simplyfy kar ke likha hai 
        dp[node] = dp[parent] + n - (2 * subTree[node]) ;
    }
	for(auto &child:tree[node]){
		if(child == parent) continue;
		dfs_(child,node,n,tree,subTree,subAns,dp) ;
	}
}

int maxPoints(vector<vector<int>> &edges)
{
	int n = edges.size() ;
    vector<int> tree[n + 2] ;

	for(int i = 0 ; i < n ; i++){
		tree[edges[i][0]].push_back(edges[i][1]) ;
		tree[edges[i][1]].push_back(edges[i][0]) ;
	}

    vector<int> subTree(n + 2) , subAns(n + 2) ;
    dfs(1,-1,tree,subTree,subAns) ;

    vector<int> dp(n + 2 , 0) ;
    dp[1] = subAns[1] ;
    dfs_(1,-1,n + 1,tree,subTree,subAns,dp) ;
    
    int ans = 0 ;
    for(auto &x:dp) ans = max(ans,x) ;

	return ans ;
}

int main(){
    int n ;
    cin >> n ;

    vector<vector<int>> edges ;
    for(int i = 0 ; i < n - 1 ; i++){
        int x , y ;
        cin >> x >> y ;
        edges.push_back({x,y}) ;
    }

    cout << maxPoints(edges) ;
}