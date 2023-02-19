#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

node *take_inp_ka_maa_ka_vosra()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        //prthom node ta check koar jonno
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

node *insert_node(node *head, int i, int data)
{
    node *newnode = new node(data);
    int count = 0;
    node *temp = head;

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
    if (temp != NULL)
    {
        node *a = temp->next;
        temp->next = newnode;
        newnode->next = a;
    }
    return head;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    node *head = take_inp_ka_maa_ka_vosra();
    print(head);
    int i, data;
    cin >> i >> data;

    head = insert_node(head, i, data);
    print(head);

    return 0;
}