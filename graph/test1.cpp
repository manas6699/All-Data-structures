// // // #include <bits/stdc++.h>
// // // using namespace std;

// // // // time complexity : O(n)

// // // class solution
// // // {
// // // public:
// // //     bool dfs_ka_cycleFucker(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfsVis)
// // //     {
// // //         vis[node] = 1;
// // //         dfsVis[node] = 1;

// // //         for (auto it : adj[node])
// // //         {
// // //             if (!vis[it])
// // //             {
// // //                 if (dfs_ka_cycleFucker(it, vis, adj, dfsVis))
// // //                 {
// // //                     return true;
// // //                 }
// // //             }
// // //             else if (dfsVis[it])
// // //             {
// // //                 return true;
// // //             }
// // //         }
// // //         dfsVis[node] = 0;
// // //         return false;
// // //     }

// // //     bool isCycle(int v, vector<int> adj[])
// // //     {
// // //         // vector e 0 vore dilam
// // //         vector<int> vis(v, 0);
// // //         vector<int> dfsVis(v, 0);
// // //         for (int i = 0; i < v; i++)
// // //         {
// // //             if (!vis[i])
// // //             {
// // //                 if (dfs_ka_cycleFucker(i, vis, adj, dfsVis))
// // //                 {
// // //                     return true;
// // //                 }
// // //             }
// // //         }
// // //         return false;
// // //     }
// // // };

// // #include <bits/stdc++.h>

// // using namespace std;

// // class Solution
// // {
// // private:
// //     bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
// //     {
// //         vis[node] = 1;
// //         dfsVis[node] = 1;
// //         for (auto it : adj[node])
// //         {
// //             if (!vis[it])
// //             {
// //                 if (checkCycle(it, adj, vis, dfsVis))
// //                     return true;
// //             }
// //             else if (dfsVis[it])
// //             {
// //                 return true;
// //             }
// //         }
// //         dfsVis[node] = 0;
// //         return false;
// //     }

// // public:
// //     bool isCyclic(int N, vector<int> adj[])
// //     {
// //         int vis[N], dfsVis[N];
// //         memset(vis, 0, sizeof vis);
// //         memset(dfsVis, 0, sizeof dfsVis);

// //         for (int i = 0; i < N; i++)
// //         {
// //             if (!vis[i])
// //             {
// //                 // cout << i << endl;
// //                 if (checkCycle(i, adj, vis, dfsVis))
// //                 {
// //                     return true;
// //                 }
// //             }
// //         }
// //         return false;
// //     }
// // };

// // int main()
// // {
// //     int n, m;
// //     cout << "Enter the node size and vertex number : ";
// //     cin >> n >> m;

// //     vector<int> adj[n];
// //     for (int i = 0; i < m; i++)
// //     {

// //         int u, v;
// //         cout << "Enter connections : ";
// //         cin >> u >> v;

// //         adj[u].push_back(v);
// //         adj[v].push_back(u);
// //     }
// //     Solution s1;
// //     bool fAns = s1.isCyclic(n, adj);
// //     if (fAns != true)
// //     {
// //         cout << "No Cycle detected!";
// //     }
// //     else
// //     {
// //         cout << "cycle detected!";
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// pair<int, int> findIndex(vector<vector<int>> &matrix)
// {
//     pair<int, int> ans;
//     int m = matrix.size();
//     int n = matrix[0].size();
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 ans.first = i;
//                 ans.second = j;
//                 break;
//             }
//         }
//     }
//     return ans;
// }
// int main()
// {

//     int n = 3;
//     int m = 3;
    
//     // vector<int> v1 = {0 , 1 , 2 , 3 , 4};
//     // //cout << true<< " " << false;
//     // for(auto it : v1)
//     // {
//     //     cout << v1[it] << " ";
//     // }

//     vector<vector<int>> v1(n, vector<int>(m, 0));
    
//     cout << "Matrix : ";
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << v1[i][j] << " ";
//         }
//     }
//     cout << findIndex(v1).first << " " << findIndex(v1).second;

//     return 0;
// }

// Dijkstra's algorithm : 

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, source;
	cin >> n >> m;
	vector<pair<int, int>> g[n + 1]; // 1-indexed adjacency list for of graph

	int a, b, wt;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b, wt));
		// g[b].push_back(make_pair(a, wt));
	}

	cin >> source;

	// Dijkstra's algorithm begins from here
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap ; In pair => (dist,from)
	vector<int> distTo(n + 1, INT_MAX);													// 1-indexed array for calculating shortest paths;

	distTo[source] = 0;
	pq.push(make_pair(0, source)); // (dist,from)

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();

		vector<pair<int, int>>::iterator it;
		for (it = g[prev].begin(); it != g[prev].end(); it++)
		{
			int next = it->first;
			int nextDist = it->second;
			if (distTo[next] > distTo[prev] + nextDist)
			{
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
	}

	cout << "The distances from source to " << source << " is : " << distTo[source] << endl;

	return 0;
}
//  6 8 0 1 1 1 2 3 1 3 5 2 3 4 1 4 2 3 4 6 4 5 5 3 5 2