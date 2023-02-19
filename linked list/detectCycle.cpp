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

bool detectCycle(node* &head)
{
    map<node*, int> m;
    node *temp = head;
    
    while(temp != NULL)
    {
        m[temp]++;
        temp = temp->next;

    }
    if(m.empty()){
        return NULL;
    }

    for(auto i : m){
        if(i.second > 1){
            return true;
        }
    }
    return false;

    
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

    if(detectCycle(head)){
        cout << "Cycle is present in the linked list";
    }
    else{
        cout << "Cycle is not present in the linked list";
    }

    return 0;
}