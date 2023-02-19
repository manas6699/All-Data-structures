#include <bits/stdc++.h>
using namespace std;

void bfsPrint(int **edges, int n, int si)
{
    queue<int> q1;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

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

bool has_path(int** edges , int n , int sv , int find)
{
    bool ans = false;
    queue<int> q1;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    q1.push(sv);
    visited[sv] = true;

     while (!q1.empty())
    {
        int currentNode = q1.front();
        if (q1.front() == find)
        {
            ans = true;
        }
        
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
    return ans;
}
// 7 7 0 1 0 2 2 6 1 5 5 4 4 3 3 2
int main()
{
    cout << "Enter the number of nodes and edges respectively : " << endl;
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

    cout << "Enter connections : " << endl;
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << "\nEnter starting index : ";
    int si;
    cin >> si;
    cout << "Your graph in bfs order : " << endl;
    bfsPrint(edges, n, si);
    int find;
    cout << "\nEnter the node to check it's availability : " << endl;
    cin >> find;
    if(has_path(edges , n , si , find))
    {
        cout << find << " is available!" << endl;
    }
    else
    {
        cout << "Sorry!" << endl;
    }


    return 0;
}