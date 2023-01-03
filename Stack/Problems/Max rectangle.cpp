int* Smaller(vector<int>& cal , int sz , bool chance){
    stack<int> s ;
    s.push(-1) ;

    int* small = new int[sz];

    if(chance == 0){
        for(int i = 0 ; i < sz ; i++){
            while(!s.empty() and s.top() != -1 and cal[s.top()] >= cal[i]) s.pop() ;
            small[i] = s.top() ;
            s.push(i) ;
        }
    }
    else{
        for(int i = sz - 1 ; i >= 0 ; i--){
            while(!s.empty() and s.top() != -1 and cal[s.top()] >= cal[i]) s.pop() ;
            small[i] = s.top() ;
            s.push(i) ;
        }
    }
    return small ;
}
int maxArea(int M[MAX][MAX], int n, int m) {
    vector<int> cal(m,0) ;
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(M[i][j] == 0) cal[j] = 0 ;
            else cal[j] = cal[j] + M[i][j] ;
        }
        int* temp = Smaller(cal,m,0) ;
        int* temp1 = Smaller(cal,m,1) ;

        for(int j = 0 ; j < m ; j++){
            if(M[i][j] == 0) continue ;
            int left , right ;
            left = temp[j] ;
            if(temp1[j] == -1) right = m ; 
            else right = temp1[j] ;
            left++ ;
            right-- ;
            ans = max(ans,cal[j] * ((j - left) + (right - j) + 1)) ;
        }
    }
    return ans ;
}