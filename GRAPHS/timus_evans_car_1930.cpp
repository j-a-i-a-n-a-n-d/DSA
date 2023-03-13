// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define abid() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int BFS(int vertices, vector<pair<int, int>> graph[], int source, int destination)
{
    deque<pair<int, int>> q;
    vector<int> D(vertices + 1, INT_MAX);
    D[source] = 0;
    q.push_front({source, -1});
    int loop = 0;

    while (!q.empty())
    {
        pair<int, int> a = q.front();
        q.pop_front();
        int a1 = a.first;
        int a2 = a.second;

        for (auto it : graph[a1])
        {
            int adjnode = it.first;
            int dir = it.second;
            if (a2 == -1)
            {
                D[adjnode] = 0;
                q.push_front({adjnode, dir});
            }
            else if (a2 == dir && D[a1] < D[adjnode])
            {
                D[adjnode] = D[a1];
                q.push_front({adjnode, dir});
            }
            else if (D[a1] < D[adjnode])
            {
                D[adjnode] = D[a1] + 1;
                q.push_back({adjnode, dir});
            }
        }
    }
    return D[destination];
}
int main()
{
    abid();
    int n, m, source, destination;
    cin >> n >> m;
    vector<pair<int, int>> graph[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
            continue;
        graph[a].push_back(make_pair(b, 0));
        graph[b].push_back(make_pair(a, 1));
    }
    cin >> source >> destination;
    int op = BFS(n, graph, source, destination);
    cout << op << endl;
    return 0;
}