#include <bits/stdc++.h>
using namespace std;

int allPossibleArrays(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    string reducedArray = input.substr(1);
    int counterString = allPossibleArrays(reducedArray, output);

    for (int i = 0; i < counterString; i++)
    {
        output[i + counterString] = input[0] + output[i];
    }
    return 2 * counterString;
}

int main()
{
    string input;
    cin >> input;
    string *output = new string[1000];

    int n = allPossibleArrays(input, output);
    for (int i = 0; i < n; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}