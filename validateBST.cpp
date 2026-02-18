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
    bool isValidBST(TreeNode* root) {
        return validate(root,LONG_MIN,LONG_MAX);
    }

    bool validate(TreeNode* curr, long low, long high){
        if(!curr) return true;

        if(curr->val<=low || curr->val>=high){
            return false;
        }

        return validate(curr->left, low,curr->val) && validate(curr->right,curr->val,high);
    }
};