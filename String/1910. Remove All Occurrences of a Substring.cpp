// learning 
    // s.size() and string::npos dono same kaam karta hai find ke case me 

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.size() != 0 && s.find(part) != string::npos){
            s.erase(s.find(part),part.size()) ;
        }
        return s ;
    }
};

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.size() != 0 && s.find(part) < s.size()){
            s.erase(s.find(part),part.size()) ;
        }
        return s ;
    }
};