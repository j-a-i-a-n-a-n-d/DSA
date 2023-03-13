#include <bits/stdc++.h>
using namespace std;

int BFS(int vertices, vector<pair<int, int>> graph[])
{
    deque<int> q;
    vector<int> distances(vertices + 1, INT_MAX);
    distances[1] = 0;
    q.push_front(1);

    while (!q.empty())
    {
        int a = q.front();
        q.pop_front();
        for (auto it : graph[a])
        {
            int adjnode = it.first;
            int weight = it.second;
            if (distances[a] + weight < distances[adjnode])
            {
                distances[adjnode] = distances[a] + weight;
                if (weight == 1)
                    q.push_back(adjnode);
                else
                    q.push_front(adjnode);
            }
        }
    }
    return distances[vertices];
}
int main()
{
    int vertcies, edges;
    cin >> vertcies >> edges;
    vector<pair<int, int>> graph[vertcies + 1];
    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
            continue;
        graph[a].push_back(make_pair(b, 0));
        graph[b].push_back(make_pair(a, 1));
    }
    int op = BFS(vertcies, graph) == INT_MAX ? -1 : BFS(vertcies, graph);
    cout << op << endl;
}