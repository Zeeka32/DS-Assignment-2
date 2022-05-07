#include<iostream>
using namespace std;

template <class T>
class stack{
private:
    struct node{
        T value;
        node *next;
        node *previous;
    };
    node *head, *tail;
    int size = 0;
public:
    stack() { head = tail = NULL; }

    int getSize() { return size; }

    void push(T element){

        if(size == 0){
            node *temp = new node;
            temp->value = element;
            head = tail = temp;
            size++;
        }

        node *temp = new node;
        temp->value = element;
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
        size++;
    }

    T pop() {
        if(size == 0)
            throw "Empty stack exception";

        T temp = tail->value;
        tail = tail->previous;
        delete tail->next;
        size--;
        
        return temp;
    }

};

string canonPath(stack<char> stk, string path){
            
}

int main(void){
    
    

}