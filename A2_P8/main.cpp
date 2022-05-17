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

void solve(string preOrder, string inOrder){
    cout << "PreOrder: " << preOrder << " InOrder: " << inOrder << "\n";
    cout << "Post Order: ";
    printPostOrder(preOrder, inOrder);
    cout << "\n\n";
}

int main (void)
{

    /* Tree 1
    |       A
    |      / \
    |     B   C
    |    / \
    |   F   G
    */
    string preOrder = "ABFGC", inOrder = "FBGAC";
    solve(preOrder, inOrder);

    /* Tree 2
    |        N
    |       / \
    |      /   \
    |     S     E
    |    / \   /
    |   H  U  I
    */
    preOrder = "NSHUEI", inOrder = "HSUNIE";
    solve(preOrder, inOrder);

    /* Tree 3
    |        A
    |       / \
    |      /   \
    |     B     C
    |    / \   / \
    |   D   E F   G
    |    \         \
    |     H         I
    |  
    */
    preOrder = "ABDHECFGI", inOrder = "DHBEAFCGI";
    solve(preOrder, inOrder);

    /* Tree 4
    |              a
    |             / \
    |            /   \
    |           /     \
    |          /       \
    |         /         \
    |        /           \
    |       I             f
    |      / \           / \
    |     /   \         /   \
    |    /     \       /     \  
    |   U       S     2       t   
    |  / \           / \     / \
    | 1   H         E   N   /   \
    |                      r     s
    |                     / \     \
    |                    A   m     u
    |                               \
    |                                M
    |                                 \
    |                                  3
    */
    preOrder = "aIU1HSf2ENtrAmsuM3", inOrder = "1UHISaE2NfArmtsuM3";
    solve(preOrder, inOrder);

    /* Tree 5
    |        S
    |       / \
    |      A   K
    |     / \   \ 
    |    T   H   N       
    */
    preOrder = "SATHKN", inOrder = "TAHSKN";
    solve(preOrder, inOrder);
    
    return 0;
}