// Last updated: 04/05/2026, 15:44:21

// 22/04/26
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // No left child, visit this node and move right
                result.push_back(curr->val);
                curr = curr->right; // Fixed: was curr->result
            } else {
                // Find the rightmost node in the left subtree
                TreeNode* leftChild = curr->left; // Fixed: consistent naming
                while (leftChild->right != NULL) {
                    leftChild = leftChild->right;
                }

                // Connect the rightmost node to the current node
                leftChild->right = curr;
                
                // Move to the left child and break the old link to avoid infinite loops
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL; 
            }
        }
        return result;
    }
};
