#include <bits/stdc++.h>
using namespace std;

int lengthofstring(char s[]){
    if (s[0] == '\0'){
        return 0;

    }
    
     int v = lengthofstring(s + 1);
     return 1 + v;

}

int main()
{
    char s[100];
    cin >> s;

    int m = lengthofstring(s);
    cout << m << endl;

    return 0;
}