#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n)

class solution
{
public:
    bool cBh(int snode, vector<int> adj[], vector<int> &color)
    {
        queue<int> q1;
        q1.push(snode);
        color[snode] = 1;
        while (!q1.empty())
        {
            // babar bal chire ati badh bokachoda
            int node = q1.front();
            q1.pop();

            for (auto it : adj[node])
            {
                if (color[it] == -1)
                {
                    color[it] = 1 - color[node];
                    q1.push(it);
                }
                else if (color[it] == color[node])
                {
                    return false;
                }
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
                if (!cBh(i, adj, color))
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

// #include <bits/stdc++.h>
// using namespace std;

// bool bipartiteBfs(int src, vector<int> adj[], int color[])
// {
//     queue<int> q;
//     q.push(src);
//     color[src] = 1;
//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();

//         for (auto it : adj[node])
//         {
//             if (color[it] == -1)
//             {
//                 color[it] = 1 - color[node];
//                 q.push(it);
//             }
//             else if (color[it] == color[node])
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// bool checkBipartite(vector<int> adj[], int n)
// {
//     int color[n];
//     memset(color, -1, sizeof color);
//     for (int i = 0; i < n; i++)
//     {
//         if (color[i] == -1)
//         {
//             if (!bipartiteBfs(i, adj, color))
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> adj[n];
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     if (checkBipartite(adj, n))
//     {
//         cout << "yes";
//     }
//     else
//     {
//         cout << "No";
//     }
//     return 0;
// }