#include <bits/stdc++.h>
//#include"queue_using_array.h"
//#include "dynamic_array_using_queue.h"
//#include "practicequeue2.h"
#include "queue_using_ll.h"

using namespace std;

int main()
{
    //queue_using_array<int> q(5);
    queuef <int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.get_size() << endl;
    q.dequeue();
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.get_size() << endl;
    cout << q.front() << endl;
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout << q.get_size() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.front() << endl;
    cout << q.get_size() << endl;

    return 0;
}