#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val('0'), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};

double Expression_Tree(string exp){
    TreeNode *root = new TreeNode(exp[0]);

    //create expression tree
    TreeNode *temp = root;
    for(int i = 1; i < exp.length(); i++){
        if(i%2 != 0){
            temp->left = new TreeNode(exp[i]);
        }else{
            temp->right = new TreeNode(exp[i]);
            temp = temp->right;
        }
    }

    //Evaluate expression.
    stack<double> stk; double result = 0;
    for(int i = exp.length() - 1; i >= 0; i--){
        if(exp[i] != '/' && exp[i] != '*' && exp[i] != '+' && exp[i] != '-')
            stk.push(exp[i] - '0');
        else{
            double num1 = stk.top();
            stk.pop();
            double num2 = stk.top();
            stk.pop();
            if(exp[i] == '/')
                result = num1 / num2;
            else if(exp[i] == '+')
                result = num1 + num2;
            else if(exp[i] == '-')
                result = num1 - num2;
            else
                result = num1 * num2;
                
            stk.push(result);
        }
            
    }
    return result;
}

int main(void){

    //check for evaluation validness when a minus operator is included.
    string exp = "+3*4/82";
    cout << exp << "\n";
    cout << "Evaluation: " << Expression_Tree(exp) << "\n";

    exp = "*+12+34";
    cout << exp << "\n";
    cout << "Evaluation: " << Expression_Tree(exp) << "\n";

    exp = "-3+*4+215";
    cout << exp << "\n";
    cout << "Evaluation: " << Expression_Tree(exp) << "\n";
}