#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;


node *insert_node_recursively(node *head , int data , int i)
{
    node *temp = head;
    node *newnode = new node(data);
    if(temp == NULL)
    {
        return newnode;
    }
    if(i == 0)
    {
        newnode->next = temp;
        temp = newnode;
        return temp;
    }
    head->next = insert_node_recursively(head->next , data , i - 1);
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
    int data , i;
    cout << "Enter data & position : \n";
    cin >> data >> i;
    head = insert_node_recursively(head , data , i);
    print(head);
    

    return 0;
}