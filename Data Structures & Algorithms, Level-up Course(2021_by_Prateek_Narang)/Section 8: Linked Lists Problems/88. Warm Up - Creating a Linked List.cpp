#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

//-----------Linked List--------//
void insertAtHead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }

    // otherwise
    node *n = new node(data);
    n->next = head;
    head = n;
}

//--------insertInMiddle------//
void insertInMiddle(node *&head, int data, int pos)
{
    if (pos == 0)
    {
        head = new node(data);
        return;
    }

    // otherwise
    node *temp = head;
    for (int jump = 1; jump <= pos - 1; jump++)
    {
        temp = temp->next;
    }

    node *n = new node(data);
    n->next = temp->next;
    temp->next = n;
}

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertInMiddle(head, 100, 3);

    printLL(head);
}