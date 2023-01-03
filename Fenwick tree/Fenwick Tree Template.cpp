#include<bits/stdc++.h>
using namespace std ;

#define intt long long int

class fenwickTree{
    vector<intt> fenTree ;
    public:
        fenwickTree(intt n){
            fenTree.resize(n + 2) ;
            for(auto &x:fenTree) x = 0 ;
        }

        // for updating the array 
        void update(intt n , intt ind , intt data , vector<intt>& v){
            int prev = v[ind - 1] ;
            while(ind <= n){
                if(fenTree[ind] == 0) fenTree[ind] += data ;
                else{
                    fenTree[ind] -= prev ;
                    fenTree[ind] += data ;
                }
                ind = ind + (ind & (-ind)) ;
            }
        }

        // updating the element when all the elements in fewick tree is 0
        void freUpdate(intt n , intt ind , intt data){
            while(ind <= n){
                fenTree[ind] += data ;
                ind = ind + (ind & (-ind)) ;
            }
        }

        // for answering query 
        intt query(intt ind){
            int s = 0 ;
            while(ind > 0){
                s += fenTree[ind] ;
                ind = ind - (ind & (-ind)) ;
            }

            return s ;
        }

        // for removing the sum of a particular range
        intt rangeSum(intt l , intt r){
            return query(r) - query(l - 1) ;
        }
};

int main(){
    intt n ;
    cin >> n ;

    vector<intt> v(n) ;
    for(auto &x:v) cin >> x ;

    fenwickTree fen(n) ;
    for(int i = 1 ; i <= n ; i++){
        fen.freUpdate(n,i,v[i - 1]) ;
    }

    intt q ;
    cin >> q ;
    while(q--){
        intt que , l , r ;
        cin >> que >> l >> r ;

        if(que == 1){
            fen.update(n,l,r,v) ;
        }
        else{
            cout << fen.rangeSum(l,r) << endl ;
        }
    }
    return 0 ;
}

