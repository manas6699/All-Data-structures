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

node *remove_duplicate(node *head)
{
    cout << "After removing duplicates ";
    node *temp = head;
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node *t1 = temp;
    node *t2 = temp->next;

    while (t2 != NULL)
    {
        
        if(t1->data !=  t2->data)
        {
            t1->next = t2;

            t1 = t1->next;
            t2 = t2->next;
        }
        else
        {
            t2 = t2->next;
        }
    }
    t1->next = t2;
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

    remove_duplicate(head);
    print(head);

    return 0;
}