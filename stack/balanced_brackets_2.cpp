#include <bits/stdc++.h>
using namespace std;

void balanced_bracket2(string s)
{
    stack<char> str;
    int n = s.size();
    if (n % 2 == 0)
    {
        cout << "It's balanced!\n";
    }
    else
    {
        cout << "It's not balanced\n";
    }
    
    
}

int main()
{
    string s1;
    cout << "Enter a string : ";
    cin >> s1;

    balanced_bracket2(s1);

    return 0;
}