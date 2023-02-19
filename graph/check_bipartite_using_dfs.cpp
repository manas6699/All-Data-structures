#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n)

class solution
{
public:
    bool checkBipartiteDfs(int node, vector<int> adj[], vector<int> &color)
    {
        if (color[node] == -1)
        {
            color[node] = 1;
        }
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                if (!checkBipartiteDfs(it, adj, color))
                {
                    return false;
                }
            }

            else if (color[it] == color[node])
            {
                return false;
            }
        }
        return true;
    }

    bool check_bipartite(int n, vector<int> adj[])
    {
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if ((color[i] == -1))
            {
                if (!checkBipartiteDfs(i, adj, color))
                {
                    return false;
                }
            }
        }
        return true;
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
        adj[v].push_back(u);
    }
    solution s1;
    bool fAns = s1.check_bipartite(n, adj);
    if (fAns == true)
    {
        cout << "It's a bipartite graph";
    }
    else
    {
        cout << "It's not a bipartite graph";
    }

    return 0;
}