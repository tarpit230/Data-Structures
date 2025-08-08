#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        int value = this -> data;
        // memory free
        if(this -> next != NULL){ 
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

int main() {
    int arr[] = {2, 3, 4, 8};
    for(int i=0; i<sizeof arr/sizeof arr[0]; i++) {
        if(i == 0) Node* head = new Node(arr[i]);
        else {
            Node* temp = head;
        }
    }
}