#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(string s);
TreeNode* buildTreeHelper(string& s, int& i);

TreeNode* buildTree(string s) {
    int i = 0;
    return buildTreeHelper(s, i);
}

TreeNode* buildTreeHelper(string& s, int& i) {
    int num = 0;
    bool negative = false;
    if (s[i] == '-') {
        negative = true;
        i++;
    }
    while (isdigit(s[i])) {
        num = num * 10 + s[i] - '0';
        i++;
    }
    if (negative) num = -num;
    TreeNode* root = new TreeNode(num);
    if (s[i] == '(') {
        i++; // eat '('
        root->left = buildTreeHelper(s, i);
        i++; // eat ','
        root->right = buildTreeHelper(s, i);
        i++; // eat ')'
    }
    return root;
}

void levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return;
    queue<TreeNode*> q{ {root} };
    while (!q.empty()) {
        vector<int> oneLevel;
        for (int i = q.size(); i > 0; i--) {
            TreeNode* t = q.front(); q.pop();
            oneLevel.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        res.push_back(oneLevel);
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string s;
    getline(cin, s);
    TreeNode* root = buildTree(s);
    levelOrderBottom(root);
    return 0;
}

