#include <bits/stdc++.h>
using namespace std;

class node
{
    public :
    int data;
    node *next;

    node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};


int checkLength(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}



node* apend_node(node *head, int n)
{
    node* temp = head;
    node* temp2 = head;
    
    for (int i = 0; i < n; i++)
    {
        temp = temp->next;
    }

    while (temp->next != NULL)
    {
        temp2 = temp2->next;
        temp = temp->next;

    }
    
    temp->next = head;
    head = temp2->next;
    
    temp2->next = NULL;
   // head->next = temp2;
    return head;
//      1 2 3 4 5 -1
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

    int d = checkLength(head);
    cout << "The length of your linked list is " << d << endl;
    int n;
    cout << "Enter the value you wanna append : ";
    cin >> n;

    //append_ll(head, n, d);
    node* result = apend_node(head , n);
    print(result);

    return 0;
}