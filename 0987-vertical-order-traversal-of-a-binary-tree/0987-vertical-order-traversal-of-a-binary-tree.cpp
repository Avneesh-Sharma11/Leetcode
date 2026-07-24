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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> res;
        if(root == NULL)return res;

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].insert(node->val);

            if (node->left)
                q.push(make_pair(node->left, make_pair(hd - 1, lvl + 1)));
            if (node->right)
                q.push(make_pair(node->right, make_pair(hd + 1, lvl + 1)));
        }

        for (auto node : nodes) {
            vector<int> col;
            for (auto p : node.second) {
                col.insert(col.end(), p.second.begin(), p.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};