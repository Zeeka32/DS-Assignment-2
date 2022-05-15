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

    T pop() {
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

    bool empty(){ return size == 0; }

};

string canon_path(string path){

    //adding to path so path is it meets if conditions, pushing first top
    stack<char> stk; stk.push('/'), path.push_back('/');

    for(int i = 1; i < path.length(); i++)
    
        if (path[i] == '/' && stk.top() != '/')// case you get / and stack top not /
            stk.push('/');

        else if (path[i] == '/')
            continue;

        //handling /.. command
        else if (path[i] == '.' && path[i+1] == '.' && path[i+2] == '/' && stk.top() == '/'){
            if (stk.getSize() > 1)
                stk.pop();
            while (stk.top() != '/')
                stk.pop();
        }

        //if it is a single dot we ignore it.
        else if (path[i] == '.' && path[i+1] == '/' && stk.top() == '/')
            continue;
        else
            stk.push(path[i]);

    //remove slash from end of the stack.
    if (stk.getSize() > 1)
        stk.pop();

    //reverse the stack to put it into the string.
    stack<char> reverseStk;
    while (!stk.empty())
        reverseStk.push(stk.pop());

    //putting the final answer into the string and returning the answer.
    string canonicalPath;
    while (!reverseStk.empty())
        canonicalPath.push_back(reverseStk.pop());

    return canonicalPath;
}


int main(void){
    //"/home"
    string input = "/home/";
    cout << "input path:" << input << "\n";
    cout << "canonical path:" << canon_path(input) << "\n\n";

    //"/"
    input = "/../";
    cout << "input path:" << input << "\n";
    cout << "canonical path:" << canon_path(input) << "\n\n";

    //"/"
    input = "/a/../.././../../.";
    cout << "input path:" << input << "\n";
    cout << "canonical path:" << canon_path(input) << "\n\n";

    //"/c"
    input = "/a/./b/../../c/";
    cout << "input path:" << input << "\n";
    cout << "canonical path:" << canon_path(input) << "\n\n";

    // Expected Result /...
    input = "/.../";
    cout << "input path:" << input << "\n";
    cout << "canonical path:" << canon_path(input) << "\n\n";

    return 0;
}