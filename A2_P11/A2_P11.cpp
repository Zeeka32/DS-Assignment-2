#include <bits/stdc++.h>

using namespace std;

template<class T>
struct BSTNode {
private:
    T val;
    int height = 0;
    BSTNode *parent;
    BSTNode *right;
    BSTNode *left;
public:
    BSTNode() {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    BSTNode(T v) {
        val = v;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    BSTNode(const T &v, BSTNode *l, BSTNode *r) {
        val = v;
        left = new BSTNode<T>(l);
        right = new BSTNode<T>(r);
        parent = nullptr;
    }

    void setVal(T v) { val = v; }

    T getVal() { return val; }

    void setParent(BSTNode<T> *node) { parent = node; }

    BSTNode *getParent() { return parent; }

    void setRight(BSTNode<T> *node) { right = node; }

    BSTNode *getRight() { return right; }

    void setLeft(BSTNode<T> *node) { left = node; }

    BSTNode *getLeft() { return left; }

    int getHeight() { return height; }

    void setHeight(int h) { height = h; }

};

template<class T>
class BSTFCI {
private:
    BSTNode<T> *root;
    int sz;

    bool calculate_height(BSTNode<T> *x, BSTNode<T> *prev, bool ans) {

        if (x == nullptr) return ans;

        ans &= calculate_height(x->getRight(), x, ans);
        ans &= calculate_height(x->getLeft(), x, ans);

        if ((x->getRight() == nullptr || x->getLeft() == nullptr) && (x->getHeight() > 1)) return false;

        if (prev != nullptr) {
            if ((abs(prev->getHeight() - (x->getHeight() + 1)) > 1 && prev->getHeight() != 0)) return false;
            
            prev->setHeight(max(prev->getHeight(), x->getHeight() + 1));
        }

        return ans;
    }

public:

    BSTFCI() { root = nullptr, sz = 0; }

    BSTFCI(const T &v) { root = new BSTNode<T>(v); }

    bool empty() { return root == nullptr; }

    BSTNode<T> *getRoot() { return root; }

    void insert(T x) {
        sz++;
        if (empty())
            root = new BSTNode<T>(x);
        else {

            BSTNode<T> *p = root, *prev, *temp = new BSTNode<T>(x);

            while (p != nullptr) {
                prev = p;
                (x < p->getVal()) ? p = p->getLeft() : p = p->getRight();
            }

            (x < prev->getVal()) ? prev->setLeft(temp) : prev->setRight(temp);

            temp->setParent(prev);
        }
    }

    bool isSameTree(BSTNode<T> *p, BSTNode<T> *q){

        if(p != NULL && q != NULL){
            if(p->getVal() == q->getVal()){

                if(!isSameTree(p->getLeft(), q->getLeft()))
                    return false;

                if(!isSameTree(p->getRight(), q->getRight()))
                    return false;

            }else return false;

        }else if(p == NULL && q == NULL)
            return true;
        else 
            return false;

        return true;
    }

    bool isSubTreeSolver(BSTNode<T> *tree1, BSTNode<T> *tree2){

        if(isSameTree(tree1, tree2))
            return true;

        if(tree1 != nullptr && isSubTreeSolver(tree1->getLeft(), tree2))
            return true;

        if(tree1 != nullptr && isSubTreeSolver(tree1->getRight(), tree2))
            return true;

        return false;
    }

    bool isSubTree(BSTFCI *t1, BSTFCI *t2) {
        return isSubTreeSolver(t1->getRoot(), t2->getRoot());
    }

    bool isBalance() {
        return calculate_height(root, nullptr, true);
    }

    bool printRange(BSTNode<T> *x, T l, T r, bool f) {

        if (x == nullptr) return f;

        if (l < x->getVal())
            f |= printRange(x->getLeft(), l, r, f);

        if (l <= x->getVal() && x->getVal() <= r) {
            if (f) cout << ", ";
            f = true;
            cout << x->getVal();
        }

        if (x->getVal() < r)
            f |= printRange(x->getRight(), l, r, f);
            
        return f;
    }

    void printRange(T left, T right) {
        cout << '[';
        printRange(root, left, right, false);
        cout << ']';
    }

    void clear(BSTNode<T> *x) {
        if (x != nullptr){
            clear(x->getLeft());
            clear(x->getRight());
            delete x;
        }
    }

    void clear() {
        clear(root);
    }

    ~BSTFCI() {
        clear();
    }

};

int main() {
    BSTFCI<int> bst1(50), bst2, bst3, bst4, bst5, bst6;
    bst1.insert(70);
    bst1.insert(60);
    bst1.insert(80);
    bst1.insert(30);
    bst1.insert(20);
    bst1.insert(40);


    /*     main BST...
     *
     *        50
     *      /    \
     *     30     70
     *    /  \   /  \
     *   20  40 60  80
    */

//    cout << bst1.isBalance() << '\n'; // true
//    bst1.printRange(30, 70);
//    cout << '\n';

    /*  test 1
     *
     *         30
     *       /    \
     *      20    40
     */


    bst2.insert(30);
    bst2.insert(20);
    bst2.insert(40);

//    cout << bst2.isBalance() << '\n'; // true
    cout << bst1.isSubTree(&bst1, &bst2) << '\n'; // true
//    bst2.printRange(21, 39);
    cout << '\n';

    /*  test 2
     *
     *           2
     *          /  \
     *         1    3
     *               \
     *                4
     *                 \
     *                  5
     */

    bst3.insert(2);
    bst3.insert(1);
    bst3.insert(3);
    bst3.insert(4);
    bst3.insert(5);

//    cout << bst3.isBalance() << '\n'; // true
    cout << bst1.isSubTree(&bst1, &bst3) << '\n'; // false
//    bst3.printRange(1, 3);
    cout << '\n';

    /*     test 3
     *
     *        70
     *       /
     *     60
     */

    bst4.insert(70);
    bst4.insert(60);

//    cout << bst4.isBalance() << '\n'; // true
    cout << bst1.isSubTree(&bst1, &bst4) << '\n'; // true
//    bst4.printRange(1, 3);
    cout << '\n';

    /*     test 4
     *
     *       50
     */

    bst5.insert(50);

//    cout << bst5.isBalance() << '\n'; // true
    cout << bst1.isSubTree(&bst1, &bst5) << '\n'; // true
//    bst5.printRange(50, 50);
    cout << '\n';

    /*     test 5
     *
     *      50
     *      /
     *     30
     *    /  \
     *   20  40
     */

    bst6.insert(50);
    bst6.insert(30);
    bst6.insert(20);
    bst6.insert(40);

//    cout << bst6.isBalance() << '\n'; // true
    cout << bst1.isSubTree(&bst1, &bst6) << '\n'; // true
//    bst6.printRange(20, 35);
    cout << '\n';

    return 0;
}
