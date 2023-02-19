#include <bits/stdc++.h>
using namespace std;

void printDFS(int **edges, int n, int fi, bool *visited)
{
    cout << fi << " ";
    visited[fi] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == fi)
        {
            continue;
        }
        if (edges[fi][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

void PrintBFS(int **edges, int n, int si, bool *visited)
{
    queue<int> q1;
    q1.push(si);
    visited[si] = true;

    while (!q1.empty())
    {
        int currentNode = q1.front();
        cout << currentNode << " ";
        q1.pop();

        for (int i = 0; i < n; i++)
        {
            if (i == currentNode)
            {
                continue;
            }

            if (edges[currentNode][i] == 1 && !visited[i])
            {
                q1.push(i);
                visited[i] = true;
            }
        }
    }
}

void bfs(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            PrintBFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}
void dfs(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    cout << "BFS : " << endl;
    bfs(edges, n);
    cout << endl;
    cout << "DFS : " << endl;
    dfs(edges, n);

    return 0;
}