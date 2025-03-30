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
class BSTIterator {
public:
    TreeNode* root;
    vector<int> v;
    int n;

    BSTIterator(TreeNode* root) {
        this->root = root;
        n=0;
        inOrder(root);
    }

    void inOrder(TreeNode* R) {
        if(R) {
            inOrder(R->left);
            v.push_back(R->val);
            inOrder(R->right);
        }
    }
    
    int next() {
        int ans = v[n];
        n++;
        return ans;
    }
    
    bool hasNext() {
        return n<v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */