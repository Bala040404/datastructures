#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int value;
    Node *next;

    Node(int val = 0)
    {
        value = val;
        next = nullptr;
    }
};

void append(Node *head, int value)
{
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = new Node(value);
}

void print(Node *head)
{
    Node *cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;
        cout << cur->value << " ";
    }
}

void insert(Node *head, int pos, int val)
{
    Node *cur = head;
    while (pos > 1)
    {
        cur = (*cur).next;
        pos--;
    }
    Node *rest = cur->next;
    Node *temp = new Node(val);
    temp->next = rest;
    cur->next = temp;
}

void Delete(Node *head, int pos)
{
    Node *cur = head;
    while (pos > 1)
    {
        cur = (*cur).next;
        pos--;
    }
    cur->next = cur->next->next;
}
// Node *reverse(Node *head,Node * prev =NULL)
// {
//     if (head->next != NULL)
//     {

//         Node *rest = reverse(head->next);
//         rest->next = head;

//         return rest;
//     }

//     return prev;
// }

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *cur = head->next;
    Node *next = cur->next;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    Node *temp = new Node();
    temp->next = prev;
    return temp;
}

int main()
{

    Node *head = new Node();
    append(head, 5);
    append(head, 6);
    append(head, 7);

    Node *temp = reverse(head);
    print(temp);
}