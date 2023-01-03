# include <bits/stdc++.h>
using namespace std;

#define nline "\n" 
typedef long long intt;

class segmentTree{
    vector<intt>segTree ;
    public:
        segmentTree(intt n){
            /* segTree ki size around O(4 * N) tak ja sakti hai because n leave node honge and bich me kuch internal node 
                honge jo segment tree ko divide kar rhe hai 
            */
            segTree.resize(4 * n) ;
        }
        /* build function ki time complextiy near O(N) tak hoti hai because humara jo build function hota hai wo segment tree
            me jitne bhi nodes hai unn sabko ke liye 1 se 2 baar chalta hai to total number of nodes jo honge wo almost O(4*N) 
            honge to round figure kar ke O(N)
        */
        void build(intt ind , intt low , intt high , vector<intt>& arr){
            if(low == high){
                segTree[ind] = arr[low] ;
                return ;
            }
            intt mid = (low + high) / 2 ;
            build(2 * ind + 1 , low , mid , arr) ;
            build(2 * ind + 2 , mid + 1 , high , arr) ;
            segTree[ind] = min(segTree[2 * ind + 1] , segTree[2 * ind + 2]) ;
        }

        /* query function ke time complexity O(logN) hoti hai because yaha pe 3 cases hote hai no overlap , partially overlap 
            and compelete overlap 
            no overlap - jab humare low and high l and r me lie nahi karte unka koi bhi part given l and r me lie nahi karta
            complete overlap - jab humare low and high completely given l and r me lie karte hai jaise l <= low <= high <= r 
                                aise case me 
            partially overlap - jab humare low and high given l and r ke range me partially overlap kar hai jase 
                                low <= l <= high <= r  OR l <= low <= r <= high  is type me
            jab no overlap condition occur hoti hai to hum ussi node se int_max return kar dete hai because wo node and uske childrens
            humare kaam ke nahi hai humare range me nahi hai isliye wo humare ans me kabhi contribute nahi kar sakta 
            jab complete overlap ki condition occur hoti hai tab hum wo node ki value return kar dete hai because ye range humare given
            l and r ke bich me hai to iska contribution hume lagega 
            jab partially overlap ki conditon occur hoti hai tab hum 2 recursion call karte hai ek left part ke liye ek right part ke 
            liye because wo partially occur hue hai hume uska pura part humare ans me consider nahi karna 
        */
        intt query(intt ind , intt low , intt high , intt l , intt r){
            // no overlap
            // low high l r or l r low high
            if(high < l || r < low) return INT_MAX ;

            // complete overlap 
            if(low >= l && high <= r) return segTree[ind] ;

            // partially overlap 
            intt mid = (low + high) / 2 ;
            intt left = query(2 * ind + 1 , low , mid , l , r) ;
            intt right = query(2 * ind + 2 , mid + 1 , high , l , r) ;
            return min(left , right) ;
        }

        /* update function ki time compelxity O(logN) hoti hai because hum apne search space ko half half part me divide kar ke 
            apna index search karte hai jaha pe hume value update karni hai 
        */
        void update(intt ind , intt low , intt high , intt i , intt val){
            if(low == high){
                segTree[ind] = val ;
                return ;
            }
            intt mid = (low + high) / 2 ;
            if(i <= mid) update(2 * ind + 1 , low , mid , i , val) ;
            else update(2 * ind + 2 , mid + 1 , high , i , val) ;
            segTree[ind] = min(segTree[2 * ind + 1] , segTree[2 * ind + 2]) ;
        }

};

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    intt n ;
    cin >> n ;
    vector<intt>v(n) ;
    for(auto &x:v) cin >> x ;
    segmentTree seg1(n) ;
    seg1.build(0 , 0 , n - 1 , v) ;
    intt q ;
    cin >> q ;
    while(q--){
        intt que ;
        cin >> que ;
        if(que == 1){
            intt i , val ;
            cin >> i >> val ;
            i-- ;
            seg1.update(0,0,n - 1,i,val) ;
            v[i - 1] = val ;
        }
        else{
            intt l , r ;
            cin >> l >> r ;
            l-- ;
            r-- ;
            cout << seg1.query(0,0,n - 1,l,r) << nline ;
        }
    }
    return 0;
}