/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> ii;

const int N = 1e6 + 7;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;

int n, m, k;
vector<int> dist[N];
vector<ii> adj[N];

void solve()
{
    // World Final when?
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [du, u] = pq.top();
        pq.pop();

        if (dist[u].size() >= k) continue;
        dist[u].push_back(du);

        for (auto [v, w] : adj[u])
        {
            //if (dist[v].size() < k) {
                //dist[v].push_back(du + w);
                pq.push({du + w, v});
            //}
        }
    }

    for (int j = 0; j < k; ++j)
        cout << dist[n][j] << ' ';
}

#define TASK "test"

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}