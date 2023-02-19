#include <iostream>
#include "stack_using_array.cpp"
using namespace std;

int main()
{

    stackUsingArray s(100);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;


    return 0;
}