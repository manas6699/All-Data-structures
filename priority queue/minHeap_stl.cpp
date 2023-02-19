#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int ,vector<int> , greater <int> > manas;

    manas.push(100);
    manas.push(10);
    manas.push(15);
    manas.push(4);
    manas.push(17);
    manas.push(21);
    manas.push(61);

    cout << "smallest value : " << endl;
    while (!manas.empty())
    {
        cout << manas.top() << " ";
        manas.pop();
        
    }


    return 0;
}