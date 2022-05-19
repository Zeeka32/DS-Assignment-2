#include <iostream>
#include <stack>
#include <cmath>
#include <iomanip>
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

double post_order_traverse (TreeNode *node, double &result){
    if (node != NULL){
        double rhs = post_order_traverse(node->right, result);
        double lhs = post_order_traverse(node->left, result);
        if (node->left != NULL && node->right != NULL){
            if (node->val == "^")
                result = pow(lhs, rhs);// -+ ^3  11  /4  18 * 5  200
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


TreeNode *insert (TreeNode *node,const string &exp, int &i)//"+3*4/8 2"
{
    if (node == NULL){//insert
        while (exp[i] == ' ')
            i++;
        string strNumberN;
        while (isdigit(exp[i]))
            strNumberN.push_back(exp[i++]);
        if (strNumberN.size() == 0)
            strNumberN.push_back(exp[i++]);

        node = new TreeNode(strNumberN);
    }
    if (i < exp.length()){
        if (isdigit(node->val[0]))
            return node;

        node->left = insert(node->left, exp, i);
        node->right = insert(node->right, exp, i);
        
    }
    return node;
}

double Expression_Tree(string exp){
    TreeNode *root = NULL; int i = 0;
    root = insert (root, exp, i);
    //Evaluate expression.
    double result = 0;
    post_order_traverse(root, result);
    return result;
}


int main(void){
    cout << "Test 1\n";
    string exp = "+3*  4  /8 2";
    cout << exp << "\n"; 
    cout << "result is " << Expression_Tree(exp) << '\n' << '\n';

    cout << "Test 2\n";
    exp = "/+ 1 2 - 3 4";
    cout << exp << "\n";
    cout << "result is " << Expression_Tree(exp) << '\n' << '\n';

    cout << "Test 3\n";
    exp = " - * + - 8 1 3 6 * + 3 7 2";
    cout << exp << "\n";
    cout << "result is " << Expression_Tree(exp) << '\n' << '\n';

    cout << "Test 4\n";
    exp = "+/*4  2 3^ 7 2";
    cout << exp << "\n";
    cout << "result is " << fixed << setprecision(3) << Expression_Tree(exp) << '\n' << '\n';
    
    cout << "Test 5\n";
    exp = "-+ ^3  11  /4  18 * 5  200 ";
    cout << exp << "\n";
    cout << "result is " << fixed << setprecision(3) << Expression_Tree(exp) << '\n' << '\n';


    return 0;
}