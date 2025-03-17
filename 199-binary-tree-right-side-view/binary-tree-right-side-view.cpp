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
    void BFS_Traverse(TreeNode* root, vector<vector<int>>&TreeLevelTraverse){
        if(!root) return;
        queue<pair<int,TreeNode*>>BFS_Q;
        BFS_Q.push({0,root});
        while(!BFS_Q.empty()){
            auto [H, node]= BFS_Q.front();
            BFS_Q.pop();
            // Ensure TreeLevelTraverse can store the current level
            if (H == TreeLevelTraverse.size()) {
                TreeLevelTraverse.push_back({});
            }
            TreeLevelTraverse[H].push_back(node->val);
            if(node->left) BFS_Q.push({H+1,node->left});
            if(node->right) BFS_Q.push({H+1,node->right});
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>Tree_Traverse;
        int n = Tree_Traverse.size();
        BFS_Traverse(root,Tree_Traverse);
        vector<int>Result;

        // Extract the last node from each level
        for (const auto& level : Tree_Traverse) {
            Result.push_back(level.back());
        }
        return Result;
    }
};