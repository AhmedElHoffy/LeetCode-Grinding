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
        if(!Curr_Node) return nullptr;
        if(Curr_Node->val==val) return Curr_Node;
         TreeNode* LeftChild  = searchBST(Curr_Node->left,val);
         if(LeftChild) return LeftChild;
         TreeNode* RightChild = searchBST(Curr_Node->right,val);
         return RightChild;
    }
};