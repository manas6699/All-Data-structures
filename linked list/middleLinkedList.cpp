#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

node* middleLinkedList(node* head)
{
    int size = 0;
    node* temp = head;
    while (head != NULL)
    {
        head = head->next;
        size++;
    }
    for (int i = 0; i < size / 2; i++)
    {
        temp = temp->next;
    }

    return temp;
    
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

    
    cout << "The middle node is : " << middleLinkedList(head)->data << endl;
   

    return 0;
}