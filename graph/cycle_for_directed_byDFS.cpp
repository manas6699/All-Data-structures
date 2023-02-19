// babar bichi hoyeche bokachoda

#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n)

class solution
{
public:
    bool dfs_ka_cycleFucker(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfsVis)
    {
        // 1 means true
        vis[node] = 1;
        dfsVis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfs_ka_cycleFucker(it, vis, adj, dfsVis))
                {
                    return true;
                }
            }
            else if (dfsVis[it])
            {
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }

    bool isCycle(int v, vector<int> adj[])
    {
        // vector e 0 vore dilam
        vector<int> vis(v, 0);
        vector<int> dfsVis(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (dfs_ka_cycleFucker(i, vis, adj, dfsVis))
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

    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {

        int u, v;
        cout << "Enter connections : ";
        cin >> u >> v;

        adj[u].push_back(v);
        
    }
    solution s1;
    if(s1.isCycle(n , adj))
    {
        cout << "Cycle detected!";
    }
    else
    {
        cout << "Cycle not dectected!";
    }

    return 0;
}