class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.size() ;
        int m = s2.size() ;

        if(m < n) return 0 ;
        
        map<char,int> first , second ;

        for (int i = 0 ; i < n ; i++)
        {
            first[s1[i]]++ ;
            second[s2[i]]++ ;
        }


        for (int i = 0 ; (i + n - 1) < m ; i++)
        {
            bool fang = true ;
            if(i != 0){
                second[s2[i - 1]]-- ;
                second[s2[i + n - 1]]++ ;
            }

            for(auto &x:first){
                if(x.second != second[x.first]) fang = false ; 
            }

            if(fang) return 1 ;
        }

        return 0 ;
        
    }
};