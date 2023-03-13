import java.util.*;

class Solution {
    private static final int NINF = Integer.MIN_VALUE;

    private boolean checkCycle(int node, List<Integer>[] adj, int[] vis, int[] dfsVis) {
        vis[node] = 1;
        dfsVis[node] = 1;
        for (int it : adj[node]) {
            if (vis[it] == 0) {
                if (checkCycle(it, adj, vis, dfsVis)) {
                    return true;
                }
            } else if (dfsVis[it] == 1) {
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }

    public boolean isCyclic(int N, List<Integer>[] adj) {
        int[] vis = new int[N];
        int[] dfsVis = new int[N];

        for (int i = 0; i < N; i++) {
            vis[i] = 0;
            dfsVis[i] = 0;
        }

        for (int i = 0; i < N; i++) {
            if (vis[i] == 0) {
                if (checkCycle(i, adj, vis, dfsVis)) {
                    return true;
                }
            }
        }
        return false;
    }
}

public class OP {
    private static void addEdge(List<Integer>[] adj, int u, int v) {
        adj[u].add(v);
    }

    private static void dfs(int node, List<Integer>[] adj, int[] dp, boolean[] vis) {
        vis[node] = true;
        for (int i = 0; i < adj[node].size(); i++) {
            int adjNode = adj[node].get(i);
            if (!vis[adjNode]) {
                dfs(adjNode, adj, dp, vis);
            }
            dp[node] = Math.max(dp[node], 1 + dp[adjNode]);
        }
    }

    private static int findLongestPath(List<Integer>[] adj, int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, 0);
        boolean[] vis = new boolean[n + 1];
        Arrays.fill(vis, false);
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i, adj, dp, vis);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int m = in.nextInt();
        String s = in.next();
        List<Integer> x = new ArrayList<>();
        List<Integer> y = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            x.add(in.nextInt());
        }
        for (int i = 0; i < m; i++) {
            y.add(in.nextInt());
        }

        List<Integer>[] adj = new List[n + 1];
        for (int i = 0; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            addEdge(adj, x.get(i), y.get(i));
        }

        Solution obj = new Solution();
        if (obj.isCyclic(n, adj)) {
            System.out.println(-1);
            return;
        }
        System.out.println(findLongestPath(adj,n));
        }
}
