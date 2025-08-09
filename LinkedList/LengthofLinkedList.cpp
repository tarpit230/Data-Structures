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

void insertAttail(Node* &tail, int val) {
    Node* temp = new Node(val);
    tail -> next = temp;
    tail = temp;
}

void insertAtHead(Node* &head, int val){
    Node* temp = new Node(val);
    temp -> next = head;
    head = temp;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int lengthofLinkedList(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        temp = temp -> next;
    }
    return cnt;
}

bool searchElement(Node* head, int val) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp -> data == val) return true;
        temp = temp -> next;
    }
    return false;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int val) {
    if(position == 1) {
        insertAtHead(head, val);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != NULL) {
        temp = temp -> next;
        cnt++;
    }
    if(temp -> next == NULL) {
        insertAttail(tail, val);
        return;
    }
    
    Node* nodeToInsert = new Node(val);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
    
}

int main() {
    int arr[] = {2, 3, 4, 8};
    Node* head = new Node(arr[0]);
    Node* tail = head;
    int size = sizeof arr/sizeof arr[0];
    int i = 1;
    while(i<4) {
        insertAttail(tail, arr[i]);
        i++;
    }
    insertAtPosition(head, tail, 5, 5);
    print(head);
    // cout << lengthofLinkedList(head) << endl;
    // cout << searchElement(head, 6);
    return 0;
}