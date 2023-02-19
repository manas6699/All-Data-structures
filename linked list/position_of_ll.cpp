#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

void position_of_ll(node *tail)
{
    int position;
    cout << "Enter the position of the linked list :-\n";
    cin >> position;
    for (int i = 0; i < position ; i++)
    {
        tail = tail->next;
    }
    cout << tail->data;
}

node *take_inp()
{
    cout << "Enter linked list members\n";
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

int main()
{

    node *head = take_inp();

    position_of_ll(head);
    return 0;
}