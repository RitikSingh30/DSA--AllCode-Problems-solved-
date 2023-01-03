// This is the solution of leetcode problem 
// if sorting is required then we have to also make use of level
// Time complexity O(nlogn) , space complexity O(n)  
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans ;
        map<int,vector<pair<int,int>>> mp ; // vertical , val , level 
        queue<pair<TreeNode*,pair<int,int>>> binaryTree ; // node , vertical , level ;

        // vertical index of root node will be 0 and it's left child will be -1 and right child will be 1
        binaryTree.push({root,{0,0}}) ;

        while(!binaryTree.empty()){
            auto node = binaryTree.front() ;
            binaryTree.pop() ;
            mp[node.second.first].push_back({node.first->val,node.second.second}) ;
            if(node.first->left) binaryTree.push({node.first->left,{node.second.first - 1,node.second.second + 1}}) ;
            if(node.first->right) binaryTree.push({node.first->right,{node.second.first + 1,node.second.second + 1}}) ;

        }

        for(auto &x:mp){
            vector<int> temp ;
            // sorting the array according to problem statement 
            sort(x.second.begin(),x.second.end(),[&](pair<int,int>x , pair<int,int>y){
                if(x.second == y.second) return x.first < y.first ;
                return x.second < y.second ;
            });
            for(auto &y:x.second) temp.push_back(y.first) ;
            ans.push_back(temp) ;
        }
        return ans ;
    }
};
