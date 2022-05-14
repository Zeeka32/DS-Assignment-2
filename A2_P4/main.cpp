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
    void inverse_post_order_traverse (TreeNode *node, stack <int> &stk)
    {
        if (node != NULL){
            stk.push(node->val);
            inverse_post_order_traverse(node->right, stk);
            inverse_post_order_traverse(node->left, stk);
        }
    }
    void post_order_traverse (TreeNode *node, stack <int> &stk)
    {
        if (node != NULL){
            post_order_traverse(node->left, stk);
            post_order_traverse(node->right, stk);
            stk.push(node->val);
        }
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        stack <int> right;
        stack <int> left;
        inverse_post_order_traverse(root->right, left);
        post_order_traverse(root->left, right);
        while (!right.empty() && !left.empty() && left.top() == right.top() )
            right.pop(), left.pop();
        if (right.empty() && left.empty())
            return true;
        else 
            return false;
    }
};

int main (void)
{
    TreeNode *root = new TreeNode (5);
    TreeNode *lv1_right = new TreeNode (1);
    TreeNode *lv1_left = new TreeNode (1);
    TreeNode *lv2_right1 = new TreeNode (1);
    TreeNode *lv2_left1 = new TreeNode (1);
    TreeNode *lv2_right2 = new TreeNode (1);
    TreeNode *lv2_left2 = new TreeNode (1);

    Solution solver;

    cout << "Test 1\n";
    solver.isSymmetric(root)? cout << "Symmetric\n": cout << "Not Symmetric\n";
    cout << endl;

    cout << "Test2\n";
    root->right = lv1_right, root->left = lv1_left;
    solver.isSymmetric(root)? cout << "Symmetric\n": cout << "Not Symmetric\n";
    cout << endl;

    cout << "Test3\n";
    lv1_right->right = lv2_right1, lv1_left->left = lv2_left2;
    solver.isSymmetric(root)? cout << "Symmetric\n": cout << "Not Symmetric\n";
    cout << endl;

    cout << "Test4\n";
    lv1_right->left = lv2_left1;
    solver.isSymmetric(root)? cout << "Symmetric\n": cout << "Not Symmetric\n";
    cout << endl;


    return 0;
}