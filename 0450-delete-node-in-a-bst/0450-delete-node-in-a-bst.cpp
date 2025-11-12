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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* Curr_Node = root;
        if(!Curr_Node) return nullptr;

        if (key < Curr_Node->val) {
            Curr_Node->left = deleteNode(Curr_Node->left, key);
        } else if (key > root->val) {
            Curr_Node->right = deleteNode(Curr_Node->right, key);
        }else{

            // Found Node
            if (!Curr_Node->left) return Curr_Node->right;
            if (!Curr_Node->right) return Curr_Node->left;

            // Case 3:  Two children → find inorder successor
            TreeNode* Min_Node = findMin(Curr_Node->right);
            Curr_Node->val = Min_Node->val;
            Curr_Node->right = deleteNode(Curr_Node->right,Min_Node->val);
        }
        return Curr_Node;
    }

    TreeNode* findMin(TreeNode* node){
        while(node->left){
            node = node->left;
        }
        return node;
    }

};


/*
TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Found the node to delete
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Case 3: Two children → find inorder successor
            TreeNode* minNode = findMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }

        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }
*/