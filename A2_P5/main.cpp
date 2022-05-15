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

    bool isSameTree(TreeNode *p, TreeNode *q){

        if(p != NULL && q != NULL){
            if(p->val == q->val){

                if(!isSameTree(p->left, q->left))
                    return false;

                if(!isSameTree(p->right, q->right))
                    return false;

            }else return false;

        }else if(p == NULL && q == NULL)
            return true;
        else 
            return false;

        return true;
    }
    
};

void freeMemory(TreeNode *node) {
    if (node != NULL){
        freeMemory(node->left);
        freeMemory(node->right);
        delete node;
    }
}

void solve(TreeNode *root, TreeNode *root2) {

    Solution solver;
    if(solver.isSameTree(root, root2))
        cout << "Entered trees are the same\n\n";
    else 
        cout << "Entered trees are not the same\n\n";
    
    //freeing the allocated memory.
    freeMemory(root);
    freeMemory(root2);

}

//main function to prepare the test cases
int main (void) {

    //test case 1
    //constructing the following trees and comparing
    /* Tree Representation
    |       1           1
    |      / \   with  / \
    |     2   3       2   3
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    
    solve(root, root2);


    //test case 2
    //constructing the following trees and comparing
    /* Tree Representation
    |     1          1
    |    / \          \
    |   2   3  with    2
    |                   \
    |                    3
    */

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root2 = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);

    solve(root, root2);

    //test case 3
    //constructing the following trees and comparing
    /*
    |     1            1
    |    /     with     \
    |   2                2
    |
    */
    root = new TreeNode(1);
    root->left = new TreeNode(2);

    root2 = new TreeNode(1);
    root2->right = new TreeNode(2);

    solve(root, root2);

    //test case 4
    //constructing the following trees and comparing
    /*
    |     1            1
    |    / \   with   / \
    |   2   1        1   2
    */
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);

    root2 = new TreeNode(1);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(2);

    solve(root, root2);

    //test case 5
    //constructing the following trees and comparing
    /*
    |           1           1
    |          / \         / \
    |         3  10       3  10
    |        / \         / \
    |       3   5       3   5
    */
    root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(10);
    
    root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(5);
    root2->right = new TreeNode(10);

    solve(root, root2);

    return 0;
}