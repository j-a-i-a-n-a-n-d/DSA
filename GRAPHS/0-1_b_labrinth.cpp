#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int i, j, left, right;
} node;
int BFS(vector<vector<char>> &grid, int n, int m, int r, int c, int left, int right)
{
    deque<node> D;
    node t1;
    t1.i = r;
    t1.j = c;
    t1.left = left;
    t1.right = right;
    D.push_front(t1);

    int count = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));

    while (!D.empty())
    {
        node t = D.front();
        D.pop_front();
        visited[t.i][t.j] = 1;
        // cout << t.i << " " << t.j << " " << t.left << " " << t.right << endl;
        count++;
        if (t.j - 1 >= 0 && !visited[t.i][t.j - 1] && grid[t.i][t.j - 1] == '.' && t.left - 1 >= 0)
        {
            // count++;
            visited[t.i][t.j - 1] = 1;
            D.push_back({t.i, t.j - 1, t.left - 1, t.right});
        }

        if (t.j + 1 <= m - 1 && !visited[t.i][t.j + 1] && grid[t.i][t.j + 1] == '.' && t.right - 1 >= 0)
        {
            visited[t.i][t.j + 1] = 1;
            D.push_back({t.i, t.j + 1, t.left, t.right - 1});
            // count++;
        }

        if (t.i + 1 <= n - 1 && !visited[t.i + 1][t.j] && grid[t.i + 1][t.j] == '.')
        {
            visited[t.i + 1][t.j] = 1;
            D.push_front({t.i + 1, t.j, t.left, t.right});
            // count++;
        }

        if (t.i - 1 >= 0 && !visited[t.i - 1][t.j] && grid[t.i - 1][t.j] == '.')
        {
            visited[t.i - 1][t.j] = 1;
            D.push_front({t.i - 1, t.j, t.left, t.right});
            // count++;
        }
    }
    return count;
}
int main()
{
    int n, m;
    int left, right;
    int r, c;
    cin >> n >> m;
    cin >> r >> c;
    r--;
    c--;
    cin >> left >> right;
    vector<vector<char>> grid(n, vector<char>(m, ' '));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            grid[i][j] = ch;
        }
    }
    cout << BFS(grid, n, m, r, c, left, right) << endl;
}