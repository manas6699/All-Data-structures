#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Hi" << endl;
    vector<char> v1;
    string s1 = "lord";
    
    
    for (int i = 0; i < s1.size(); i++)
    {
         v1.push_back(s1[s1.size() - i - 1]); 
    }
    cout << "Size of stringis : "<< s1.size() << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    
    return 0;
}