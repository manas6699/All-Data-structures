#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

void print (node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    
}
//dynamically print the linked list using while loop
int main()
{
    node *n1 = new node(10);
    node *n2 = new node(20);
    node *n3 = new node(30);
    node *n4 = new node(40);
    node *n5 = new node(50);
    
    node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    print(head);

    return 0;
}