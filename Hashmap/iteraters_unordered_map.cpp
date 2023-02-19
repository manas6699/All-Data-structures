#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> m1;
    m1["abc"] = 1;
    m1["abc1"] = 2;
    m1["abc2"] = 3;
    m1["abc3"] = 4;
    m1["abc4"] = 5;

    unordered_map<string, int>::iterator it;
    it = m1.begin();
    while (it != m1.end())
    {
        cout << "Key : " << it->first << " "
             << "Value : " << it->second << endl;
        it++;
    }

    //      find :

    unordered_map<string, int>::iterator it2;
    it2 = m1.find("abc3");

    cout << "Find index : " << it2->first << " " << it2->second << endl;

    //      erase :
    m1.erase(it2);
    cout << "After erasing : " << endl;
    it = m1.begin();
    while (it != m1.end())
    {
        cout << "Key : " << it->first << " "
             << "Value : " << it->second << endl;
        it++;
    }

    return 0;
}