// give the array arr which contain n elements and q queries of type l r and x in each query you have to tell how many number in the 
// range l and r are greater than x 

// Author Ritik 
#include <bits/stdc++.h>
using namespace std ;

#define nline '\n' ;

class segmentTree{
    vector<int> segTree ;

    public:
    segmentTree(int n){
        segTree.resize(n * 4) ;
    }

    void update(int ind , int low , int high , int x){
        if(low == high){
            segTree[ind] = 1 ;
            return ;
        }

        int mid = low + (high - low) / 2 ;
        if(x <= mid) update(ind * 2 + 1 , low , mid , x) ;
        else update(ind * 2 + 2 , mid + 1 , high , x) ;

        segTree[ind] = segTree[ind * 2 + 1] + segTree[ind * 2 + 2] ;
    }

    int query(int ind , int low , int high , int l , int r){
        if(high < l || low > r) return 0 ;

        if(low >= l && high <= r) return segTree[ind] ;

        int mid = low + (high - low) / 2 ;
        int left = query(ind * 2 + 1 , low , mid , l , r) ;
        int right = query(ind * 2 + 2 , mid + 1 , high , l , r) ;

        return (left + right) ;
    }
};

bool cmp(vector<int>x , vector<int>y){
    return x[3] < y[3] ;
}

int main(){
    int n , q ;
    cin >> n >> q ;

    priority_queue<pair<int,int>> pq ;
    for (int i = 0 ; i < n ; i++)
    {
        int x ;
        cin >> x ;
        pq.push({x,i}) ;
    }

    vector<vector<int>> query(q) ;
    for (int i = 0 ; i < q ; i++)
    {
        int l , r , x ;
        cin >> l >> r >> x ;

        l-- ;
        r-- ;

        query[i].push_back(x) ;
        query[i].push_back(l) ;
        query[i].push_back(r) ;
        query[i].push_back(i) ;
    }

    sort(query.begin(),query.end(),greater<>()) ;

    segmentTree segTree(n) ;

    for(int i = 0 ; i < q ; i++){
        int num = query[i][0] ;
        while(!pq.empty() && pq.top().first > num){
            segTree.update(0,0,n-1,pq.top().second) ;
            pq.pop() ;
        }
        query[i].push_back(segTree.query(0,0,n-1,query[i][1],query[i][2])) ;
    }

    sort(query.begin(),query.end(),cmp) ;

    for(auto &x:query){
        cout << x[4] << nline ;
    }

    return 0 ;
}