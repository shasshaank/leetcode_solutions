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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count= 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        while(!q.empty()){
            auto [current, maxValue] = q.front();
            q.pop();
            if(current->val>=maxValue){
                count++;
            }

            int nextMax = max(maxValue,current->val);
            if(current->left){
                q.push({current->left,nextMax});
            }

            if(current->right){
                q.push({current->right,nextMax});
            }
        }

        return count;
    }
};