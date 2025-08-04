#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    // Destructor
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

void InsertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

}  

void InsertAtTail(Node* &tail, int d) {

    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;

}

void InsertAtPosition(Node* &head, Node* &tail, int position, int d) {

    if(position == 1) {
        InsertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1) {
        temp = temp -> next;
        cnt++;
    }
     
    if(temp -> next == NULL) {
        InsertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node* nodeToInsert = new Node(d);
    
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

}

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

}

void deleteNode(int position, Node* &head) {

   //deleting first node
   if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start node
        temp -> next = NULL;
        delete temp;
    }
    else {
        //deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }


}

int main(){
    
    // Created a new node
    Node* node1 = new Node(10);
    // Node node1 = Node(10);
    cout << node1;
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    // head pointed to node1
    // Node* head = node1;
    // Node* tail = node1;
    // print(head);

    // InsertAtHead(head, 12);
    // print(head);

    // InsertAtHead(head, 15);
    // print(head);

    // InsertAtTail(tail, 20);
    // print(head);

    // InsertAtPosition(head, tail, 5, 16);
    // print(head);

    // cout << "head " << head -> data << endl;
    // cout << "tail " << tail -> data << endl;

    // deleteNode(1, head);
    // print(head);

    // deleteNode(4, head);
    // print(head);

    return 0;
}