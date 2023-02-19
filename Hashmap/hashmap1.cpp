#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> ourmap;

    // insert
    pair<string, int> p1("abc", 1);
    ourmap.insert(p1);
    ourmap["def"] = 300;

    // access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;
    cout << ourmap.at("def") << endl;
    // cout << ourmap.at("ghi") << endl;
    // cout << ourmap["ghi"] << endl;

    // check presence
    if (ourmap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
    else
    {
        cout << "ghi is not present" << endl;
    }

    // size
    cout << "Size of hashmap is : " << ourmap.size() << endl;

    // erase
    ourmap.erase("abc");
    cout << "Size of hashmap is : " << ourmap.size() << endl;

    return 0;
}