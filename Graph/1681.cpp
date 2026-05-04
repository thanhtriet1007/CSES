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

int ways[N];
int deg[N];

void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    queue<int>q;
    vector<int>vis(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (!deg[i]) {
            //ways[i] = 1;
            vis[i] = 1;
            q.push(i);
        }
    }

    ways[1] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int &v : adj[u]) {
            if (vis[v]) continue;
            --deg[v];
            ways[v] += ways[u];
            ways[v] %= MOD;
            if (deg[v] == 0) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }   

    cout << ways[n];

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