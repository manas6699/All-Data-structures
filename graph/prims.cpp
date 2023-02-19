#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void prims_brute(int n, vector<pair<int, int>> adj[])
    {
        // time complexituy > 0(n2)
        int parent[n];
        int key[n];
        bool mstSet[n];

        for (int i = 0; i < n; i++)
        {
            key[i] = INT_MAX;
            parent[i] = -1;
            mstSet[i] = false;
        }
        key[0] = 0;

        for (int count = 0; count < n - 1; count++)
        {
            int mini = INT_MAX, u;

            for (int v = 0; v < n; v++)
            {
                if (mstSet[v] == false && key[v] < mini)
                {
                    mini = key[v], u = v;
                }
            }
            mstSet[u] = true;

            for (auto it : adj[u])
            {
                int v = it.first;
                int weight = it.second;

                if (mstSet[v] == false && weight < key[v])
                {
                    parent[v] = u, key[v] = weight;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            cout << "MST : " << parent[i] << "-" << i << endl;
        }
    }

    void prims_efficient(int n, vector<pair<int, int>> adj[])
    {
        // time complexituy > 0(n(log(n))
        int parent[n];
        int key[n];
        bool mstSet[n];

        for (int i = 0; i < n; i++)
        {
            key[i] = INT_MAX;
            mstSet[i] = false;
            parent[i] = -1;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        key[0] = 0;
        parent[0] = -1;
        pq.push({0, 0});

        for (int count = 0; count < n - 1; count++)
        {
            int u = pq.top().second;
            pq.pop();

            mstSet[u] = true;

            for (auto it : adj[u])
            {
                int v = it.first;
                int weight = it.second;

                if (mstSet[v] == false && weight < key[v])
                {
                    parent[v] = u;
                    pq.push({key[v], v});
                    key[v] = weight;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            cout << "MST : " << parent[i] << "-" << i << endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "Enter the node size and vertex number : ";
    cin >> n >> m;

    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {

        int u, v, wt;
        cout << "Enter connections & weights : ";
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        // for undirected grph
        adj[v].push_back({u, wt});
    }
    solution s1;
    s1.prims_brute(n, adj);

    cout << endl << endl;
    s1.prims_efficient(n , adj);
    return 0;
}
