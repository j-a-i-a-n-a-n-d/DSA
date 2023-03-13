#include <bits/stdc++.h>
using namespace std;
bool isValid(int i, int j, int n, int m)
{
    return i >= 0 && j >= 0 && j < m && i < n;
}
int multipleBFS(vector<vector<int>> &grid, int n, int m, int maxxy)
{
    // queue //visited array
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    // storing hours
    int hours = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == maxxy)
                q.push({i, j});
        }
    }
    while (!q.empty())
    {

        vector<pair<int, int>> vp;
        while (!q.empty())
        {
            pair<int, int> temp = q.front();
            q.pop();
            if (isValid(temp.first, temp.second, n, m) && !visited[temp.first][temp.second])
            {
                visited[temp.first][temp.second] = 1;
                vp.push_back({temp.first, temp.second});
            }
        }

        if (!vp.empty())
            hours++;

        for (auto it : vp)
        {
            int i = it.first;
            int j = it.second;
            if (!isValid(i, j, n, m))
                continue;

            q.push({i - 1, j - 1});
            q.push({i - 1, j});
            q.push({i - 1, j + 1});
            q.push({i, j - 1});
            q.push({i, j + 1});
            q.push({i + 1, j - 1});
            q.push({i + 1, j});
            q.push({i + 1, j + 1});
        }
        vp.clear();
    }
    // one extra iteration lg rhi h corner walo  k lie coz so hours --1 return krna is good for the answer
    return hours - 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        cin >> m;

        vector<vector<int>> grid(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                grid[i][j] = x;
            }
        }

        int maxxy = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // cout << grid[i][j] << " ";
                if (maxxy < grid[i][j])
                    maxxy = grid[i][j];
            }
            // cout << endl;
        }
        // cout << maxxy;
        cout << multipleBFS(grid, n, m, maxxy) << endl;
    }
    return 0;
}
