#include <iostream>
#include <stack>

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

class Solution {
public:
    void pre_order_traverse (TreeNode *node, string &dfs)
    {
        if (node != NULL){
            dfs.push_back(node->val);
            pre_order_traverse(node->left, dfs);
            pre_order_traverse(node->right, dfs);
        }
    }

    bool isSameTree(TreeNode *p, TreeNode *q){
        string dfs1, dfs2;
        pre_order_traverse(p, dfs1);
        pre_order_traverse(q, dfs2);

        if(dfs1 == dfs2)
            return true;

        return false;
    }
    
};

int main (void)
{
    Solution solver;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left = new TreeNode(3);

    TreeNode *root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->left = new TreeNode(3);

    if(solver.isSameTree(root, root2))
        cout << "the trees are equal\n";
    else 
        cout << "trees are not equal\n";
        
    return 0;
}