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
            return;
        }

        node *temp = new node;
        temp->value = element;
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
        size++;
    }

    T pop() throw (string) {
        if(size == 0)
            throw "Empty stack exception";

        T temp = tail->value;
        if(size == 1){
            delete tail;
            size--;
        }
        else{
            tail = tail->previous;
            delete tail->next;
            size--;
        }

        return temp;
    }

    T top() { return tail->value; }

    bool isEmpty(){ return size == 0; }

};




string canonPath(string path){

    stack<char> reverse;
    reverse.push('/'), path.push_back('/'), path.push_back('/');//adding to path so path is it meets if conditions, pushing first top
    for(int i = 1; i < path.length(); i++){
        if (path[i] == '/' && reverse.top() != '/')// case you get / and stack top not /
            reverse.push('/');

        else if (path[i] == '/')
            continue;//ignore

        else if (path[i] == '.' && path[i+1] == '.' && path[i+2] == '/' && reverse.top() == '/'){//encounter ".."
            if (reverse.getSize() > 1)
                reverse.pop();
            while (reverse.top() != '/')
                reverse.pop();
        }
        else if (path[i] == '.' && path[i+1] == '/' && reverse.top() == '/')
            continue;//ignore we will handle top later
        else
            reverse.push(path[i]);
    }
    if (reverse.getSize() > 1)//pop top slash
        reverse.pop();

    //reverse
    stack<char> original;
    while (!reverse.isEmpty())
        original.push(reverse.pop());

    //making result
    string canonicalPath;
    while (!original.isEmpty())
        canonicalPath.push_back(original.pop());

    return canonicalPath;
}


int main(void){
    //"/home"
    string input = "/home/";
    cout << "input path:" << input << "\n";
    cout << "canonical path:" << canonPath(input) << "\n\n";

    //"/"
    input = "/../";
    cout << "input path:" << input << "\n";
    cout << "canonical path:" << canonPath(input) << "\n\n";

    //"/"
    input = "/a/../.././../../.";
    cout << "input path:" << input << "\n";
    cout << "canonical path:" << canonPath(input) << "\n\n";

    //"/c"
    input = "/a/./b/../../c/";
    cout << "input path:" << input << "\n";
    cout << "canonical path:" << canonPath(input) << "\n\n";

    //"/a/b/c/d"
    input = "/a//b//c//////d";
    cout << "input path:" << input << "\n";
    cout << "canonical path:" << canonPath(input) << "\n\n";

    //"/a/b/c/d"
    input = "/..///../a/b/c/.//..//d///..";
    cout << "input path:" << input << "\n";
    cout << "canonical path:" << canonPath(input) << "\n\n";

    return 0;
}