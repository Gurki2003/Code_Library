#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int data)
    {
        this->value = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int value)
{
    Node *temp = new Node(value);
    if (head == NULL)
    {
        head = temp;
    }
    temp->next = head;
    head = temp;
}
void insertAtBack(Node *&head, int value)
{
    Node *pos = head;
    Node *temp = new Node(value);
    if (head == NULL)
    {
        head = temp;
    }
    while (pos->next != NULL)
    {
        pos = pos->next;
    }
    pos->next = temp;
}
void insertAtPosition(Node* &head, int position, int value)
{   
    if(position == 0)
    {
        insertAtHead(head, value);
        return;
    }
    int count = 0;
    Node* temp = new Node(value);
    Node* curr = head;
    Node* prev = head;
    while(count < position)
    {
        count++;
        curr = curr->next;
    }
    if(curr == NULL || curr->next == NULL)
    {
        insertAtBack(head, value);
        return;
    }
    while(prev->next != curr)
    {
        prev = prev->next;
    }
    prev->next = temp;
    temp->next = curr;

    
}

void Print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

void reverseLinkedList(Node* &head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* Next_one = head;
    while(curr != NULL)
    {
        Next_one = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = Next_one;
    }
    head = prev;

}
void revll(Node* &head,Node* curr,Node* prev)
{
    if(head ==NULL || head->next ==NULL)
    {
        return;
    }
    if(curr != NULL)
    {
        revll(head,curr->next,curr);
        curr->next = prev;

    }
    else{
        head = prev;
        return;
    }

}
void detectAndRemoveDuplicates(Node* &head)
{
    Node* initial = head;
    Node* far = head;
    while(initial != NULL && initial->next != NULL)
    {
        far = initial;
        while(far != NULL && far->next != NULL)
        {
            if(far->next->value == initial->value)
            {
                far->next = far->next->next;
            }
            far = far->next;
        }
        initial = initial->next;
    }
}
int main()
{
    Node *head = new Node(10);
    insertAtBack(head, 20);
    insertAtBack(head, 20);
    insertAtBack(head, 40);
    insertAtBack(head, 30);
    insertAtBack(head, 20);
    insertAtBack(head, 10);
    Print(head);
    cout<<endl;
    detectAndRemoveDuplicates(head);
    // reverseLinkedList(head);
    // Node* prev =NULL;
    // revll(head,head,prev);

    Print(head);
    return 0;
}