#include <bits/stdc++.h>
using namespace std;

class priorityQueue
{
    vector<int> pq;

public:
    priorityQueue()
    {
    }
    bool is_empty()
    {
        return pq.size() == 0;
    }
    int get_size()
    {
        return pq.size();
    }
    int get_min()
    {
        if (is_empty())
        {
            return 0;
        }
        return pq[0];
    }
    void insert(int element)
    {
        pq.push_back(element);
        int child_index = pq.size() - 1;
        while (child_index > 0)
        {
            int parent_index = (child_index - 1) / 2;
            if (pq[child_index] < pq[parent_index])
            {
                swap(pq[child_index], pq[parent_index]);
            }
            else
            {
                break;
            }
            child_index = parent_index;
        }
    }
    int remove_min()
    {
        if (is_empty())
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // down heapify
        int pi = 0;
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;
        while (lci < pq.size())
        {
            int mi = pi;
            if (pq[mi] > pq[lci])
            {
                mi = lci;
            }
            if ((rci < pq.size()) && (pq[rci] < pq[mi]))
            {
                mi = rci;
            }
            if (mi == pi)
            {
                break;
            }

            swap(pq[mi], pq[pi]);
            pi = mi;
            lci = 2 * pi + 1;
            rci = 2 * pi + 2;
        }

        return ans;
    }
};

int main()
{

    priorityQueue manas;

    manas.insert(100);
    manas.insert(10);
    manas.insert(15);
    manas.insert(4);
    manas.insert(17);
    manas.insert(21);
    manas.insert(61);

    cout << "smallest value : " << endl;
    while (!manas.is_empty())
    {
        cout << manas.remove_min() << " ";
        // manas.remove_min();
    }

    return 0;
}
