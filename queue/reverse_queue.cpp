#include <bits/stdc++.h>
using namespace std;

void print_queue(queue<int> q1)
{
    if (q1.size() != 0)
    {
        // int temp = q1.front();
        // q1.pop();
        // print_queue();
        // cout << temp << " ";
        // q1.push(temp);
        int y = q1.front();
        cout << y << " ";
        q1.pop();
        print_queue(q1);
    }
}
void reverse_queue(queue<int> q1)
{

    if (q1.empty())
    {
        return;
    }
    int x = q1.front();
    q1.pop();

    reverse_queue(q1);
    cout << x << " ";
}

int main()
{
    queue<int> q1;

    q1.push(4);
    q1.push(3);
    q1.push(2);
    q1.push(1);

    cout << "Before reversing ";
    print_queue(q1);
    cout << endl;

    // cout << "Before reversing " ;
    // print_queue();

    cout << "After reversing : ";
    // print_queue();
    reverse_queue(q1);
    // print_queue();
    // cout << endl;
    return 0;
}