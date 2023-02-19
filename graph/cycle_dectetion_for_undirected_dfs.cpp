#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n)

class solution
{
public:
    bool dfs_ka_cycleFucker(int node, int parent, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = true;
        for (auto it : adj[node])
        {
            if (it == parent)
            {
                continue;
            }
            if (vis[it])
            {
                return true;
            }
            if (dfs_ka_cycleFucker(it, node, vis, adj))
            {
                return true;
            }
           
        }
         return false;
    }

    bool isCycle(int v, vector<int> adj[])
    {
        // vector e 0 vore dilam
        vector<int> vis(v + 1, 0);
        for (int i = 1; i <= v; i++)
        {
            if (!vis[i])
            {
                if (dfs_ka_cycleFucker(i, -1, vis, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int n, m;
    cout << "Enter the node size and vertex number : ";
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {

        int u, v;
        cout << "Enter connections : ";
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solution s1;
    bool fAns = s1.isCycle(n, adj);
    if (fAns == true)
    {
        cout << "Cycle detected!";
    }
    else
    {
        cout << "No cycle detected!";
    }

    return 0;
}