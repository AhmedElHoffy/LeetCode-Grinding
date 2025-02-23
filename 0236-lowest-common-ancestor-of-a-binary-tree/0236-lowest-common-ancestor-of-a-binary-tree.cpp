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
        // return null ptr if neither p or q are not found  or return Curr_Node if either was found
        //TreeNode* Curr_Node = root;
        if(!root || root==p || root==q){
            return root;
        }
        // DFS on both sides of the tree Left Side and Right side respectively (In a recursive approach)
        TreeNode* LeftChild = lowestCommonAncestor(root->left,p,q);
        TreeNode* RightChild = lowestCommonAncestor(root->right,p,q);

        // If both Traversal returns Nodes; therefore, the Curr_Node is the LCA for p and q
        if(LeftChild && RightChild){
            return root;
        }else if(LeftChild){          
        // Otherwise return the non-null Recursive approach  
        //return the non-null child (either LeftChild or RightChild)
            return LeftChild;
        }else {
            return RightChild;
        }
    }
};



/*

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

       // Base Case
        if (!root || root == p || root == q) {
            return root;
        }

        // Recursive calls for left and right subtrees
        TreeNode* LeftChild = lowestCommonAncestor(root->left, p, q);
        TreeNode* RightChild = lowestCommonAncestor(root->right, p, q);

        // If both left and right return non-null, root is the LCA
        if (LeftChild && RightChild) {
            return root;
        }

        // Otherwise, return the non-null child (either LeftChild or RightChild)
        return LeftChild ? LeftChild : RightChild;
        
    }
};
*/