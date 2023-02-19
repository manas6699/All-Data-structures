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



node *delete_node(node *head , int i)
{
    int count = 0;
    node *temp = head;

    if(i == 0)
    {
        node *temp2 = head;
        head = head->next;
        delete temp2;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    if(temp != NULL)
    {
        node *a = temp->next;
        node *b = a->next;
        temp->next = b;
        delete a;
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

int main()
{
    node *head = take_inp();
    print(head);
    int i;
    cout << "Enter the position where you want to delete : ";
    cin >> i;
    head = delete_node(head , i);
    print(head);

    return 0;
}