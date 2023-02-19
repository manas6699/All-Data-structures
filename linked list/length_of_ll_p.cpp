#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

int checkLength (node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
    
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
        if(head == NULL)
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
    // node n1 (1);
    // node n2 (2);
    // node n3 (3);
    // node n4 (4);
    // node n5 (5);

    // node *head = &n1;
    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    // cout<< checkLength(head);
    cout << checkLength(head);

    return 0;
}