#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void BFS(vector<int> adj[], int v, int s)
{
    vector<bool> visited(v + 1, false);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        cout << u << endl;
        for (int v1 : adj[u])
        {
            if (visited[v1] == false)
            {
                visited[v1] = true;
                q.push(v1);
            }
        }
    }
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
    BFS(adj, v, s);
}
