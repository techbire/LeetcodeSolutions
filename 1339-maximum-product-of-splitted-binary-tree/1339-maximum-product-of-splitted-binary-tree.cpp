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
    long total = 0, ans = 0;
    const int MOD = 1e9+7;

    long dfs(TreeNode* root){
        if(!root) return 0;

        long s = root->val + dfs(root->left) + dfs(root->right);

        ans = max(ans, s * (total - s));   // product of two parts
        return s;
    }

    int maxProduct(TreeNode* root) {
        total = dfs(root);   // 1st pass: get total sum
        ans = 0;             // reset answer
        dfs(root);           // 2nd pass: calculate max product
        return ans % MOD;
    }
};
