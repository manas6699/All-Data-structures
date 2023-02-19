// uses khan's algorithm
// not recommended in the interview

#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n)

class solution
{
public:
    bool isCycle(int n, vector<int> adj[])
    {
        // queue<int> q1;
        // vector<int> degree(n, 0);
        // for (int i = 0; i < n; i++)
        // {
        //     for (auto it : adj[i])
        //     {
        //         degree[it]++;
        //     }
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     if (degree[i] == 0)
        //     {
        //         q1.push(i);
        //     }
        // }

        // vector<int> topo;
        // int count = 0;
        // while (!q1.empty())
        // {
        //     int node = q1.front();
        //     q1.pop();
        //     count++;
        //     topo.push_back(node);
        //     for (auto it : adj[node])
        //     {
        //         degree[it]--;
        //         if (degree[it] == 0)
        //         {
        //             q1.push(it);
        //         }
        //     }
        // }
        // if (count == n)
        // {
        //     return false;
        // }
        // return true;
        queue<int> q;
        vector<int> ndegree(n , 0);
        for (int i = 0; i < n; i++)
        {
            for(auto it : adj[i])
            {
                ndegree[it]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (ndegree[i] == 0)
            {
                q.push(i);
            }
            
        }

        int count = 0;
        while (!q.empty())
        {
            int node1 = q.front();
            q.pop();
            count++;
            for(auto it : adj[node1])
            {
                ndegree[it]--;
                if (ndegree[it] == 0)
                {
                    q.push(it);
                }
                
            }
        }
        
        if (count == n)
        {
            return false;
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
    }
    solution s1;
    if (s1.isCycle(n, adj))
    {
        cout << "Cycle detected!";
    }
    else
    {
        cout << "Cycle not dectected!";
    }

    return 0;
}