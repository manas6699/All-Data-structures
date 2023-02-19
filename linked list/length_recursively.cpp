#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

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

int check_len(node *head)
{
    
    int count = 0;
    node *temp = head;
    if (temp == NULL)
    {
        return 0;
        
    }
    return 1 + check_len(temp->next);
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *head = take_inp();
    print(head);
    cout << check_len(head);

    return 0;
}