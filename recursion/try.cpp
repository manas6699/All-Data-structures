// #include <bits/stdc++.h>
// using namespace std;

// bool arnab_er_bichi_choto(char s[])
// {
//     if (s[0] == 'a')
//     {
//         if(s[1] == 'b' && s[2] == 'b')
//         {
//             return true;
//             arnab_er_bichi_choto(s.)
//         }
        
//     }
// }

// int main()
// {
//     char manas[100];
//     cin >> manas;

//     return 0;
// }

#include <iostream>

using namespace std;

bool fun(string output)
{
    if (output.size() == 0)
    {
        return false;
    }

    if (output[0] == 'a')
    {
        if (output[1] == 'b' && output[2] == 'b')
        {
            return true;
            
        }
        return fun(output.substr(1));
    }
    else
    {
        return false;
    }
}

int main()
{
    string str;

    cout << "Enter your String : ";
    cin >> str;

    if (fun(str))
    {
        // return true;
        cout << "True";
    }
    else
    {
        // return false;
        cout << "False";
    }

    return 0;
}