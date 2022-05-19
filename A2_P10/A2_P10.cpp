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
    for(int i = 0; dfs[i] <= dfs[k - 1] && i < dfs.size(); i++)
        sum+= dfs[i];

    return sum;
}

int main (void) {
    int k;

    /*
                54
                / \
               /   \
              /     \
            51       75
           / \      / \    
          /   \    /   \
         49    52 74    85
    */
    cout << "Test 1\n" << "k = 3 >> ";
    k = 3;
    TreeNode *root = new TreeNode(54);
    insert(root, 51);
    insert(root, 49);
    insert(root, 52);
    insert(root, 75);
    insert(root, 74);
    insert(root, 85);
    cout << find_Kth_Smallest_Sum(root, k) << "\n\n";
    

    /*
    |             8
    |            / \
    |           /   \
    |          /     \
    |        1        9
    |         \          
    |          \    
    |           3
    |            \
    |             7  
    */
    cout << "Test 2\n" << "K = 2 >> ";
    k = 2;
    TreeNode *root1 = new TreeNode(8);
    insert(root1 ,1);
    insert(root1 ,9);
    insert(root1 ,3);
    insert(root1 ,7);
    cout << find_Kth_Smallest_Sum(root1, k) << "\n\n";

    /*
    |        1
    |         \
    |          2
    |           \
    |            3
    |             \
    |              4
    |               \
    |                5
    */
    cout << "Test 3\n" << "K = 4 >> ";
    k = 4;
    TreeNode *root2 = new TreeNode(1);
    insert(root2 ,2);
    insert(root2 ,3);
    insert(root2 ,4);
    insert(root2 ,5);
    cout << find_Kth_Smallest_Sum(root2, k) << "\n\n";


    /*
    |               6
    |              /
    |             5
    |            /
    |           4
    |          /
    |         3
    |        /
    |       2
    |      /
    |     1      
    */
    cout << "Test 4\n" << "K = 3 >> ";
    k = 3;
    TreeNode *root3 = new TreeNode(6);
    insert(root3 ,5);
    insert(root3 ,4);
    insert(root3 ,3);
    insert(root3 ,2);
    insert(root3 ,1);
    cout << find_Kth_Smallest_Sum(root3, k) << "\n\n";


    /*
    |             5
    |            / \
    |           3   6
    |          /
    |         2
    |        /
    |      -1
    */
    cout << "Test 5\n" << "K = 5 >> ";
    k = 5;
    TreeNode *root4 = new TreeNode(5);
    insert(root4 ,3);
    insert(root4 ,2);
    insert(root4 ,-1);
    insert(root4 ,6);
    cout << find_Kth_Smallest_Sum(root4, k) << "\n\n";


    return 0;
}
