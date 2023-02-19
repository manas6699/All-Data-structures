#include <bits/stdc++.h>
//#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << s.size() << endl;
    s.pop();
    cout << s.size() << endl;

    return 0;
}