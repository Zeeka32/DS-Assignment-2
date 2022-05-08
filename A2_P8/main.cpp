#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};

void post_order_traverse (TreeNode *node)
{
    if (node != NULL){
        post_order_traverse(node->left);
        post_order_traverse(node->right);
        cout << node->val;
    }
}

void printPostOrder(string preOrder, string inOrder){
    


    post_order_traverse(root);
}

int main (void)
{

    return 0;
}