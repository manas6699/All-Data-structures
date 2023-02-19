#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

node *delete_node_recursively(node *head , int i)
{
    node *temp = head;
    if(head == NULL)
    {
        return NULL;
    }

    if(i == 0)
    {
        node *temp2 = head;
        head = head->next;
        delete temp2;
        return head;
    }
    head->next = delete_node_recursively(head->next , i - 1);
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
    cout << "Your linked-list Members are : ";
    while (head != NULL)
    {
        cout <<  head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *head = take_inp();
    print(head);

    int i;
    cout << "Enter the node you wanna delete : ";
    cin >> i;

    head = delete_node_recursively(head , i);
    print(head);

    return 0;
}