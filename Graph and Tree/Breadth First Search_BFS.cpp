#include <bits/stdc++.h>
using namespace std;


/* bfs ka main use hum waha kar sakte hai jaha pe hume bola hai ki sortest path find karo ye ek use hai bfs ka
   NOTE -> and usse sotest path find karne ke liye ek condition hai ki edges ka weight 0 hona chaiye ya phir sab edges ka same 
           weight hona cahiye
           */
const int N = 1e5 + 10 ;
vector<int> tree[N] ;
int visit[N] ;
int level[N] ;

void bfs(int source){
    queue<int>q ;
    q.push(source);
    visit[source] = 1 ;
    while(!q.empty()){
        int cur_s = q.front() ;
        q.pop() ;
        for(int child:tree[cur_s]){
            if(!visit[child]){
                q.push(child) ;
                visit[child] = 1 ;
                level[child] = level[cur_s] + 1 ;
            }
        }
    }
}

/* V = node , E = edge 
    TC -> O(V+E) 
    iski time complexity V + E isliye hai because bahar wala while loop jitne bhi vertex hai unn sab ke liye ek baar chalega 
    and andar wala for loop sare edges ke liye ek baar chalega
    */
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
    bfs(1) ;
    for (int i = 1 ; i <= n ; i++)
    {
        cout << level[i] << ' ' ;
    }
    
    
    
    return 0;
}