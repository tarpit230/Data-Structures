/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;

class ListNode
{

public:
    int data;
    ListNode *next;

    // Constructor
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~ListNode()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};
class Solution
{
public:
    // int getLength(ListNode* head) {
    //     ListNode* temp = head;
    //     int cnt = 0;
    //     while (temp != nullptr) {
    //         temp = temp->next;
    //         cnt++;
    //     }
    //     return cnt;
    // }
    ListNode *deleteMiddle(ListNode *head)
    {
        // Brute force method
        // if(!head) return head;

        // int length = getLength(head);
        // if(length == 1) {
        //     ListNode* temp = head;
        //     head = head -> next;
        //     // delete temp;
        //     return head;
        // }
        // int middleNode = length / 2;
        // ListNode* prev = nullptr;
        // ListNode* curr = head;
        // for(int i =0; i< middleNode; i++) {
        //     prev = curr;
        //     curr = curr->next;
        // }
        // prev -> next = curr -> next;
        // // delete curr;
        // return head;

        // Optimal method
        if (!head)
            return head;
        if (!head->next)
        {
            head = head->next;
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return head;
    }

    void InsertAtHead(ListNode *&head, int d)
    {
        // new node create
        ListNode *temp = new ListNode(d);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    ListNode *head = new ListNode(4);
    Solution *sol = new Solution();
    sol->InsertAtHead(head, 3);
    sol->InsertAtHead(head, 2);
    sol->InsertAtHead(head, 1);
    ListNode *temp = sol->deleteMiddle(head);
    while(temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}