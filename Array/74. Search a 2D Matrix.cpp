class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size() ;
        int m = matrix[0].size() ;

        int low = 0 , high = n * m - 1 ;

        while(low <= high){

            int mid = low + (high - low) / 2 ;

            int element = matrix[mid / m][mid % m] ;

            if(element == target) return 1 ;

            if(element < target) low = mid + 1 ;
            else high = mid - 1 ;
        }      

        return 0 ;
    }
};