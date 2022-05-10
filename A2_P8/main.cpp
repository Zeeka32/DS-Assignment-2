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

int findIndex(string inOrder, char target){

    for(int i = 0; i < inOrder.length(); i++)
        if(inOrder[i] == target)
            return i;
        
    return -1;
}

TreeNode* insert(string preOrder, string inOrder, int &preIndex, int inStart, int inEnd){

    if(inStart > inEnd)
        return nullptr;

    TreeNode *node = new TreeNode(preOrder[preIndex]);

    int index = findIndex(inOrder, preOrder[preIndex]);

    preIndex++;

    node->left = insert(preOrder, inOrder, preIndex, inStart, index - 1);
    node->right = insert(preOrder, inOrder, preIndex, index + 1, inEnd);

    return node;
    

}

void printPostOrder(string preOrder, string inOrder){
    
    int preIndex = 0;

    TreeNode *root = insert(preOrder, inOrder, preIndex, 0, inOrder.length() - 1);

    post_order_traverse(root);


}

int main (void)
{

    //test case1
    string preOrder = "ABFGC", inOrder = "FBGAC";
    cout << "PreOrder: " << preOrder << " InOrder: " << inOrder << "\n";
    cout << "Post Order: ";
    printPostOrder(preOrder, inOrder);
    cout << "\n\n";

    //test case2
    preOrder = "ABDHECFGI", inOrder = "DHBEAFCGI";
    cout << "PreOrder: " << preOrder << " InOrder: " << inOrder << "\n";
    cout << "Post Order: ";
    printPostOrder(preOrder, inOrder);
    cout << "\n\n";
    return 0;
}