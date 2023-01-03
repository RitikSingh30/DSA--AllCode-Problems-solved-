// Author : RITIK 
# include <bits/stdc++.h>
using namespace std;

#define nline "\n" 
typedef long long ll;

/* dijkstra algorithm weighted graph pe lagta hai . to find the sortest path dijkstra algorithm is used */

/* dijkstra algorithm bolta hai ki tumhe jis source se chalu karna hai wo source mujhe de do and uska distance intially 0 kar do and jo 
remaining vertices hai uska distance infinity kar do and source ko set me insert kar do then set me se minimum distance wala element nikalo
and agar uske childrem ka distance tum uske through minimize kar sakte ho to usse minimize karo and usse set me store kar lo and agar nahi
kar sakte to usse chod do and usse vertices ko visit mark kardo ki dobara uske liye check na ho and jo bhi element set se bahar niklega
wo apna sabse minimum distance lekar niklega uska distance usse aur chota nahi ho sakta 
 */

/* Dijkstra can work in both the graph directed as well as undirected graph */

const int N = 1e3 + 10 ;
const int INF = 1e9 + 10 ;

vector<pair<int,int>> graph[N] ;

/* Time complexity of this dijkstra algorithm is O(V + Elog(V)) 
    v = number of verices , E = number of edges 
    jo bhar wala while loop hai wo total V times chalega because jitne number of vertices hai utni baar hi chalega iska ye prof hai ki har 
    ek while loop ke iteration me ek vertex erase ho rha hai and wo visited mark ho rha hai wo total while loop V times chalega and jo andar
    ka for loop hai wo sare edges ke liye chalega and log(n) time isliye increase hua because for loop me hum set me value bhi inset kar rhe 
    hai jisko log(n) time lagta hai
*/

int dijkstra(int source){
    vector<bool> vis(N,0) ; // visited vector
    vector<int>dist(N,INF) ; // distance vector to store distance of all vertices 
    set<pair<int,int>>s ;   // set humara vertices ko store karega and hum har baar min wt wala vertices bahar nikalenge
    dist[source] = 0 ;        // marking sources distance as 0 
    s.insert({0,source}) ;    // inserting the distance in set 
    while(!s.empty()){
        auto node = *s.begin() ;
        int distance = node.first ;
        int v = node.second ;
        s.erase(s.begin()) ;
        if(vis[v]) continue;
        vis[v] = 1 ;
        for(auto child : graph[v]){
            int wt = child.second ;
            if(dist[v] + wt < dist[child.first]){
                dist[child.first] = dist[v] + wt ;
                s.insert({dist[child.first],child.first}) ;
            }
        }
    }    
    return dist[2] ;           
}

int main(){
    int n , m ;
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int x , y , wt ;
        cin >> x >> y >> wt ;
        graph[x].push_back({y,wt}) ;
    }
    cout << dijkstra(1) ; 
    return 0;
}