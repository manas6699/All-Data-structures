#include <bits/stdc++.h>
using namespace std;

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

    return 0;
}