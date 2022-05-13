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
    Node<T> *root;
public:
    vector<T> v;

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

    void dfs(Node<T> *x) {
        if (x == nullptr) return;
        v.push_back(x->getVal());
        dfs(x->getLeft());
        dfs(x->getRight());
    }

    long long sum;

    T findKthSmallest(int k) {
        sum = 0;
        dfs(root);
        sort(v.begin(), v.end());
        for (int i = 0; i < (int) v.size() && k; ++i) {
            if (v[i] != v[i + 1])
                k--;
            sum += v[i];
        }
        return sum;
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
    int k;
    cin >> k;
    BST<int> bst1(54), bst2, bst3, bst4, bst5;
    bst1.insert(51);
    bst1.insert(49);
    bst1.insert(52);
    bst1.insert(75);
    bst1.insert(74);
    bst1.insert(85);
    cout << bst1.findKthSmallest(k) << endl;

    cin >> k;
    bst2.insert(8);
    bst2.insert(1);
    bst2.insert(9);
    bst2.insert(3);
    bst2.insert(7);
    cout << bst2.findKthSmallest(k) << '\n';

    cin >> k;
    bst3.insert(1);
    bst3.insert(2);
    bst3.insert(3);
    bst3.insert(4);
    bst3.insert(5);
    cout << bst3.findKthSmallest(k) << '\n';

    cin >> k;
    bst4.insert(6);
    bst4.insert(5);
    bst4.insert(4);
    bst4.insert(3);
    bst4.insert(2);
    bst4.insert(1);
    cout << bst4.findKthSmallest(k) << '\n';


    cin >> k;
    bst5.insert(5);
    bst5.insert(5);
    bst5.insert(5);
    bst5.insert(5);
    bst5.insert(5);
    bst5.insert(5);
    cout << bst5.findKthSmallest(k) << '\n';

    return 0;
}
