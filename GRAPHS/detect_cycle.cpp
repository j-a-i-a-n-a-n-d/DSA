#include <bits/stdc++.h>
#define NINF INT_MIN
using namespace std;
class Solution
{
private:
    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (checkCycle(it, adj, vis, dfsVis))
                    return true;
            }
            else if (dfsVis[it])
            {
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }

public:
    bool isCyclic(int N, vector<int> adj[])
    {
        int vis[N], dfsVis[N];

        for (int i = 0; i < N; i++)
        {
            vis[i] = 0;
            dfsVis[i] = 0;
        }

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                // cout << i << endl;
                if (checkCycle(i, adj, vis, dfsVis))
                {
                    // cout << i << endl;
                    return true;
                }
            }
        }
        return false;
    }
};
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
void dfs(int node, vector<int> adj[], int dp[], bool vis[])
{
    vis[node] = true;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!vis[adj[node][i]])
            dfs(adj[node][i], adj, dp, vis);
        dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
    }
}
int findLongestPath(vector<int> adj[], int n)
{
    int dp[n + 1];
    memset(dp, 0, sizeof dp);
    bool vis[n + 1];
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, adj, dp, vis);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main()
{

    int n, m, temp;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> x(m, 0);
    vector<int> y(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        x[i] = temp;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        y[i] = temp;
    }

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
        addEdge(adj, x[i], y[i]);
    Solution obj;
    if (obj.isCyclic(n, adj))
    {
        cout << -1;
        return 0;
    }
    cout << findLongestPath(adj, n);
    return 0;
}