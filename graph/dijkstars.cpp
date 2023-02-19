#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<int> dijkstra(int src, int n, vector<pair<int, int>> adj[])
    {
        vector<int> distance(n, INT_MAX);
        vector<int> visited(n, 0);

        priority_queue<pair<int, int>, vector<pair<int ,int >>,greater<pair<int , int>>> st;
         distance[src] = 0;
        st.push({0, src});
       

        while (st.size() > 0)
        {
           
          
            int v = st.top().first;
            int v_dist =st.top().second;
            st.pop();
          /*  if (visited[v])
            {
                continue;
            }*/
           // visited[v] = 1;
            for (auto child : adj[v])
            {
                int child_v = child.first;
                int wt = child.second;
                if (distance[v_dist] + wt < distance[child_v])
                {
                    distance[child_v] = distance[v_dist] + wt;
                    st.push({distance[child_v], child_v});
                }
            }
        }

        return distance;
    }

    // int networkDelayTime(vector<vector<int>> &times, int n, int k)
    // {
    //     vector<pair<int , int> > adj[n];
    //     for(auto vec : times)
    //     {
    //         adj[vec[0]].push_back({vec[1] , vec[2]});
    //     } 
    //     return dijkstra(k , n , adj);
    // }
};

int main()
{
    int n, m;
    cout << "Enter the node size and vertex number : ";
    cin >> n >> m;

    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {

        int u, v, wt;
        cout << "Enter connections and weights : ";
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        // for undirected grph
        // adj[v].push_back(u);
    }
    int src;
    cout << "Enter destination point : ";
    cin >> src;
    solution s1;
    vector<int>  f_ans = s1.dijkstra(0, n, adj);
    cout << f_ans[src];
    
    return 0;
}
// 6 8
// 0 1 1 1 2 3 1 3 5 2 3 4 1 4 2 3 4 6 4 5 5 3 5 2
// 4