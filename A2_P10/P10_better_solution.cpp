#include <iostream>
#include <vector>
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

TreeNode* insert(TreeNode *node, int element){

    if(node == NULL){
        node = new TreeNode(element);
        return node;
    }

    if(element > node->val)
        node->right = insert(node->right, element);
    else
        node->left = insert(node->left, element);

    return node;
}

void in_order_traverse (TreeNode *node, vector<int> &dfs)
{
    if (node != NULL){
        in_order_traverse(node->left, dfs);
        dfs.push_back(node->val);
        in_order_traverse(node->right, dfs);
    }
}

int find_Kth_Smallest_Sum(TreeNode *node, int k) {
    int sum = 0;
    vector<int> dfs;

    in_order_traverse(node, dfs);
    for(int i = 0; i < k; i++)
        sum+= dfs[i];

    return sum;
}

int main (void) {

    int k; cin >> k;
    TreeNode *root = new TreeNode(54);
    insert(root, 51);
    insert(root, 49);
    insert(root, 52);
    insert(root, 75);
    insert(root, 74);
    insert(root, 85);
    cout << find_Kth_Smallest_Sum(root, k) << "\n";

    cin >> k;
    TreeNode *root1 = new TreeNode(8);
    insert(root1 ,1);
    insert(root1 ,9);
    insert(root1 ,3);
    insert(root1 ,7);
    cout << find_Kth_Smallest_Sum(root1, k) << '\n';

    cin >> k;
    TreeNode *root2 = new TreeNode(1);
    insert(root2 ,2);
    insert(root2 ,3);
    insert(root2 ,4);
    insert(root2 ,5);
    cout << find_Kth_Smallest_Sum(root2, k) << '\n';

    cin >> k;
    TreeNode *root3 = new TreeNode(6);
    insert(root3 ,5);
    insert(root3 ,4);
    insert(root3 ,3);
    insert(root3 ,2);
    insert(root3 ,1);
    cout << find_Kth_Smallest_Sum(root3, k) << '\n';


    cin >> k;
    TreeNode *root4 = new TreeNode(5);
    insert(root4 ,5);
    insert(root4 ,5);
    insert(root4 ,5);
    insert(root4 ,5);
    insert(root4 ,5);
    cout << find_Kth_Smallest_Sum(root4, k) << '\n';


    return 0;
}
