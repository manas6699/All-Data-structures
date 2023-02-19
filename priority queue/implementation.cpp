#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue <int> pq;
    pq.push(10);
    pq.push(80);
    pq.push(90);
    pq.push(30);
    pq.push(20);

    cout << "Size : " << pq.size() << endl;
    //pq.swap(pq.top() , 100);
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    

    return 0;
}