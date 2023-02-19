#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n)

class solution
{
public:

    
    void helper(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
    {
        // 1 means true
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
            helper(it, vis, st, adj);
                
            }
        }
        st.push(node);
    }

    vector<int> TopoSort(int n, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                helper(i, vis, st, adj);
            }
        }
        vector<int> topo;
        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
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
    vector<int> ans = s1.TopoSort(n , adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
}

