#include <bits/stdc++.h>
using namespace std;

class solution
{

public:
    bool checkForCycle(int s, int v, vector<int> adj[], vector<int> &vis)
    {
        // bfs manei queue , tai akta queue banalam
        queue<pair<int, int>> q1;

        vis[s] = true;
        q1.push({s, -1});

        while (!q1.empty())
        {
            int node = q1.front().first;
            int pre = q1.front().second;
            q1.pop();

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    q1.push({it, node});
                }
                else if (pre != it)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int v, vector<int> adj[])
    {
        bool ans;
        vector<int> vis(v + 1, 0);
        for (int i = 1; i <= v; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, v, adj, vis))
                {
                    // cout << "There is a cycle detected!";
                    ans = true;
                }
                else
                {
                    // cout << "No cycle detected!";
                    ans = false;
                }
            }
        }

        // if (ans == true)
        // {
        //     cout << "There is a cycle detected!";
        // }
        // else
        // {
        //     cout << "No cycle detected!";
        // }
        return ans;
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