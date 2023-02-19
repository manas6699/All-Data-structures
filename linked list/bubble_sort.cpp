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

node *bubble_sort(node *head, int count)
{
    int n = count - 1;

    while (n--)

    {
        node *prev = NULL;
        node *cur = head;
        while (cur->next != NULL)
        {
            if (cur->data >= cur->next->data)
            {

                if (prev == NULL)
                {
                    //first node
                    node *nxt = cur->next;
                    cur->next = nxt->next;
                    nxt->next = cur;
                    prev = nxt;
                    head = prev;
                }

                // main logic of bubble sort
                else
                {

                    node *nxt = cur->next;
                    prev->next = nxt;

                    //problem solved! very very tricky
                    cur->next = nxt->next;
                    nxt->next = cur;
                    prev = nxt;
                }
            }
            else
            {

                prev = cur;
                cur = cur->next;
            }
        }
    }

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

// inputs :                       9 8 7 6 5 4 3 2 1 -1

int main()
{
    node *head = take_inp();
    print(head);

    int k = checkLength(head);

    node *g = bubble_sort(head, k);
    print(g);

    return 0;
}