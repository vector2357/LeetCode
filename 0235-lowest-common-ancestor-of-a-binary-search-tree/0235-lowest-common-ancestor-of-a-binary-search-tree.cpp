/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> v;

    void ancestral(TreeNode* R, int k) {
        if(R && R->val != k) {
            if(k < R->val) {
                ancestral(R->left, k);
                v.push_back(R);
            }
            else {
                ancestral(R->right, k);
                v.push_back(R);
            }
        }
    }

    bool search(TreeNode* R, int k) {
        if(!R) return false;
        if(R->val == k) return true;

        if(k < R->val) {
            return search(R->left, k);
        }
        else {
            return search(R->right, k);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        v.push_back(p);
        ancestral(root, p->val);
        TreeNode* ans;
        
        for(int i=0; i<v.size(); i++) {
            if(search(v[i], q->val)) {
                return v[i];
            }
        }
        return NULL;
    }
};