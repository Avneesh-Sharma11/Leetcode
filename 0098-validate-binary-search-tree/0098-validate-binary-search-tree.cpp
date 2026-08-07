/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = NULL;
    void solve(TreeNode* root, bool& ans) {
        if (root == NULL)
            return;

        solve(root->left, ans);
        if (prev != NULL && prev->val >= root->val) {
            ans = false;
            return;
        }
        prev = root;
        solve(root->right, ans);
    }
    bool isValidBST(TreeNode* root) {
        bool ans = true;

        solve(root, ans);
        return ans;
    }
};