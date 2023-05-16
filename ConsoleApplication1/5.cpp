#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(string s) {
    if (s.empty()) {
        return NULL;
    }
    stringstream ss(s);
    string item;
    getline(ss, item, '(');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if (!getline(ss, item, ',')) {
            break;
        }
        if (item != "#") {
            TreeNode* left = new TreeNode(stoi(item));
            cur->left = left;
            q.push(left);
        }
        if (!getline(ss, item, ',')) {
            break;
        }
        if (item != "#") {
            TreeNode* right = new TreeNode(stoi(item));
            cur->right = right;
            q.push(right);
        }
    }
    return root;
}

void printTree(TreeNode* root) {
    if (!root) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* cur = q.front();
            q.pop();
            cout << cur->val << " ";
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        cout << endl;
    }
}

int main() {
    string s;
    cin >> s;
    TreeNode* root = buildTree(s);
    printTree(root);
    return 0;
}