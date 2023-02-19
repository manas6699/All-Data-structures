/* problem is unsolved due to lack of understanding 
the fact of what should be used, stack or queue.*/

#include <bits/stdc++.h>
using namespace std;

void check_r(string s1)
{
    stack<char> str;
    int size = s1.size();
    for (int i = 0; i < size; i++)
    {
        if (s1[i] == ')')
        {
            str.push(s1[i]);
            // cout << s1[i] << endl;
            break;
        }
        cout << s1[i] << endl;
    }
    
    // number of brackets counting
    int bc = 0;
    for (int i = 0; i < str.size(); i++)
    {

        if (s1[i] == '(')
        {
            bc++;
        }
    }
    cout << "number of brackets are " << bc << endl;
    int c2 = 0;
    for (int i = 0; i < bc; i++)
    {

        if (s1[i] != '(')
        {
            c2++;
            str.pop();
        }
        else
        {
            break;
        }
    }

    cout << c2 << endl;
    // true = 1 , false = 0 ;
    if (c2 == 0)
    {
        cout << "string is not reduntant\n";
    }
    else
    {
        cout << "string is reduntant\n";
    }
}

int main()
{
    string s1;
    cin >> s1;

    //cout << check_r(s1);
    check_r(s1);
    return 0;
}