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
int curr = 0;
int res = -1;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return res;
    }

    void dfs(TreeNode* root, int k){
        if(!root) return;
        if(res != -1) return;

        dfs(root->left,k);
        curr++;
        if(curr == k) res = root->val;
        dfs(root->right,k);
    }
};
