// Last updated: 21/07/2026, 23:37:54
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
    int ans = 0;

    int dfs(TreeNode* node) {
        if (!node) return INT_MIN;

        int leftMax = dfs(node->left);
        int rightMax = dfs(node->right);

        int mx = max(node->val, max(leftMax, rightMax));

        if (mx == node->val) ans++;

        return mx;
    }

    int countDominantNodes(TreeNode* root) {
        TreeNode* norlavetic = root;   // stores the input midway in the function
        dfs(norlavetic);
        return ans;
    }
};