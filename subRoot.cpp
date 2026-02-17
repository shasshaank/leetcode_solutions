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

    bool isSameTree(TreeNode* p, TreeNode* q){
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* currentRoot = q1.front();
            TreeNode* subRoot = q2.front();
            q1.pop();
            q2.pop();
            if(!currentRoot && !subRoot) continue;
            if(!currentRoot || !subRoot) return false;
            if(currentRoot->val != subRoot->val){
                return false;
            }
            if(currentRoot->val == subRoot->val){
                q1.push(currentRoot->left);
                q1.push(currentRoot->right);
                q2.push(subRoot->left);
                q2.push(subRoot->right);
            }
        }

        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        
        if(isSameTree(root,subRoot)) return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }

};