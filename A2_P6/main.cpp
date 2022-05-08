#include <iostream>
#include <stack>
#include <cmath>
using namespace std;


struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val('0'), left(nullptr), right(nullptr) {}
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};

double in_order_traverse (TreeNode *node, double &result){
    cout << "result is " << result << endl;
    if (node != NULL){
        double rhs = in_order_traverse(node->right, result);
        double lhs = in_order_traverse(node->left, result);
        if (rhs != 'n' && lhs != 'n'){
            if (node->val == '^')
                result = pow(lhs, rhs);
            else if (node->val == '*')
                result = lhs * rhs;
            else if (node->val == '/')
                result = lhs / rhs;
            else if (node->val == '+')
                result = lhs + rhs;
            else if (node->val == '-')
                result = lhs - rhs;
            cout << "calculated " << result  << " by rhs " << rhs << " and lhs " << lhs << " and operator " << node->val << endl;
        }else{
            return node->val - '0';
        }
        return result;
    }
    return 'n';
}


TreeNode *insert (TreeNode *root,const string &exp, int &i)
{
    if (root == NULL){//insert
        while (exp[i] == ' ')
            i++;
        root = new TreeNode(exp[i++]);
    }
    if (i != exp.length()){
        if (isdigit(root->val))
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
    stack<double> stk; double result = 0;
    in_order_traverse(root, result);
    return result;
}





/*
the problem is not over yet since this program only works for 1 digit
numbers please complete it im tired tracing qwq
*/


int main(void){
    cout << "Test 1\n";
    string exp = "+3*4/8 2";
    cout << exp << "\n";
    cout << "result is " << Expression_Tree(exp);
    return 0;
}