#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

node *takeinp_better()
{
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


    void print(node * head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }

    int main()
    {
        node *head = takeinp_better();
        print(head);

        return 0;
    }