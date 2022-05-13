#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};

void dfs1(TreeNode *x, vector<int> &v) {
    if (x == nullptr) return;
    v.push_back(0);
    dfs1(x->left, v);
    v.push_back(1);
    dfs1(x->right, v);
}

void dfs2(TreeNode *x, vector<int> &s) {
    if (x == nullptr) return;
    s.push_back(0);
    dfs2(x->right, s);
    s.push_back(1);
    dfs2(x->left, s);
}

bool isFoldable(TreeNode *root) {
    vector<int> v, s;
    dfs1(root->left, v);
    dfs2(root->right, s);
    if ((int) v.size() != (int) s.size()) return false;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != s[i])
            return false;
    }
    return true;
}


void freeMemory(TreeNode *node){
    if (node != NULL){
        freeMemory(node->left);
        freeMemory(node->right);
        delete node;
    }
}

int main() {
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    
    isFoldable(root) ? cout << "YES\n" : cout << "NO\n";


    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(6);
    root2->right->right = new TreeNode(5);

    isFoldable(root2) ? cout << "YES\n" : cout << "NO\n";
    

    freeMemory(root);
    freeMemory(root2);

    return 0;
}
