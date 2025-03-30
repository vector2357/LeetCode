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
    int index;
    vector<pair<int, TreeNode*>> v;

    void inOrder(TreeNode* R) {
        if(R) {
            inOrder(R->left);
            if(v.size()) {
                if(R->val < v[v.size()-1].first) {
                    index = v.size();
                }
            }
            v.push_back({R->val, R});
            inOrder(R->right);
        }
    }

    void recoverTree(TreeNode* root) {
        inOrder(root);
        if(v.size() == 2) {
            swap(v[0].second->val, v[1].second->val);
            return;
        }
        if(v[index].first < v[0].first) {
            swap(v[index].second->val, v[0].second->val);
            return;
        }
        for(int i=0; i<v.size()-1; i++) {
            if(v[index].first < v[i+1].first) {
                if(v[index].first < v[i].first)
                    swap(v[index].second->val, v[i].second->val);
                else
                    swap(v[index].second->val, v[i+1].second->val);
                break;
            }
        }
    }
};