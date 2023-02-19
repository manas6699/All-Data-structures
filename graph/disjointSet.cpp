#include <bits/stdc++.h>
using namespace std;

// global variables
const int n = 1e5+10;
int parent[n];
int raNk[n];

// functions
void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        raNk[i] = 0;
    }
}

int findParent(int node)
{
    if (node == parent[node])
    {
        return node;
    }
    // path compression
    return parent[node] = findParent(node);
}

void unIon(int u, int v)
{
    u = findParent(u);
    v = findParent(v);

    if (raNk[u] < raNk[v])
    {
        parent[u] = v;
    }
    else if (raNk[v] < raNk[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        raNk[u]++;
    }
}
int main()
{
    int m;
    cout << "Enter the value of m : ";
    cin >> m;

    while (m--)
    {
        int u , v;
        unIon(u , v);
    }

    // if 2 & 3 belong to the same paren or not
    if (findParent(2) != findParent(3))
    {
        cout << "Different parent" << endl;
    }
    else
    {
        cout << "Same parent" << endl;
    }
    
    

    return 0;
}