string FirstNonRepeating(string A){
    vector<bool> arr(26,0) ;
    int n = A.size() ;
    queue<char> q ;
    string ans ;
    for(int i = 0 ; i < n ; i++){
    	if(arr[A[i] - 'a'] == 0){
    		q.push(A[i]) ;
    		ans.push_back(q.front()) ;
    		arr[A[i]] = 1 ;
    	}
    	else{
    		queue<char> temp ;
    		while(!q.empty()){
    			if(q.front() == A[i]){
    				q.pop() ;
    				continue ;
    			}
    			temp.push(q.front()) ;
    			q.pop() ;
    		}
    		q = temp ;
    		if(q.empty()) ans.push_back('#') ;
    		else ans.push_back(q.front()) ;
    	}
    }
    return ans ;
}