/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, m;
vector<ii>adj[N];

vector<pair<ii, int>>vec;

void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, -w});
        adj[v].push_back({u, -w});
        vec.push_back({{u, v}, -w});
    }

    vector<int>dist(n + 1, INF);
    dist[1] = 0;
    for (int T = 1; T < n; ++T) {
        for (auto [p, w] : vec) {
            auto [u, v] = p;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    for (int T = 0; T < n; ++T) {
        for (auto [p, w] : vec) {
            auto [u, v] = p;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = -INF;
            }
        }
    }

    if (dist[n] == -INF) {
        cout << -1;
    } else cout << -dist[n];
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