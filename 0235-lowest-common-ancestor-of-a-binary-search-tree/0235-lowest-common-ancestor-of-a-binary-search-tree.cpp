/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* Curr_Node = root;

        while(Curr_Node){
            if( p->val > Curr_Node->val && q->val > Curr_Node->val){
                Curr_Node = Curr_Node->right;
            }else if(p->val < Curr_Node->val && q->val < Curr_Node->val){
                Curr_Node = Curr_Node->left;
            }else {
                // If Splits in p and q paths occurs or we actually fidns any of them
                return Curr_Node;
            }
        }
        return nullptr;
    }
};






/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr=root;
        while(curr){
            
            // If both p and q are greater than curr ; go right
            if(p->val > curr->val  &&  q->val > curr->val){
                curr=curr->right;
            }else if(p->val < curr->val  &&  q->val < curr->val){
                curr = curr->left;
            }else{
                return curr;
            }
        }
        return nullptr;
    }
};
*/