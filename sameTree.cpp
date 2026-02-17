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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1,q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* currentP = q1.front();
            TreeNode* currentQ = q2.front();
            q1.pop();
            q2.pop();
            if(!currentP && !currentQ) continue;
            if(!currentP || !currentQ) return false;
            if(currentP->val!=currentQ->val){
                return false;
            }
            q1.push(currentP->left);
            q1.push(currentP->right);
            q2.push(currentQ->left);
            q2.push(currentQ->right);
        }

        return true;
    }


};