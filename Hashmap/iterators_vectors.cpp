#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    vector<int> :: iterator it1;
    it1 = v1.begin();
    while (it1 != v1.end())
    {
        cout <<"Iterate using vector : " << *it1 << endl;
        it1++;
    }
    
    

    return 0;
}