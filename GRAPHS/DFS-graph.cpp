#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void DFSr(vector<int> adj[], int s, vector<bool> &visited)
{
    visited[s] = true;
    cout << s << endl;
    for (int i : adj[s])
    {
        if (visited[i])
            continue;
        if (visited[i] == false)
            DFSr(adj, i, visited);
    }
}
void DFS(vector<int> adj[], int v, int s)
{
    vector<bool> visited(v, false);
    for (int u = 0; u < v; u++)
        if (visited[u] == false)
            DFSr(adj, u, visited);
}
void addelementtograph(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

int main()
{
    int v, x, y, e;
    cout << "no of vertex" << endl;
    cin >> v;
    cout << "no. of edges" << endl;
    cin >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        cout << "v1 v2" << endl;
        cin >> x >> y;
        addelementtograph(adj, x, y);
    }
    int s;
    cin >> s;
    DFS(adj, v, s);
}
