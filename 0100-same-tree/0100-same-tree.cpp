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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr)return true;
        if(p==nullptr && q!=nullptr)return false;
        if(p!=nullptr && q==nullptr)return false;
        if(p->val!=q->val)return false;
        
//         bool left=isSameTree(p->left,q->left);
//         if(left==false)return false;
        
        
//        bool right=isSameTree(p->right,q->right);
//         if(right==false)return false;
        
//         return true;
        
        
//     }
// };
        
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        
        // Return true only if both subtrees match
        return left && right;
    }
};