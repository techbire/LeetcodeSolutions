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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1, ans = 1, best = INT_MIN;

        while(!q.empty()){
            int sz = q.size(), sum = 0;

            while(sz--){
                TreeNode* n = q.front(); 
                q.pop();
                sum += n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }

            if(sum > best){
                best = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};
