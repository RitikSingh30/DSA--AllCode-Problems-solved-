# include <bits/stdc++.h>
using namespace std;

#define nline "\n" 
typedef long long intt;

/*
    hume ek graph diya hoga and bola hoga ki ismese minimum spanning tree find karke do 
    spanning tree : jo bhi graph diya hai uske jitne bhi vertices hai wo sab vertices spanning tree me include honge but sare edges include nahi hogi bas n - 1 edges 
        hogi and wo jo hum n - 1 edges lenge wo aisa lena hai jisse humara ek tree structure create ho because hume spanning tree banana hai and wo spanning tree sare
        trees ki condition satisfy hona cahiye jaise usme koi loop nahi hona cahiye sare nodes ek hi connected components me hona cahiye hone cahiye.
    minimum spanning tree : minimum spanning tree ka matlab hota hai ki hume jo graph diya hai usse hume ek spanning tree banana hai but uss tree ke jo edges ka weight
        hai wo minimum hona cahiye. 

    Time complexity of kruskal's Algorithm : O(Nlog(N)) 

    Kruskal's algorithm : kruskal's algorithm me hum pehele sare vertices ko independent assume karte hai and humare pass jitne bhi edges hai usko sorted order me store
        kar lete hai then unn edges me se hum minimum wala edge lete hai and usko humare spanning tree me include karna cahte hai to include karte same bas hume ye
        dhyan rakhna hai ki hum jo edge add kar rhe hai wo add karne se humare tree me koi loop create ho rha hai ya nahi agar loop create ho rha hai to uss edge ko hum
        add nahi karenge and agar loop create nahi ho rha to uss edge ko hum apne tree me include karenge.
        ab edges ko sort hum O(nlog(n)) me kar sakte hai but hum ab ye kaise dekhenge ki ye edge dalne se loop create ho rha hai ya nahi to ye kaam hum DSU ki madat se
        karenge disjoint set union tree me loop tab create hota hai jab hum ek hi tree ke nodes ke bich me edge dalne ki koshish karte hai to hum DSU se check kar 
        lenge ki ye dono node ek tree ka part hai ya nahi agar nahi hai to hum node add karenge but agar hai to hum node add nahi karenge.
*/

const int N = 1e5 + 10 ;
vector<int> parent(N) , size(N) ;

void make(int vertex){
    parent[vertex] = vertex ;
    size[vertex] = 1 ;
}

int find(int vertex){
    if(parent[vertex] == vertex) return vertex ;
    return parent[vertex] = find(parent[vertex]) ;
}

void Union(int a , int b){
    a = find(a) ;
    b = find(b) ;

    if(a != b){
        if(size[a] < size[b]) swap(a,b) ;
        parent[b] = a ;
        size[a] += size[b] ;
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n , m ;
    cin >> n >> m ;

    vector<pair<int,pair<int,int>>> edges ;

    for (int i = 0 ; i < m ; i++)
    {
        int u , v , wt ;
        cin >> u >> v >> wt ;

        edges.push_back({wt,{u,v}}) ;
    }

    sort(edges.begin(),edges.end()) ;

    for(int i = 1 ; i <= n ; i++) make(i) ;

    int sumOfEdges = 0 ;

    for(auto &edge:edges){
        int u = edge.second.first ;
        int v = edge.second.second ;
        int wt = edge.first ;

        if(find(u) == find(v)) continue;
        Union(u,v) ;
        sumOfEdges += wt ;
        cout << u << ' ' << v << nline ;
    }

    cout << sumOfEdges << nline ;

    return 0;
}