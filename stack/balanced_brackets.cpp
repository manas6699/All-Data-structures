#include <bits/stdc++.h>
using namespace std;

void balanced_bracket(string s)
{
    stack<char> str;
    int n = s.size();
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            str.push(s[i]);
        }

        if (s[i] == ')')
        {
            if (str.top() == '(')
            {
                str.pop();
            }
            else
            {
                ans = false;
                break;
            }
            
        }
        if (s[i] == '}')
        {
            if (str.top() == '{')
            {
                str.pop();
            }
            else
            {
                ans =false;
                break;
            }
            
        }
        if (s[i] == ']')
        {
            if (str.top() == '[')
            {
                str.pop();
            }
            else
            {
                ans =false;
                break;
            }
            
        }
        
        
    }

    if (ans == true)
    {
        cout << "valid!";
    }
    else
    {
        cout << "invalide!";
    }  
    
}

int main()
{
    string s1;
    cout << "Enter a string : ";
    cin >> s1;

    balanced_bracket(s1);

    return 0;
}