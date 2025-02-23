/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
       vector<vector<int>>Result;
       if(!root) return Result;

       queue<tuple<TreeNode*,int,int>>BFS_Q;
       BFS_Q.push({root,0,0});
       map<int,vector<int>>HashMap;
       while(!BFS_Q.empty()){
        auto [Curr_Node, X_Idx, Y_Idx] = BFS_Q.front();
        HashMap[X_Idx].push_back(Curr_Node->val);
        BFS_Q.pop();
        
        if(Curr_Node->left){
            BFS_Q.push({Curr_Node->left,X_Idx-1,Y_Idx+1});
        }

        if(Curr_Node->right){
            BFS_Q.push({Curr_Node->right,X_Idx+1,Y_Idx+1});
        }

       }

       for( auto& Vec : HashMap){
        Result.push_back(Vec.second);
       }
       return Result;
    }
};





/*
class Solution {
private:
    //Helper Function to return nodes based on X Coordinate
    void VerticalTraverse(TreeNode * root,unordered_map<int,vector<int>> & HashMap, int &min_x, int &max_x){
        if(!root) return;
        queue<pair<int,TreeNode*>>BFS_Q;
        BFS_Q.push({0,root});
        
        while(!BFS_Q.empty()){
            auto [x, CurrNode] = BFS_Q.front();
            BFS_Q.pop();
            HashMap[x].push_back(CurrNode->val);

            min_x = min(min_x,x);
            max_x = max(max_x,x); 
            
            // Traverse left and right children with updated column indices
            if (CurrNode->left) BFS_Q.push({x - 1, CurrNode->left});
            if (CurrNode->right) BFS_Q.push({x + 1, CurrNode->right});
        }
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        // Map to store nodes grouped by their column indices
        unordered_map<int, vector<int>> HashMap;

        // To track the minimum and maximum column indices
        int minCol = 0, maxCol = 0;

        // Perform the vertical traversal and populate HashMap
        VerticalTraverse(root, HashMap, minCol, maxCol);

        vector<vector<int>>Result;
        for (int col = minCol; col <= maxCol; col++) {
            if (HashMap.count(col)) {
                Result.push_back(HashMap[col]);
            }
        }

        return Result;    
    }
};
*/