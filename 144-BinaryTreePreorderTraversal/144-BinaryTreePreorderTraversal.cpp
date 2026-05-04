// Last updated: 04/05/2026, 15:44:00
// 22/04/26
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // Case 1: No left child, visit Root and move Right
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find the inorder predecessor (rightmost node in left subtree)
                TreeNode* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    // Case 2: Create a temporary thread
                    // In Preorder, we visit the node BEFORE going left
                    result.push_back(curr->val); 
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // Case 3: Thread already exists, so we've finished the left side
                    prev->right = nullptr; // Cut the thread
                    curr = curr->right;    // Move Right
                }
            }
        }
        return result;
    }
};
