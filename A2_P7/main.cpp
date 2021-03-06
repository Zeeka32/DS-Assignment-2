#include <iostream>
#include <queue>

using namespace std;

template<class T>
struct Node {
    Node *left = NULL;
    Node *right = NULL;
    T value;

    Node(T value) { this->value = value; }

    ~Node() { right = left = NULL; }
};

template<class T>
void flip(Node<T> *node) {
    if (node != NULL) {//post order
        flip(node->right);
        flip(node->left);
        Node<T> *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

template<class T>
void BFT(Node<T> *node){
    if(node != NULL){
        queue<Node<T>*> Q; int i = 1, j = 1;
        Q.push(node);
        while(!Q.empty()){
            i++;
            Node<T> *cur = Q.front();
            cout << cur->value << " ";
            if(i % j == 0){
                cout << "\n";
                j*= 2;
            }

            if(cur->left != NULL)
                Q.push(cur->left);
            if(cur->right != NULL)
                Q.push(cur->right);
            Q.pop();
        }
    }
}

template<class T>
void free(Node<T> *root) {
    if (root != NULL) {
        free(root->left);
        free(root->right);
        delete root;
        root = NULL;
    }
}

int main(void) {
    Node<int> *root = new Node<int>(5);
    root->right = new Node<int>(1);
    root->left = new Node<int>(2);
    root->left->right = new Node<int>(8);
    root->left->left = new Node<int>(10);
    root->right->right = new Node<int>(88);
    root->right->left = new Node<int>(12);

    /*
          5
         / \
        /   \
       2     1
      / \   / \
     10 8  12 88
    */
    cout << "Test 1\nThe post order of the reversed tree is: \n";

    flip<int>(root);
    BFT(root);
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
    cout << "Test 2\nThe postorder of the reversed tree is: \n";
    root = new Node<int>(5);
    root->left = new Node<int>(1);
    root->right = new Node<int>(2);
    root->right->right = new Node<int>(88);
    flip<int>(root);
    BFT(root);
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
    cout << "Test 3\nThe postorder of the reversed tree is: \n";
    root = new Node<int>(1);
    root->left = new Node<int>(2);
    root->right = new Node<int>(3);
    root->left->left = new Node<int>(4);
    root->left->right = new Node<int>(5);
    flip<int>(root);
    BFT(root);
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
    cout << "Test 4\nThe postorder of the reversed tree is: \n";
    root = new Node<int>(1);
    root->left = new Node<int>(2);
    root->right = new Node<int>(3);
    root->left->left = new Node<int>(4);
    root->left->right = new Node<int>(5);
    root->left->right->left = new Node<int>(10);
    flip<int>(root);
    BFT(root);
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
    cout << "Test 5\nThe postorder of the reversed tree is: \n";
    root = new Node<int>(1);
    root->left = new Node<int>(2);
    root->right = new Node<int>(3);
    root->right->right = new Node<int>(9);
    root->left->left = new Node<int>(4);
    root->left->right = new Node<int>(5);
    root->left->right->left = new Node<int>(10);
    flip<int>(root);
    BFT(root);
    free<int>(root);
    cout << '\n' << '\n';
    return 0;
}
