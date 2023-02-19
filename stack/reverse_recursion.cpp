#include <bits/stdc++.h>
using namespace std;

stack<int> s1;

void insert_at_the_bottom(int x)
{
    if (s1.size() == 0)
    {
        s1.push(x);
    }
    else
    {
        int a = s1.top();
        s1.pop();

        insert_at_the_bottom(x);
        s1.push(a);
    }
}

void reverse_recursion(stack<int> s1)
{

    if (s1.size() == 1)
    {
        cout << s1.top();
    }

    int x = s1.top();
    s1.pop();

    reverse_recursion(s1);
    insert_at_the_bottom(x);
}

int main()
{

    s1.push(400);
    s1.push(3);
    s1.push(2);
    s1.push(12);
    s1.push(13);
    s1.push(14);
    s1.push(51);
    s1.push(51);
    s1.push(16);
    s1.push(121);
    s1.push(155);
    s1.push(166);
    s1.push(14);
    s1.push(15);
    s1.push(199);
    s1.push(123);

    cout << s1.top() << endl;
    reverse_recursion(s1);
    cout << s1.top() << endl;

    return 0;
}