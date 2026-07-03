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
    int maxSum = INT_MIN;
    int sum(TreeNode* root) {
        if (root == NULL) return 0;

        // maxSum = max(root->val,maxSum);

        int left = sum(root->left);
        int right = sum(root->right);
        if(left < 0)left = 0;
        if(right < 0)right = 0;

        int s = root->val + left + right;

        maxSum = max(maxSum, s);

        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        sum(root);
        return maxSum;
    }
};