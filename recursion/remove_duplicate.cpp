#include <bits/stdc++.h>
using namespace std;

void removeduplicate(char s[]){
    if (s [0] == '\0')
    {
        return;
    }
    if(s [0] == s[1]){
        cout << s[0];
        // while (s[0] == s[1])
        // {
        //     
        // }
        
        
    }
    removeduplicate(s + 1);
}

int main()
{
    char str[100];
    cin >> str;

    removeduplicate(str);

    return 0;
}