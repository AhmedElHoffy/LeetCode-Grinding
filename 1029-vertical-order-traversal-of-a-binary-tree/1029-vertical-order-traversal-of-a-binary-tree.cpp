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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>Result;
        if(!root) return Result;

        map<int, map<int, multiset<int>>> nodes; // {col -> {row -> values}}
        
        queue<tuple<TreeNode*,int,int>>BFS_Q;
        
        BFS_Q.push({root,0,0});
        
        while(!BFS_Q.empty()){
            auto [Curr_Node, Row, Col] = BFS_Q.front();
            BFS_Q.pop();

            nodes[Col][Row].insert(Curr_Node->val); // Insert into ordered map

            if (Curr_Node->left) {
                BFS_Q.push({Curr_Node->left, Row + 1, Col - 1});
            }
            
            if (Curr_Node->right) {
                BFS_Q.push({Curr_Node->right, Row + 1, Col + 1});
            }

        }

        for (auto& [Col, Row_Map] : nodes) {  // Process each column in sorted order
            vector<int> Col_Values;  // Stores values for the current column

            for (auto& [Row, Values] : Row_Map) {  // Process each row in sorted order
                Col_Values.insert(Col_Values.end(), Values.begin(), Values.end());
            }

            Result.push_back(Col_Values);  // Add this column's values to the final output
        }
        return Result;
    }
};