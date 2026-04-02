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
    int maxSum = INT_MIN;
    int gain(TreeNode* root){
        if(!root) return 0;

        int leftGain = max(gain(root->left),0);
        int rightGain = max(gain(root->right),0);
        int currentSum = root->val + leftGain + rightGain;
        maxSum = max(currentSum,maxSum);

        return root->val + max(leftGain,rightGain);
    }
    int maxPathSum(TreeNode* root) {
        gain(root);
        return maxSum;
    }
};