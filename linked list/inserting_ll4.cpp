#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

node *take_inp()
{
    cout << "Enter linked list data members \n";
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

void print(node *head)
{
    cout << "Elements of the linked lists are :- ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *insert_node(node *head , int i , int data)
{
    node *newnode = new node(data);
    node *temp = head;
    int count = 0;

    if(i == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }

    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    if(temp != NULL)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}


int main()
{
    node *head = take_inp();
    print(head);

    cout << "Enter the podition and the data to insert node\n";
    int i , data;
    cin >> i >> data;

    head = insert_node(head , i , data);
    print(head);

    return 0;
}