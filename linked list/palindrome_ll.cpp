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

node *take_inp()
{
    cout << "Enter linked list members : ";
    int data;
    cin >> data;

    node *head = NULL;
    node *tail = NULL;

    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

node *reverse_ll(node *head)
{
     cout << " \n ";
    if (head == NULL)
    {
        return head;
    }
    else
    {
        reverse_ll(head->next);
        
    }
    return head;
}

void print(node *head)
{
    cout << "Your linked list members are : ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    node *head = take_inp();
    print(head);

    reverse_ll(head);
    print(head);
    return 0;
}