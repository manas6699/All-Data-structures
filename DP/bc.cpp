#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1;
    getline(cin, s1);
    int n;
    cin >> n;
    int string_size = s1.size();
    vector<char> v1;
    for (int i = 0; i < string_size; i++)
    {
        v1.push_back(s1[i]);
    }

    while (v1.size() != 0)
    {
        if (n < v1.size())
        {
            for (int i = 0; i < n; i++)
            {
                cout << v1[i];
                v1.pop_back();
            }
            cout << " ";
        }
        
        else
        {
            for (int i = 0; i < v1.size(); i++)
            {
                cout << v1[i];
            }
            
        }
        
    }

    return 0;
}
