#include <bits/stdc++.h>
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int>v ;
  	int i = 0 , j = 0 ;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            i++ ;
        }
        else if(arr1[i]>arr2[j]){
            j++ ;
        }
        else{
            v.push_back(arr1[i]) ;
            i++ ; j++ ;
        }
    }
  
    if(v.size()==0){
        v.push_back(-1) ;
        return v ;
    }
    return v ;
        
      
}