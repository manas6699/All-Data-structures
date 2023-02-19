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
		g[b].push_back(make_pair(a, wt));
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

    int source_node;
    cout << "Enter the destination node : " ;
    cin >> source_node;

	//cout << "The distances from source, " << source << ", are : \n";
	// for (int i = 1; i <= n; i++)
	// 	cout << distTo[i] << " ";
	// cout << "\n";

    cout << distTo[source_node];

	return 0;
}

// 6 8
// 0 1 1 1 2 3 1 3 5 2 3 4 1 4 2 3 4 6 4 5 5 3 5 2
// 4
