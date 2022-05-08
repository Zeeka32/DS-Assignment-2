#include <iostream>
#include <queue>

using namespace std;

template <class T>
struct Node  {
    Node *left = NULL;
    Node *right = NULL;
    T value;
    Node (T value) {this->value = value;}
};

template <class T>
void flip (Node <T> *node){
    if (node != NULL){//post order
        flip(node->left);
        flip(node->right);
        Node <T> *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

template <class T>
void breadth_first_traversal (Node <T> *node)
{
    if (node != NULL){
        queue <Node <T>* > nodes;
        nodes.push(node);
        while(!nodes.empty()){
            Node <T>* placeholder = nodes.front();
            cout << '(' << placeholder->value << ')' << '\t';
            if(placeholder->left != NULL) {
                nodes.push(placeholder->left);
            }
            if(placeholder->right != NULL) {
                nodes.push(placeholder->right);
            }
            nodes.pop();
        }
    }
}


int main (void)
{
    Node <int> *root = new Node <int> (5);
    Node <int> *lv1_right = new Node <int> (1);
    Node <int> *lv1_left = new Node <int> (2);
    Node <int> *lv2_right1 = new Node <int> (8);
    Node <int> *lv2_left1 = new Node <int> (10);
    Node <int> *lv2_right2 = new Node <int> (88);
    Node <int> *lv2_left2 = new Node <int> (12);

    /*
          5
         / \
        /   \
       2     1
      / \   / \
     10 8  12 88
    */
    cout << "Test1\n";
    root->right = lv1_right;
    root->left = lv1_left;
    lv1_left->right = lv2_right1;
    lv1_left->left = lv2_left1;
    lv1_right->left = lv2_left2;
    lv1_right->right = lv2_right2;
    flip<int>(root);
    breadth_first_traversal(root);
    cout << '\n';

    /*
          5
         / \
        /   \
       1     2
              \
              88
    */
    cout << "Test2\n";
    lv1_left->left = NULL;
    lv1_right->right = lv1_right->left = NULL;
    flip<int>(root);
    breadth_first_traversal(root);
    cout << '\n';

    return 0;
}