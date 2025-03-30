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
    vector<int> v;

    void inOrder(TreeNode* R) {
        if(R) {
            inOrder(R->left);
            v.push_back(R->val);
            inOrder(R->right);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        bool ans = false;
        inOrder(root);

        for(int i=0, j=v.size()-1; i!=j;) {
            if(v[i]+v[j] == k) {
                ans = true;
                break;
            }
            if(v[i]+v[j] > k) {
                j--;
            }
            else {
                i++;
            }
        }
        return ans;
    }
};