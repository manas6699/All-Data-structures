#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q1;
    q1.push (10);
    cout << q1.empty() << endl;
    q1.push(20);
    q1.push(30);
    q1.push(40);

    cout << q1.front() << endl;
    q1.push(50);
    q1.push(60);
    q1.push(70);
    q1.pop();
    cout << q1.size() << endl;
    cout << q1.front() << endl;


    return 0;
}