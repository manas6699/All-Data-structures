#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<int> MySol(int n, vector<int> adj[])
    {
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
        // adj[v].push_back(u);
    }
    solution s1;
    vector<int> ans = s1.MySol(n, adj);
    return 0;
}
