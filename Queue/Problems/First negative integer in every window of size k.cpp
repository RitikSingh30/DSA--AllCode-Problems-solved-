// Time complexity O(N) , Space Complexity O(K) 
vector<long long> printFirstNegativeInteger(long long int a[], long long int N, long long int k) {
        vector<int> ans ;
        queue<int> q ;
        for(int i = 0 ; i < k ; i++){
            q.push(a[i]) ;
        }

        int ind = k - 1 ;
        while(ind < N){
            ind++ ;
            while(!q.empty() and q.front() >= 0) q.pop() ;
            if(q.empty()){
                ans.push_back(0) ;
            }
            else{
                ans.push_back(q.front()) ;
            }

            if(ind < N){
                q.push(a[ind]) ;
            }

            if(q.size() > k) q.pop() ;
        }

        return ans ;
                                                 
 }

// Time complexity O(N) , Space complexity O(1) 
// ye wale quesiton me humne jo space complexity calculate kiya hai usme humne ans wale vector ka space add nahi kiya hai 
 vector<long long> printFirstNegativeInteger(long long int a[], long long int N, long long int k) {
        vector<long long> ans ;
        int firstNegative = -1 ;
        for(int i = 0 ; i < k ; i++){
            if(a[i] < 0){
                firstNegative = i ;
                break ;
            }
        }
        
        bool possible = false ;
        if(firstNegative != -1) possible = true ;

        int ind = k - 1 ;
        while(ind < N){
            ind++ ;
            if(!possible){
                ans.push_back(0) ;
            }
            else ans.push_back(a[firstNegative]) ;

            if(ind < N){
                    while(firstNegative < (ind - k + 1)) firstNegative++ ;
                    while(firstNegative <= ind and a[firstNegative] >= 0) firstNegative++ ;
                    if(firstNegative > ind) possible = false ;
                    else possible = true ;
            }
        }

        return ans ;
                                                 
 }