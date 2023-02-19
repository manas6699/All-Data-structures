#include <bits/stdc++.h>
#include "node.cpp"

using namespace std;

int main()
{
    node n1(580);
    // print 1st element using head
    node *head = &n1;
    node n2(7850);

    n1.next = &n2;

    //cout << n1.data << " " << n2.data;
    cout << head->data;
    return 0;
}