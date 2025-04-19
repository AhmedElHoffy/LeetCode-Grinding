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
    int DFS_PathSum_Count(TreeNode* Curr_Node,unordered_map<long long,int>&PrefixSums,int targetSum,long long Curr_Sum){
        if(!Curr_Node)return 0;
        Curr_Sum+=Curr_Node->val;
        int Count = PrefixSums[Curr_Sum - targetSum];
        PrefixSums[Curr_Sum]++;

        Count+=DFS_PathSum_Count(Curr_Node->left,PrefixSums,targetSum,Curr_Sum);
        Count+=DFS_PathSum_Count(Curr_Node->right,PrefixSums,targetSum,Curr_Sum);
        PrefixSums[Curr_Sum]--;
        return Count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int>PrefixSums;
        PrefixSums[0]=1;
        return DFS_PathSum_Count(root,PrefixSums,targetSum,0);
    }
};