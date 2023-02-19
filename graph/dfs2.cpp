#include <bits/stdc++.h>
using namespace std;

void dfs_ka_maa_ka_vosra_behen_ki_lund(int sv , int** edges , int n , bool* visited)
{
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            dfs_ka_maa_ka_vosra_behen_ki_lund(i , edges , n , visited);
        }
        
        
    }
    
}

int main()
{
    int e , n;
    cout << "Enter the number of nodes and edges respectively : " << endl;
    cin >> n >> e;
    int** edges = new int* [n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i] [j] = 0;
        }
        
    }
    
    for (int i = 0; i < e; i++)
    {
        cout << "Enter connections : " << endl;
        int f , s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;

    }
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int si;
    cout << "Enter the starting index : " << endl;
    cin >> si;
    dfs_ka_maa_ka_vosra_behen_ki_lund(si , edges , n , visited);
    delete[] visited;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    

    return 0;
}