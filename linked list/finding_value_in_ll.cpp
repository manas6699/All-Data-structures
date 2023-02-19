#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

void find_value(node *head , int n)
{
    int count = 0;
    node *temp = head;
    while (temp->data != n)
    {
        count++;
        temp = temp->next;
    }
    cout <<count;
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
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *head = take_inp();
    print(head);
    int n;
    cout << "enter the value you want to find : ";
    cin >> n;

    find_value(head , n);

    return 0;
}