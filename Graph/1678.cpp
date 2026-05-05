/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, m;
vector<int>adj[N];
int cl[N];
int trace[N];

void dfs(int u) {
    cl[u] = 1;
    for (int &v : adj[u]) {
        if (cl[v] == 2) continue;
        else if (cl[v] == 1) {
            int node = u;
            vector<int>ans;
            ans.push_back(v);
            while (node != v) {
                ans.push_back(node);
                node = trace[node];
            }
            ans.push_back(v);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for (auto it : ans) cout << it << ' ';
            exit(0);
        }
        else {
            trace[v] = u;
            dfs(v);
        }
    }
    cl[u] = 2;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v; 
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!cl[i]) {
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE";


}

#define TASK "test"

signed main()
{
   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   if (fopen("input.txt", "r")) {
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   }
   int t = 1;
   //cin >> t;
   while (t--)
   solve();
   return 0;
}