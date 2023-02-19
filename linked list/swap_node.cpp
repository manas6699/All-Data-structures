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

node *gandu(node *head, int m, int n)
{
    node *temp1 = head;
    node *temp2 = head;
    node *temp3 = head;
    node *temp4 = head;

    for (int i = 0; i < n + 1; i++)
    {
        temp4 = temp4->next;
    }
    node *t = temp4;

    for (int i = 0; i < m; i++)
    {
        temp1 = temp1->next;
    }
    node *n1 = temp1;
    for (int i = 0; i < n; i++)
    {
        temp2 = temp2->next;
    }
    node *n2 = temp2;
    for (int i = 0; i < m - 1; i++)
    {
        temp3 = temp3->next;
    }
    temp3->next = n2;
    n2->next = n1;
    n1->next = temp4;

    //
    // n1->next = temp4;
    temp4->next = t->next;
    t = t->next;

    //temp4->next = NULL;

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
    cout << "your linked-list Members are : ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// inputs :                       1 2 3 4 5 6 7 8 9 -1

int main()
{
    node *head = take_inp();
    print(head);

    cout << "Enter m & n : ";
    int m, n;
    cin >> m >> n;

    cout << "after swaping, ";
    node *g = gandu(head, m, n);
    print(g);
    //baaki_ka_maal(head ,m , n);
    return 0;
}