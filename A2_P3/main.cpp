#include <iostream>
using namespace std;

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

class stack{
private:
    queue q;
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

};

int main(void){

    stack x;
    x.push(1);
    x.push(2);
    x.push(3);

}