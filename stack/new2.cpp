#include <bits/stdc++.h>
#include "stacks_using_template.cpp"
using namespace std;

int main()
{
    stack_use<char> s;
    s.push(100);
    s.push(101);

    cout << s.top() << endl;
    cout << s.size() << endl;

    s.push(102);
    s.push(104);
    //s.push(104);

    cout << s.top() << endl;
    cout << s.size() << endl;

    s.push(105);
    s.push(106);

    cout << s.top() << endl;
    cout << s.size() << endl;

    return 0;
}