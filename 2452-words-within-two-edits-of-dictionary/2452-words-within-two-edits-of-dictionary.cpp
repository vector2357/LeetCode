class TrieNode {
public:

    TrieNode* child[26];
    bool isLeaf;

    TrieNode() {
        isLeaf = false;
        for (int i=0; i<26; i++) {
            child[i] = nullptr;
        }
    }
};

void insert(TrieNode* root, const string& key) {
    TrieNode* curr = root;

    for (char c : key) {
        if (curr->child[c - 'a'] == nullptr) {
            TrieNode* newNode = new TrieNode();

            curr->child[c - 'a'] = newNode;
        }
        curr = curr->child[c - 'a'];
    }
    curr->isLeaf = true;
}

bool solve(TrieNode* node, string word, int idx, int diff) {
    if (diff > 2) return false;
    if (idx == word.size()) return node->isLeaf;
    if (node->isLeaf) return false;

    char c = word[idx];
    if (node->child[c - 'a'] != nullptr) {
        if (solve(node->child[c - 'a'], word, idx+1, diff)) return true;
    }
    for (int i=0; i<26; i++) {
        if (node->child[i] != nullptr && i != (c - 'a')) {
            if (solve(node->child[i], word, idx+1, diff+1)) return true;   
        }
    }
    return false;
}

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        TrieNode* root = new TrieNode();
        for (string word : dictionary) {
            insert(root, word);
        }

        for (string word : queries) {
            if (solve(root, word, 0, 0)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};