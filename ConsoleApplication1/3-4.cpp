#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeHelper(unordered_map<char, int>& inorder_map, string& inorder, string& postorder, int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end) return nullptr;
    char root_val = postorder[post_end];
    TreeNode* root = new TreeNode(root_val);
    int root_pos = inorder_map[root_val];
    int left_size = root_pos - in_start;
    root->left = buildTreeHelper(inorder_map, inorder, postorder, in_start, root_pos - 1, post_start, post_start + left_size - 1);
    root->right = buildTreeHelper(inorder_map, inorder, postorder, root_pos + 1, in_end, post_start + left_size, post_end - 1);
    return root;
}

TreeNode* buildTree(string& inorder, string& postorder) {
    unordered_map<char, int> inorder_map;
    for (int i = 0; i < inorder.size(); ++i) {
        inorder_map[inorder[i]] = i;
    }
    return buildTreeHelper(inorder_map, inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val;
    preorder(root->left);
    preorder(root->right);
}

int main() {
    string inorder, postorder;
    cin >> inorder >> postorder;
    TreeNode* root = buildTree(inorder, postorder);
    preorder(root);
    return 0;
}

