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

void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>>pq;
    vector<vector<int>>dist(2, vector<int>(n + 1, INF));
    dist[0][1] = dist[1][1] = 0;
    pq.push({0, {0, 1}});

    while (!pq.empty()) {
        auto [du, p] = pq.top();
        auto [ok, u] = p;
        pq.pop();

        if (du != dist[ok][u]) continue;
        for (auto [v, w] : adj[u]) {
            if (ok == 1) {
                if (dist[1][v] > dist[1][u] + w) {
                    dist[1][v] = dist[1][u] + w;
                    pq.push({dist[1][v], {1, v}});
                }
            }
            else {
                if (dist[1][v] > dist[0][u] + w / 2) {
                    dist[1][v] = dist[0][u] + w / 2;
                    pq.push({dist[1][v], {1, v}});
                }
                if (dist[0][v] > dist[0][u] + w) {
                    dist[0][v] = dist[0][u] + w;
                    pq.push({dist[0][v], {0, v}});
                }
            }
        }
    }

    cout << dist[1][n];
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