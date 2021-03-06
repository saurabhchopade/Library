#include <iostream>
using namespace std;
template<typename T>
class Node{
    public:
        T data;
        Node<T> *next;
    
    Node(){
    }
    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template<typename T>
class stackLL : public Node<T>{
public:

    Node<T> *head;
    int size = 0;
    stackLL(){
        head = NULL;
    }

    void push(T element){
        if(head == NULL){
            size++;
            head = new Node<T>(element);
            return;
        }
        size++;
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        return;
    }

    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        return false;
    }

    void top(){
        if(isEmpty()){
            cout << "Stack Is Empty" << endl;
            return;
        }
            cout <<"top = " << head->data << endl;
    }

    void pop(){
        if(isEmpty()){
            cout << "Invalid Operation === Stack is Empty"<< endl;
            return;
        }  

        size--;
        Node<T> *dummy = head;
        head = head->next;
    }

    void sizeOfStack(){
        cout<< "Size of the stack is= "<< size << endl;
    }
};

int main() {
stackLL<string> obj;
obj.push("saurabh");
obj.top();
obj.pop();
obj.sizeOfStack();
}