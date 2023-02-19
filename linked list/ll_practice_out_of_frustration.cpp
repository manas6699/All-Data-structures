#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL;

    while (data != -5)
    {
        node *newnode = new node(data);
        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;

    }
    
}

int main()
{

    node *head = takeinput();
    print(head);
    return 0;
}