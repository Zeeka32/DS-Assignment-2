#include <iostream>
#include <windows.h>

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

    void push (T value)
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

    T pop (void)
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
};

int time (queue <int> &que, int k)
{
    int ticket, time = 0;
    for (int i = 0; true ; i++) {
        ticket = que.front();
        que.pop();
        que.push(--ticket);
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

int main (void)
{
    cout << "Test 1\n";
    cout << "tickets = [2,3,2], k = 2\n"; 
    queue <int> que; int k = 2;
    que.push(2);
    que.push(3);
    que.push(2);
    cout << "the " << k << "th person has to wait " << time(que, k) << " seconds"<< '\n';


    cout << "Test 2\n";
    cout << "tickets = [5,1,1,1], k = 0\n"; 
    queue <int> que2;int k2 = 0;
    que2.push(5);
    que2.push(1);
    que2.push(1);
    que2.push(1);
    cout << "the " << k2 << "th person has to wait " << time(que2, k2) << " seconds" << '\n';
    return 0;
}