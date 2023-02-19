// pata nehi yr keya babsir bana diya hu

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int , int>> adj[])
    {
        // 1 means true
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it.first])
            {
                findTopoSort(it.first, vis, st, adj);
            }
        }
        st.push(node);
    }

    void MySol(int src ,int n, vector<pair<int, int>> adj[])
    {
        int vis[n] = {0};
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                findTopoSort(i , vis , st , adj);
                
            }
            
        }

        vector<int> dist(n , INT_MAX);
        dist[src] = 0;


        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (dist[node] != INT_MAX)
            {
                for(auto it : adj[node])
                {
                    if (dist[node] + it.second < dist[it.first])
                    {
                        dist[it.first] = dist[node] + it.second;
                    }
                    
                }
            }
            
        }
        
        for (int i = 0; i < n; i++)
        {
            (dist[i] == INT_MAX) ? cout << "Not Found!" : cout << dist[i] << ' ';
        }
        
        
    }
};

int main()
{
    int n, m;
    cout << "Enter the node size and vertex number : ";
    cin >> n >> m;

    vector<pair<int , int>> adj[n];
    for (int i = 0; i < m; i++)
    {

        int u, v , wt;
        cout << "Enter connections and weights : ";
        cin >> u >> v >> wt;

        adj[u].push_back({v , wt});
        // for undirected grph
        // adj[v].push_back(u);
    }
    solution s1;
    s1.MySol(0 , n, adj);
    return 0;
}
