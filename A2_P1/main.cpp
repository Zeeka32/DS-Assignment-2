#include<iostream>
using namespace std;
//this is a test comment
template <class T>//trying with new comment
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

    T pop() const throw (string) {
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

    stack<char> stk; string canonicalPath = "";

    for(int i = 0; i < path.length(); i++){
        if(path[i] == '/' && stk.isEmpty())
            stk.push(path[i]);

        else if(path[i] == '.' && path[i + 1] == '.' && !stk.isEmpty()){
            stk.pop();
            continue;

        }else if(path[i] == '.')
            continue;

        else if(path[i] == '/')
            continue;

        else if(!stk.isEmpty()){
            canonicalPath.push_back(stk.pop());
            canonicalPath.push_back(path[i]);
        }
        else
            canonicalPath.push_back(path[i]);
    }

    if(canonicalPath.empty())
        canonicalPath.push_back('/');

    return canonicalPath;
}

/*this problem is not solved yet. this is only a rough initial 
  draft based on the current understanding of the unix based style file system
  so far what i know is all characters are ignored except for "/", ".."
  where ".." returns to the parent folder.
  meaning if we have a path: /home/users/zeeka/../downloads/
  the canonical path should be: /home/users/downloads
  where downloads is a folder in users.
  
  this is not yet implemented.*/

int main(void){
    
    string input = "/home/";
    cout << "input path:" << input << "\n";
    cout << "canonical path:" << canonPath(input) << "\n\n";
    
    cout << "input path:" << input << "\n";
    input = "/../";
    cout << "canonical path:" << canonPath(input) << "\n\n";

    cout << "input path:" << input << "\n";
    input = "/home//foo/";
    cout << "canonical path:" << canonPath(input) << "\n\n";

}