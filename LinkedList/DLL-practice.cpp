#include <iostream>
#include<stack>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int data = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with value: " << data;
        cout << endl;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<< endl;
}

void insertAtHead(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    if (tail == NULL)
    {
        tail = temp;
        head = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int val)
{
    if (position == 1)
    {
        insertAtHead(head, tail, val);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    Node *nodeToInsert = new Node(val);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *Prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            Prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        Prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

Node* reverseDLL(Node* &head) {
    // Brute force Approach - 
    // 1. Iterate the linkedlist and push node->data into the stack.
    // 2. Iterate second time and push stack data from top to linked list.
    // 3. this will reverse the data in nodes of DLL.

    // Node* temp = head;
    // stack<int> st;
    // while(temp != NULL) {
    //     st.push(temp -> data);
    //     temp = temp -> next;
    // }
    // temp = head;
    // while(temp != NULL) {
    //     temp -> data = st.top();
    //     st.pop();
    //     temp = temp -> next;
    // }
    // return head;

    // Optimal Approach
    // 1. traverse through linked list and swap the pointers
    // of each node.
    // 2. Doing so will reverse linked list in single iteration.
    // 3. Use curr and last pointer.

    Node* last = NULL;
    Node* curr = head;
    while(curr != NULL) {
        last = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = last;
        curr = curr -> prev;
    }
    if (last != NULL) {
        head = last->prev;
    }
    return head;
}

int getLength(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL) {
        temp = temp -> next;
        cnt++;
    }
    return cnt;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    
    insertAtHead(head, tail, 5);
    insertAtTail(head, tail, 7);
    insertAtPosition(head, tail, 2, 9);
    // deleteNode(head, 1);
    reverseDLL(head);
    print(head);
    // cout << getLength(head) << endl;
}