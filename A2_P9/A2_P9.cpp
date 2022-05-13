#include <bits/stdc++.h>

using namespace std;

template<class T>
struct Node {
private:
    T val;
    Node *parent;
    Node *right;
    Node *left;
public:
    Node() {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    Node(T v) {
        val = v;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    Node(const T &v, Node *l, Node *r) {
        val = v;
        left = new Node<T>(l);
        right = new Node<T>(r);
        parent = nullptr;
    }

    T getVal() { return val; }

    void setVal(T v) { val = v; }

    Node *getParent() { return parent; }

    Node *getRight() { return right; }

    void setRight(Node<T> *node) { right = node; }

    Node *getLeft() { return left; }

    void setLeft(Node<T> *node) { left = node; }

    void setParent(Node<T> *node) { parent = node; }

};

template<class T>
class BST {
private:
    vector<T> v, s;
    Node<T> *root;
public:

    BST() { root = nullptr; }

    BST(const T &v) { root = new Node<T>(v); }

    bool empty() { return root == nullptr; }

    T find(const T x) {
        Node<T> *p = root;
        while (p != nullptr) {
            if (x == p->getVal())
                return p->getVal();
            (x < p->getVal()) ? p = p->getLeft() : p = p->getRight();
        }
        return -1000000000;
    }

    void insert(T x) {
        if (empty())
            root = new Node<T>(x);
        else {
            Node<T> *p = root, *prev, *temp = new Node<T>(x);
            while (p != nullptr) {
                prev = p;
                (x < p->getVal()) ? p = p->getLeft() : p = p->getRight();
            }
            (x < prev->getVal()) ? prev->setLeft(temp) : prev->setRight(temp);
            temp->setParent(prev);
        }
    }

    void dfs1(Node<T> *x) {
        if (x == nullptr) return;
        v.push_back(0);
        dfs1(x->getLeft());
        v.push_back(1);
        dfs1(x->getRight());
    }

    void dfs2(Node<T> *x) {
        if (x == nullptr) return;
        s.push_back(0);
        dfs2(x->getRight());
        s.push_back(1);
        dfs2(x->getLeft());
    }

    bool isFoldable() {
        dfs1(root->getLeft());
        dfs2(root->getRight());
        if ((int) v.size() != (int) s.size()) return false;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != s[i])
                return false;
        }
        return true;
    }

    void clear(Node<T> *x) {
        if (x == nullptr) return;
        dfs(x->getLeft());
        dfs(x->getRight());
        delete x;
    }

    void clear() {
        clear(root);
    }

    ~BST() {
        clear();
    }
};

int main() {
    BST<int> bst1(54), bst2, bst3, bst4, bst5;
    bst1.insert(51);
    bst1.insert(49);
    bst1.insert(52);
    bst1.insert(75);
    bst1.insert(74);
    bst1.insert(85);

    cout << bst1.isFoldable() << '\n';


    bst2.insert(8);
    bst2.insert(1);
    bst2.insert(9);
    bst2.insert(3);
    bst2.insert(7);

    cout << bst2.isFoldable() << '\n';

    bst3.insert(1);
    bst3.insert(2);
    bst3.insert(3);
    bst3.insert(4);
    bst3.insert(5);

    cout << bst3.isFoldable() << '\n';

    bst4.insert(6);
    bst4.insert(5);
    bst4.insert(7);
    bst4.insert(3);
    bst4.insert(8);

    cout << bst4.isFoldable() << '\n';

    bst5.insert(5);
    bst5.insert(5);
    bst5.insert(5);
    bst5.insert(5);
    bst5.insert(5);
    bst5.insert(5);

    cout << bst5.isFoldable() << '\n';

    return 0;
}
