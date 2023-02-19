#include <bits/stdc++.h>
using namespace std;

void replace(char s[], char a, char b)
{
    if (s[0] == '\0')
    {
        return;
    }
    if (s[0] == a)
    {
        //replace(s + 1, a, b);
        s[0] = b;
    }
    
    replace(s + 1, a, b);
}

int main()
{
    char str[100];
    cout << "Enter String\n";
    cin >> str;

    char a, b;
    cout << "Enter two characters\n";
    cin >> a >> b;

    replace(str, a, b);
    cout << str;

    return 0;
}