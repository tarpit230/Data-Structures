#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<< "memory freed for node with data " << val << endl;
    }
};

void print(Node* head) {
    Node* temp = head;
    
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int getLength(Node* head) {
    Node* temp = head;
    int len = 1;
    
    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);
    if(head == NULL){
        head = temp;
        tail = temp;
    } else {
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d) {
    
    Node* temp = new Node(d);
    if(tail == NULL) {
        tail = temp;
        head = temp;
    } else {
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    if(position == 1){
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position - 1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, head, d);
        return;
    }

    Node* nodeToinsert = new Node(d);
    nodeToinsert -> next = temp -> next;
    temp -> next -> prev = nodeToinsert;
    temp -> next = nodeToinsert;
    nodeToinsert -> prev = temp;
}

void deleteNode(Node* &head, int position) {
    
    if(position == 1) {

        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;

    } else {

        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;

    }

}

int main(){
    Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    // print(head);
    int length = getLength(head);
    // cout << length << endl;
    insertAtHead(head, tail, 5);
    print(head);
    insertAtTail(tail, head, 15);
    print(head);
    insertAtPosition(head, tail, 2, 100);
    print(head);
    deleteNode(head, 2);
    print(head);
    deleteNode(head, 1);
    print(head);

    return 0;
}