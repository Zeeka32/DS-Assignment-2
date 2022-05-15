#include <iostream>

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
 
    bool parallel_mirror_traverse (TreeNode *node, TreeNode *mirror)
    {
        if (node != NULL && mirror != NULL){
            if(node->val == mirror->val){

                if(!parallel_mirror_traverse(node->left, mirror->right))
                    return false;

                if(!parallel_mirror_traverse(node->right, mirror->left))
                    return false;

            }else return false;
        }else if(node == NULL && mirror == NULL)
            return true;
        else 
            return false;

        return true;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return parallel_mirror_traverse(root->left, root->right);
    }
};


int main (void)
{
    TreeNode *root = new TreeNode (5);
    TreeNode *lv1_right = new TreeNode (4);
    TreeNode *lv1_left = new TreeNode (4);
    TreeNode *lv2_right1 = new TreeNode (4);
    TreeNode *lv2_left1 = new TreeNode (1);
    TreeNode *lv2_right2 = new TreeNode (3);
    TreeNode *lv2_left2 = new TreeNode (1);

    Solution solver;

    /*
            (5)
              \
             (10)
    */
    cout << "Test 1\n";
    root->right = new TreeNode(10);
    solver.isSymmetric(root)? cout << "Symmetric\n": cout << "Not Symmetric\n";
    delete (root->right);
    root->right = NULL;
    cout << endl;


    /*
            (5)
           /  \
          /    \
        (4)    (4)
    */
    cout << "Test2\n";
    root->right = lv1_right, root->left = lv1_left;
    solver.isSymmetric(root)? cout << "Symmetric\n": cout << "Not Symmetric\n";
    cout << endl;


    /*
            (5)
           /  \
          /    \
        (4)    (4)
        /        \
      (1)        (3)
    */
    cout << "Test3\n";
    lv1_right->right = lv2_right1, lv1_left->left = lv2_left2;
    solver.isSymmetric(root)? cout << "Symmetric\n": cout << "Not Symmetric\n";
    cout << endl;

    /*
            (5)
           /  \
          /    \
        (1)    (1)
        /      / \
      (1)    (1) (3)
    */
    cout << "Test4\n";
    lv1_right->left = lv2_left1;
    solver.isSymmetric(root)? cout << "Symmetric\n": cout << "Not Symmetric\n";
    cout << endl;

    /*
            (5)
           /  \
          /    \
        (1)    (1)
          \    /
          (4)(4) 
    */
    cout << "Test5\n";
    lv1_left->right = lv2_right1;
    root->right->right = root->left->left = NULL;
    root->right->left->val = 4;
    solver.isSymmetric(root)? cout << "Symmetric\n": cout << "Not Symmetric\n";
    cout << endl;

    /*
            (5)
           /  \
          /    \
        (1)    (1)
          \      \
          (4)    (4) 
    */ 
    cout << "Test6\n";
    root->right->right = root->right->left;
    solver.isSymmetric(root)? cout << "Symmetric\n": cout << "Not Symmetric\n";
    cout << endl;

    delete root, lv1_left, lv1_right, lv2_left1, lv2_left2, lv2_right1, lv2_right2;
    root = lv1_left = lv1_right = lv2_left1 = lv2_left2 = lv2_right1 = lv2_right2 = NULL;
    return 0;
}