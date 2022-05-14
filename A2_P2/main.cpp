#include <iostream>

using namespace std;

template <class T>
class queue {
private:
    struct Node {
        Node *next = NULL;
        T     value;
        Node (T value)
        {
            this->value = value;
        }
    };
    Node *head;
    Node *tail;
    int __size = 0;
public:
    queue ()
    {
        head = tail = NULL;
    }

    queue (const queue &rhs)
    {
        head = tail = NULL;
        Node *cur = rhs.head;
        while (cur != rhs.tail){
            enqueue(cur->value);
            cur = cur->next;
        }
        enqueue(cur->value);
    }

    void enqueue (T value)
    {
        if (head == NULL){
            head = tail = new Node(value);
            __size++;
            return;
        }

        tail->next = new Node(value);
        tail = tail->next;
        __size++;
    }

    T dequeue (void)
    {
        if (tail == NULL)
            throw string("underflow");

        Node *tmp = head;
        head = head->next;
        if (head == NULL)
            tail = NULL;

        tmp->next = NULL;
        T value = tmp->value;
        delete tmp;
        __size--;
        return value;
    }

    T front (void) const
    {
        if (tail == NULL)
            throw string("underflow");
        return head->value;
    }

    bool empty (void) const
    {
        if (head == NULL)
            return true;
        else
            return false;
    }

    int size (void) const
    {
        return __size;
    }

    void clear (void)
    {
        while (!empty())
            dequeue();
    }


};

int time (queue <int> que, int k)
{
    int ticket, time = 0;
    for (int i = 0; i <= k ; i++) {
        ticket = que.front();
        que.dequeue();
        que.enqueue(--ticket);
        if (ticket >= 0)
            time++;
        if (i == k){
            i = 0;
            k = que.size();
            if (ticket == 0)
                return time;
        }
    }
}

template <class T>
void tester (int array[], int size, queue <T> &que)
{
    for (int i = 0; i < size; i++)
        que.enqueue(array[i]);
}

int main (void)
{
    cout << "Test 1\n";
    cout << "tickets = [2,3,2], k = 2\n";
    queue <int> que; int k = 2;int array[] = {2,3,2};
    tester<int>(array, 3, que);
    cout << "the " << k << "th person has to wait " << time(que, k) << " seconds"<< '\n';
    cout << '\n';
    que.clear();

    cout << "Test 2\n";
    cout << "tickets = [5,1,1,1], k = 0\n";
    k = 0; int array2[] = {5,1,1,1};
    tester<int>(array2, 4, que);
    cout << "the " << k << "th person has to wait " << time(que, k) << " seconds" << '\n';
    cout << '\n';
    que.clear();

    cout << "Test 3\n";
    cout << "tickets = [3,8,1,2,2] k = 4\n";
    k = 4;int array3[] = {3,8,1,2,2};
    tester<int>(array3, 5, que);
    cout << "the " << k << "th person has to wait " << time(que, k) << " seconds" << '\n';
    cout << '\n';
    que.clear();

    cout << "Test 4\n";
    cout << "tickets = [3,8,1,2,2,5,7,5,3] k = 6\n";
    k = 6;int array4[] = {3,8,1,2,2,5,7,5,3};
    tester<int>(array4, 9, que);
    cout << "the " << k << "th person has to wait " << time(que, k) << " seconds" << '\n';
    cout << '\n';
    que.clear();

    return 0;
}
