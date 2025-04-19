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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* Curr_Node = root;
        if(!Curr_Node || Curr_Node->val==val) return Curr_Node;
        if(val < Curr_Node->val){
            return searchBST(Curr_Node->left,val);
        }else{
            return searchBST(Curr_Node->right,val);
        }
    }
};