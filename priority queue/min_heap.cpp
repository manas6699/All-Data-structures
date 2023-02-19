#include <bits/stdc++.h>
using namespace std;
class priority_queu
{
    vector<int> pq;

public:
    priority_queu()
    {
    }
    bool is_empty()
    {
        return (pq.size() == 0);
    }

    int size()
    {
        return pq.size();
    }

    int smallest()
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
            if (pq[parent_index] > pq[child_index])
            {
                swap(pq[parent_index], pq[child_index]);
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
            int min_index = pi;
            if (pq[lci] < pq[min_index])
            {

                min_index = lci;
                // swap(pq[lci] , pq[min_index]);
            }
            if ((rci < pq.size()) && (pq[rci] < pq[min_index]))
            {
                min_index = rci;
                // swap(pq[rci] , pq[min_index]);
            }
            if (min_index == pi)
            {
                break;
            }

            swap(pq[pi], pq[min_index]);

            pi = min_index;
            lci = 2 * pi + 1;
            rci = 2 * pi + 2;
        }
        return ans;
    }
};

int main()
{
    priority_queu manas;

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
        
    }

    return 0;
}