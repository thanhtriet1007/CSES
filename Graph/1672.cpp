/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, m, q; 

int dist[502][502];
int adj[502][502];

void solve() {
    //World Final when?
    cin >> n >> m >> q; 
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) dist[i][j] = INF;
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w; 
        adj[u][v] = adj[v][u] = w; 
        dist[u][v] = dist[v][u] = min(dist[u][v], w);
    }

    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while (q--) {
        int u, v; cin >> u >> v;
        if (dist[u][v] >= INF) cout << -1 << endl;
        else cout << dist[u][v] << endl;
    }
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