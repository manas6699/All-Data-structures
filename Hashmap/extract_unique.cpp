#include <bits/stdc++.h>
using namespace std;

void extract_unique(string s1)
{
    vector<int> output;
    string s2;
    unordered_map<int, bool> seen;
    for (int i = 0; i < s1.size(); i++)
    {
        if (seen.count(s1[i]) > 0)
        {
            continue;
        }
        seen[s1[i]] = true;

        s2 += s1[i];
    }

    cout << s2;
}

int main()
{
    cout << "Enter the string : ";

    string s1;
    cin >> s1;

    extract_unique(s1);

    return 0;
}