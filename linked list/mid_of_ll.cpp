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

int mid_of_ll(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
       
        
        slow = slow->next;
        fast = fast->next->next;


    }
    return slow->data;
}

int main()
{
    node *head = take_inp();
    print(head);

    cout << mid_of_ll(head);
    

    return 0;
}