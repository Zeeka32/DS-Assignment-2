#include <iostream>
#include <stack>
#include <cmath>
using namespace std;


struct TreeNode {
    string val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val("0"), left(nullptr), right(nullptr) {}
    TreeNode(string x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(string x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};

double in_order_traverse (TreeNode *node, double &result){
    if (node != NULL){
        double rhs = in_order_traverse(node->right, result);
        double lhs = in_order_traverse(node->left, result);
        if (node->left != NULL && node->right != NULL){
            if (node->val == "^")
                result = pow(lhs, rhs);
            else if (node->val == "*")
                result = lhs * rhs;
            else if (node->val == "/")
                result = lhs / rhs;
            else if (node->val == "+")
                result = lhs + rhs;
            else if (node->val == "-")
                result = lhs - rhs;
        }else{
            return stoi(node->val);
        }
        return result;
    }
    return 0.0;
}


TreeNode *insert (TreeNode *root,const string &exp, int &i)//"+3*4/8 2"
{
    if (root == NULL){//insert
        while (exp[i] == ' ')
            i++;
        string node;
        while (isdigit(exp[i]))
            node.push_back(exp[i++]);
        if (node.size() == 0)
            node.push_back(exp[i++]);

        root = new TreeNode(node);
    }
    if (i < exp.length()){
        if (isdigit(root->val[0]))
            return root;

        root->left = insert(root->left, exp, i);
        root->right = insert(root->right, exp, i);
        
    }
    return root;
}

double Expression_Tree(string exp){
    TreeNode *root = NULL; int i = 0;
    root = insert (root, exp, i);
    //Evaluate expression.
    double result = 0;
    in_order_traverse(root, result);
    return result;
}


int main(void){
    cout << "Test 1\n";
    string exp = "+3*  40  /8 2";
    cout << exp << "\n"; 
    cout << "result is " << Expression_Tree(exp) << '\n' << '\n';

    cout << "Test 2\n";
    exp = "/+ 1 2 - 3 4";
    cout << exp << "\n";
    cout << "result is " << Expression_Tree(exp) << '\n' << '\n';
    return 0;
}