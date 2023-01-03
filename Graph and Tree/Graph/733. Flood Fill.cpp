class Solution {
public:
        void Fill(vector<vector<int>>& image, int sr, int sc, int newColor , int initialColor) {
        int row = image.size() ;
        int col = image[0].size() ;
        if(sr<0 || sc<0 || sr>=row || sc>=col){
            return ;
        }
        if(image[sr][sc]!=initialColor) 
            return ;
        image[sr][sc] = newColor ;
        int ro[4] = {1,-1,0,0} ;
        int co[4] = {0,0,1,-1} ;
        for (int i = 0 ; i < 4 ; i++)
        {
            Fill(image,sr+ro[i],sc+co[i],newColor,initialColor) ;
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialColor = image[sr][sc] ;
        if(initialColor!=newColor)
            Fill(image,sr,sc,newColor,initialColor) ;
        return image ;

    }
};