#include <iostream>
using namespace std;

template <class T>//template
class queue{
private:
    struct node{
        int value;
        node *next;
    };
    node *head, *tail;
    int size = 0;
public:

    void enqueue(int element){
        if(size == 0){
            node *temp = new node;
            temp->value = element;
            head = tail = temp;
            size++;
            return;
        }

        node *temp = new node;
        temp->value = element;
        tail->next = temp;
        tail = temp;
        size++;
    }

    void dequeue(){
        node *temp = head;
        head = head->next;
        size--;
        delete temp;
    }

    int front() { return head->value; }

    int getSize() { return size; }

    bool isEmpty() { return size == 0; }
};

template <class T>
class stack{
private:
    queue  <T> q;
public:

    void push(int element){
        
        int tempSize = q.getSize();

        q.enqueue(element);

        while(tempSize--)
            q.enqueue(q.front()), q.dequeue();
    }

    void pop(){
        if(q.getSize() == 0)
            throw string("empty stack exception");
        else
            q.dequeue();
    }

    int top() { return q.front(); }

    bool isEmpty (void)//added for testing
    {
        if (q.isEmpty())
            return true;
        else 
            return false;
    }

};

int main(void){
    //providing main
    cout << "test 1\n";
    stack <int> x;
    x.push(1);
    x.push(2);
    x.push(3);
    x.push(4);
    while (!x.isEmpty()){
        cout << "stack top :" << x.top() << '\n';
        x.pop();
    }
    try{x.pop();}
    catch (string e){cout << e << endl;}

    cout << endl;

    cout << "test 2\n";
    x.push(8);
    x.push(7);
    x.push(6);
    x.push(2);
    while (!x.isEmpty()){
        cout << "stack top :" << x.top() << '\n';
        x.pop();
    }
}