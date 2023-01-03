class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans ;
        
        int n = matrix.size() ;
        int m = matrix[0].size() ;

        int outerLoop = n / 2 + (n % 2 != 0) ;
        int firstLoop = m - 1 , firstLoopStart = 0 ;
        int rigthLoopStart = 1 , rightLoop = n - 1 ;
        int downLoop = m - 2 , downLoopStart = 0 ;
        int leftLoopStart = n - 2 , leftLoop = 1 ;
        int cnt = 0 ;

        for (int i = 0 ; i < outerLoop && cnt < (n * m) ; i++)
        {
            for (int j = firstLoopStart ; j <= firstLoop ; j++)
            {
                ans.push_back(matrix[i][j]) ;
                cnt++ ;
            }

            if(cnt >= (n * m)) break ;

            for (int j =  rigthLoopStart ; j <= rightLoop ; j++)
            {
                ans.push_back(matrix[j][firstLoop]) ;
                cnt++ ;
            }

            if(cnt >= (n * m)) break ;

            for (int j = downLoop ; j >= downLoopStart ; j--)
            {
                ans.push_back(matrix[rightLoop][j]) ;
                cnt++ ;
            }

            if(cnt >= (n * m)) break ;

            for (int j = leftLoopStart ; j >= leftLoop ; j--)
            {
                ans.push_back(matrix[j][downLoopStart]) ;
                cnt++ ;
            }
            
            firstLoopStart++ ;
            firstLoop-- ;
            rigthLoopStart++ ;
            rightLoop-- ;
            downLoop-- ;
            downLoopStart++ ;
            leftLoopStart-- ;
            leftLoop++ ;
        }
        return ans ;
    }

};