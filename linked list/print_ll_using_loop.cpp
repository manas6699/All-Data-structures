#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    // while (head != NULL)
    // {
    //     cout << head->data << " ";
    //     head = head->next;
    // }
}

// statically allocated
int main()
{
    node n1(1);
    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);

    node *head = &n1;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);
    print(head);
    return 0;
}