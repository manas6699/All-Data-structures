#include <bits/stdc++.h>
using namespace std;

void dfs_helper(int n, vector<int> &vis, vector<int> adj[], vector<int> &dfs)
{
    dfs.push_back(n);
    vis[n] = 1;

    for (auto it : adj[n])
    {
        if (!vis[it])
        {
            dfs_helper(it, vis, adj, dfs);
        }
    }
}

vector<int> dfs_of_graph(int v, vector<int> adj[])
{
    vector<int> dfs;
    vector<int> vis(v + 1, 0);

    for (int i = 1; i <= v; i++)
    {
        if (vis[i] == 0)
        {
            dfs_helper(i, vis, adj, dfs);
        }
    }
    return dfs;
}

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

    vector<int> v1 = dfs_of_graph(n, adj);
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    return 0;
}