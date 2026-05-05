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
vector<int>rev[N];

bool vis[N];

void dfs1(int u) {
    vis[u] = 1;
    for (int &v : adj[u]) {
        if (vis[v]) continue;
        dfs1(v);
    }
}

void dfs2(int u) {
    vis[u] = 1;
    for (int &v : rev[u]) {
        if (vis[v]) continue;
        dfs2(v);
    }
}

void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) vis[i] = 0;
    dfs1(1);

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cout << "NO" << endl;
            cout << 1 << ' ' << i << endl;
            return;
        }
    }

    for (int i = 1; i <= n; ++i) vis[i] = 0;
    dfs2(1);

     for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cout << "NO" << endl;
            cout << i << ' ' << 1 << endl;
            return;
        }
    }

    cout << "YES";
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