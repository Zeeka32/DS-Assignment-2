#include <iostream>
#include <queue>

using namespace std;

template <class T>
struct Node  {
    Node *left = NULL;
    Node *right = NULL;
    T value;
    Node (T value) {this->value = value;}
    ~Node () {right = left = NULL;}
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
            if (placeholder != NULL){
                cout << '(' << placeholder->value << ')' << '\t';
                nodes.push(placeholder->left);
                nodes.push(placeholder->right);
            }
            else
                cout << "(NULL)\t";
            nodes.pop();
        }
    }else{
        cout << "(NULL)";
    }
}// this printer is not good help!

template <class T>
void free (Node <T> *root)
{
    if (root != NULL){
        free(root->left);
        free(root->right);
        delete root;
        root = NULL;
    }
}

int main (void)
{
    Node <int> *root = new Node <int> (5);
    root->right = new Node <int> (1);
    root->left = new Node <int> (2);
    root->left->right = new Node <int> (8);
    root->left->left = new Node <int> (10);
    root->right->right = new Node <int> (88);
    root->right->left = new Node <int> (12);

    /*
          5
         / \
        /   \
       2     1
      / \   / \
     10 8  12 88
    */
    cout << "Test1\n";
    
    flip<int>(root);
    breadth_first_traversal(root);
    free<int>(root);
    cout << '\n' << '\n';

    /*
          5
         / \
        /   \
       1     2
              \
              88
    */
    cout << "Test2\n";
    root = new Node <int> (5);
    root->left = new Node <int> (1);
    root->right = new Node <int> (2);
    root->right->right = new Node <int> (88);
    flip<int>(root);
    breadth_first_traversal(root);
    free<int>(root);
    cout << '\n' << '\n';

    /*
             1
            / \
           /   \
          2     3
         / \  
        4   5   
    */
    cout << "Test3\n";
    root = new Node <int> (1);
    root->left = new Node <int> (2);
    root->right = new Node <int> (3);
    root->left->left = new Node <int> (4);
    root->left->right = new Node <int> (5);
    flip<int>(root);
    breadth_first_traversal(root);
    free<int>(root);
    cout << '\n' << '\n';

    /*
             1
            / \
           /   \
          2     3
         / \  
        4   5
           /
          10
    */
    cout << "Test4\n";
    root = new Node <int> (1);
    root->left = new Node <int> (2);
    root->right = new Node <int> (3);
    root->left->left = new Node <int> (4);
    root->left->right = new Node <int> (5);
    root->left->right->left = new Node <int> (10);
    flip<int>(root);
    breadth_first_traversal(root);
    free<int>(root);
    cout << '\n' << '\n';

    /*
             1
            / \
           /   \
          2     3
         / \     \
        4   5     9
           /
          10
    */
    cout << "Test5\n";
    root = new Node <int> (1);
    root->left = new Node <int> (2);
    root->right = new Node <int> (3);
    root->right->right = new Node <int> (9);
    root->left->left = new Node <int> (4);
    root->left->right = new Node <int> (5);
    root->left->right->left = new Node <int> (10);
    flip<int>(root);
    breadth_first_traversal(root);
    free<int>(root);
    cout << '\n' << '\n';
    return 0;
}