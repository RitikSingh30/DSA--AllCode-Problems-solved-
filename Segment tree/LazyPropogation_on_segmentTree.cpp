// lazyPropogation hum tab use karte hai jab hum bola hai ki l to r ke values ko update kar do waha pe hum normal segmentTree use nahi
// kar sakte 

// 1. update the node when you visit it 
// 2. ones you update propogate the update downwards 

// Rules of LazyPropogation 
// Traverse in segmentTree , update the previous remaining updates 
// 1. check if the node is completely overlaps with (L - R) then update the node propogate down and return 
// 2. check is the node partially overlap then go to left and right and then do node = left + right      

#include <bits/stdc++.h>
using namespace std ;

class segmentTreeLazyPro{
    vector<int> segTree , lazy ;

    public:
        segmentTreeLazyPro(int n){
            segTree.resize(4 * n) ;
            lazy.resize(4 * n) ;
        }
    
        void build(int ind , int low , int high , vector<int>& arr){
            if(low == high){
                segTree[ind] = arr[low] ;
                return ;
            }

            int mid = (low + high) >> 1 ;

            build(ind * 2 + 1, low , mid , arr) ;
            build(ind * 2 + 2, mid + 1 , high , arr) ;

            segTree[ind] = segTree[ind * 2 + 1] + segTree[ind * 2 + 2] ;
        }

        void update(int ind , int low , int high , int l , int r , int val){

            // update the previous remaining updates and propogate it downward
            if(lazy[ind] != 0){
                segTree[ind] += ((high - low + 1) * lazy[ind]);

                // propogate the lazy updates downwards 
                // for remaining nodes to get updates 
                if(low != high){
                    lazy[ind * 2 + 1] += lazy[ind] ;
                    lazy[ind * 2 + 2] += lazy[ind] ;
                }

                lazy[ind] = 0 ;
            }

            // no overlap 
            // we don't do anything and return 
            // low high l r or l r low high
            if(high < l or low > r){
                return ;
            }

            // complete overlap
            // l low high r 

            if(low >= l and high <= r){
                segTree[ind] += ((high - low + 1) * val) ;

                // if a leaf node it will have children 
                if(low != high){
                    lazy[ind * 2 + 1] += val ;
                    lazy[ind * 2 + 2] += val ;
                }
                return ;
            }
            
            // last case have to be partially overlap 
            int mid = (low + high) >> 1 ;
            update(ind * 2 + 1, low , mid , l , r , val);
            update(ind * 2 + 2 , mid + 1 , high , l , r ,val) ;

            segTree[ind] = segTree[ind * 2 + 1] + segTree[ind * 2 + 2] ;
        }

        int query(int ind , int low , int high , int l , int r){
            // update if any updates are remaining 
            // as the node will stay fresh and updated 
            if(lazy[ind] != 0){
                segTree[ind] += ((high - low + 1) * lazy[ind]);

                // propogate the lazy updates downwards 
                // for remaining nodes to get updates 
                if(low != high){
                    lazy[ind * 2 + 1] += lazy[ind] ;
                    lazy[ind * 2 + 2] += lazy[ind] ;
                }

                lazy[ind] = 0 ;
            }

            // no overlap return 0 
            if(high < l or low > r){
                return 0 ;
            }

            // complete overlap 
            if(low >= l && high <= r){
                return segTree[ind] ;
            }

            int mid = (low + high) >> 1 ;

            int left = query(ind * 2 + 1, low , mid , l , r) ;
            int right = query(ind * 2 + 2 , mid + 1 , high , l , r);
            return (left + right) ;
        }
};

int main(){
    int n ;
    cin >> n ;

    vector<int> arr(n) ;
    for(auto &x:arr) cin >> x ;

    segmentTreeLazyPro segTreeLzy(n) ;
    segTreeLzy.build(0,0,n - 1,arr) ;

    int q ;
    cin >> q ;

    while(q--){
        int queType ;
        cin >> queType ;
        
        if(queType == 1){
            int l , r ;
            cin >> l >> r ;
            l-- ;
            r-- ;
            cout << segTreeLzy.query(0,0,n-1,l,r) << '\n' ;
        }
        else{
            int l , r , val ;
            cin >> l >> r >> val ;
            l-- ;
            r-- ;
            segTreeLzy.update(0,0,n-1,l,r,val) ;
        }
    }
    return 0 ;
}