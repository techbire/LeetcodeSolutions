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

// -approach 
// do function banega : 
// 1- function to return the sum of nodes each level;
// 2- final function to find kth largest level and sum



class Solution {
public:
    vector<long long> levelOrderSum(TreeNode* root) {
        vector<long long> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            long long levelSum = 0;
            while (size--) {  //process all nodes
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);    //left and right for child
                if (node->right) q.push(node->right);
                levelSum += node->val;
            }
            ans.push_back(levelSum);   //store the sum of the current level in the result vector
        }
        sort(ans.begin(), ans.end(), greater<long long>());   //sort the level sums in descending order
        return ans;
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans = levelOrderSum(root);
        return (k > 0 && k <= ans.size()) ? ans[k - 1] : -1;
    }
};
