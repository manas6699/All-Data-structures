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

node *e(node *head)
{
    node *oddh = NULL;
    node *oddt = NULL;
    node *evenh = NULL;
    node *event = NULL;
    node *temp = head;

    while (oddh == NULL && evenh == NULL)
    {
        if (oddh == NULL && temp->data % 2 != 0)
        {
            oddh = temp;
            oddt = temp;
            temp = temp->next;
        }

        if (evenh == NULL && temp->data % 2 == 0)
        {
            evenh = temp;
            event = temp;
            temp = temp->next;
        }
    }

    while (temp != NULL)
    {
        if (temp->data % 2 != 0)
        {
            oddt->next = temp;
            temp = temp->next;
            oddt = oddt->next;
        }
        else
        {
            event->next = temp;
            temp = temp->next;
            event = event->next;
        }
    }

    oddt->next = NULL;
    event->next = NULL;
    oddt->next = evenh;

    return head;
}

node *take_inp()
{
    cout << "Enter linked list members : \n";
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

void print(node *head)
{
    cout << "your linked-list Members are : ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// inputs :                       1 2 3 4 5 6 7 8 9 -1

int main()
{
    node *head = take_inp();
    print(head);
    node *g = e(head);
    print(g);

    return 0;
}