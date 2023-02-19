#include <bits/stdc++.h>
using namespace std;

void match_word(vector<string> v1, string w)
{
    int count = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        
    }
}

int main()
{
    int n;
    cin >> n;
    string arr[n] = {};
    vector<string> v1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int var = 0;
    string word;
    cin >> word;
    for (int i = 0; i < n; i++)
    {
        if (word.size() <= arr[i].size())
        {
            v1.push_back(arr[i]);
            var++;
        }
        else
        {
            continue;
        }
    }

    match_word(v1, word);

    return 0;
}