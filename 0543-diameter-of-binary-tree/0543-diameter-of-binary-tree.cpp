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
    int Diameter=0;
    int Max_Depth(TreeNode* Curr_Node){
        if(!Curr_Node) return 0;

        int Left_Child = Max_Depth(Curr_Node->left);
        int Right_Child = Max_Depth(Curr_Node->right);
        Diameter = max(Diameter,Left_Child+Right_Child);
        return 1 + max(Left_Child,Right_Child);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        Max_Depth(root);
        return Diameter;
    }
};




/*
class Solution {
    int diameter = 0;
    int Max_Height_DFS(TreeNode* Curr_Node){
        if (!Curr_Node)return 0;

        int Left_Height = Max_Height_DFS(Curr_Node->left);
        int Right_Height = Max_Height_DFS(Curr_Node->right);

        diameter = max(diameter , Left_Height + Right_Height);

        return 1 + max(Left_Height, Right_Height); // Take the max height
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        Max_Height_DFS(root);
        return diameter;

    }
};
*/














/*
class Solution {
private:
 int Max_Diameter = 0; 
 int Max_Depth_Diameter(TreeNode* node){
    if(!node)return 0;

    int Left_Depth = Max_Depth_Diameter(node->left);
    int Right_Depth = Max_Depth_Diameter(node->right);

    Max_Diameter = max(Max_Diameter, Left_Depth + Right_Depth);
    return 1 + max(Left_Depth,Right_Depth);
 }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        Max_Depth_Diameter(root);
        return Max_Diameter;
    }
};
*/