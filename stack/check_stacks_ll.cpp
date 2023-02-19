#include <bits/stdc++.h>
#include "stacks_of_ll.cpp"
using namespace std;

int main()
{
    stack_use<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    

    cout << s1.top() << endl;
     s1.pop();

    s1.push(60);
    s1.push(70);
    s1.push(80);
    s1.push(90);
    s1.push(100);
    s1.push(200);
    s1.push(300);

    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    cout << s1.sizet() << endl;

    s1.push(400);
    s1.push(500);
    s1.push(600);

    s1.pop();
    cout << s1.top() << endl;

    return 0;
}