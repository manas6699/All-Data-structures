#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n)

// 1st step : write down all the degrees of all the nodes
// 2nd step : take a queue
// reduce the degree by 1

// khan's Algorithm

class solution
{
public:
    vector<int> TopoSort(int n, vector<int> adj[])
    {
        queue<int> q1;
        vector<int> degree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                degree[it]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 0)
            {
                q1.push(i);
            }
        }

        vector<int> topo;
        // bfs algo
        while (!q1.empty())
        {
            int node = q1.front();
            q1.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                degree[it]--;
                if (degree[it] == 0)
                {
                    q1.push(it);
                }
            }
        }

        return topo;
    }
};

int main()
{
    int n, m;
    cout << "Enter the node size and vertex number : ";
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {

        int u, v;
        cout << "Enter connections : ";
        cin >> u >> v;

        adj[u].push_back(v);
    }
    solution s1;
    cout << "Your array in topological sorted order is : " << endl;
    vector<int> ans = s1.TopoSort(n, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
// 6 6 5 0 5 2 2 3 3 1 4 1 4 0