#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<int> MySol(int n, vector<int> adj[])
    {
        vector<int> v1(n, INT_MAX);
        queue<int> q1;
        int start = 0;
        v1[start] = 0;
        q1.push(start);

        while (!q1.empty())
        {
            int node = q1.front();
            q1.pop();

            for (auto it : adj[node])
            {
                if (v1[node] + 1 < v1[it])
                {
                    v1[it] = v1[node] + 1;
                    q1.push(it);
                }
            }
        }

        return v1;
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
        // for undirected grph
        adj[v].push_back(u);
    }
    solution s1;
    vector<int> ans = s1.MySol(n, adj);
    int requiredDistanceNode;
    cout << "Enter the required destiny node : " << endl;
    cin >> requiredDistanceNode;
    cout << "Distance is : " << ans[requiredDistanceNode];
    return 0;
}

// 6 6 0 1 1 2 2 3 3 4 3 5 0 5