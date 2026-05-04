// Last updated: 04/05/2026, 15:43:17
// 25/04/26
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
    TreeNode* ans = NULL;

    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return 0;

        
        int left = dfs(root->left, p, q);
        int right = dfs(root->right, p, q);

        int self = (root == p || root == q) ? 1 : 0;

        int total = left + right + self;

        if (total >= 2 && ans == NULL) {
            ans = root;
        }

        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};