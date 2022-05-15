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

    /*
             1
            / \
           /   \
          4     2
           \   / 
            5 3   
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    
    isFoldable(root) ? cout << "YES\n" : cout << "NO\n";


    /*
             1
            / \
           /   \
          2     3
         / \     \  
        4   6     5
    */
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(6);
    root2->right->right = new TreeNode(5);

    isFoldable(root2) ? cout << "YES\n" : cout << "NO\n";

    /*
             1
            / \
           /   \
          2     3
         / \   / \  
        4   6 1   5
    */
    TreeNode *root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(6);
    root3->right->right = new TreeNode(5);
    root3->right->left = new TreeNode(5);

    isFoldable(root3) ? cout << "YES\n" : cout << "NO\n";

    /*
             1
            / \
           /   \
          2     3
         / \   / \  
        4   6 1   5
       /           \
      1             4
    */
    TreeNode *root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    root4->left->left = new TreeNode(4);
    root4->left->right = new TreeNode(6);
    root4->right->right = new TreeNode(5);
    root4->right->left = new TreeNode(5);
    root4->right->right->right = new TreeNode(4);
    root4->left->left->left = new TreeNode(1);

    isFoldable(root4) ? cout << "YES\n" : cout << "NO\n";
    

    /*
             1
            / \
           /   \
          2     3
         / \   / \  
        4   6 1   5
       /         /
      1         4   

    */
    TreeNode *root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(3);
    root5->left->left = new TreeNode(4);
    root5->left->right = new TreeNode(6);
    root5->right->right = new TreeNode(5);
    root5->right->left = new TreeNode(5);
    root5->right->right->left = new TreeNode(4);
    root5->left->left->left = new TreeNode(1);

    isFoldable(root5) ? cout << "YES\n" : cout << "NO\n";

    freeMemory(root);
    freeMemory(root2);
    freeMemory(root3);
    freeMemory(root4);
    freeMemory(root5);

    return 0;
}
