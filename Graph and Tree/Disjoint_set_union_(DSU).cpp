// Author : RITIK 
# include <bits/stdc++.h>
using namespace std;

#define nline "\n" 
typedef long long ll;

/* time complextiy of this data structure is O(alpha(n))
    alpha(n) ko hum Reverse Ackerman function bhi bola jata hai and ye jo fucntion hai na wo bahot slowly increase hota hai
    and ye O(alpha(n)) ko amoterized time complexity bhi bola jata hai 
    agar ye sab nahi samjha me aaya upar ka to hum itna assume kar sakte hai ki iss function ki time complexity almost constant 
    hoti hai bich me ekhada logn operaion bhi ho sakta hai but overall iski time complexity almost constant hoti hai */

const int N = 1e5 + 10 ;
int parent[N] ; 
int size[N] ;

void make(int v){
    // this will make each node and ye har node ke liye intially usko hi uska parent bana dega
    parent[v] = v ;
    // ye har node ki size 1 set kar dega 
    size[v] = 1 ;
}

int find(int v){
    // agar v == parent[v] hai matlab ye humara root node hai because root node ka hi parent wo khud hota hai
    if(v == parent[v]) return v ;
    // path compression
    return parent[v] = find(parent[v]) ; // and yaha pe hum har node ka parent change kar rhe hai iss group ka jo root node hai 
    // use hi hum v ka parent bana rahe hai to reduce time complextiy
}

void Union(int a , int b){
    a = find(a) ;
    b = find(b) ;
    if(a != b){
        // union by size
        if(size[a] < size[b]) swap(a,b) ; // yaha pe hum jab 2 group ko connect kar rhe hai to size check kar rhe hai jiski size 
        // choti hai usse bade se connect kar rhe hai agar b ki size choti hue to hum a and b ko swap kar rhe hai because hum cahte
        // hai ki humesha humara a hi bada ho and then unko connent kar rhe hai
        parent[b] = a ;
        size[a] += size[b] ; // ab connect karne ke baad hum size bhi increase kar rhe hai a ki because b usme add hue hai to a ki
        // size bhi increase hogi b ke nodes bhi ab a me add honge
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n , k ;
    cin >> n >> k ;
    for(int i = 1 ; i <= n ; i++){
        make(i) ;
    }
    while(k--){
        int u , v ;
        cin >> u >> v ;
        Union(u,v);
    }
    int connected_ct = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if(find(i) == i) connected_ct++ ;
    }
    cout << connected_ct << nline ;

    return 0;
}