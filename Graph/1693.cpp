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

int inDeg[N], outDeg[N];

vector<int>path;

void dfs(int u) {
    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();

        dfs(v);
    }

    path.push_back(u);
}

void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        ++inDeg[v];
        ++outDeg[u];
    }

    int cntStart = 0;
    int cntEnd = 0;

    for (int i = 1; i <= n; ++i) {
        if (outDeg[i] - inDeg[i] == 1) ++cntStart;
        else if (inDeg[i] - outDeg[i] == 1) ++cntEnd;
        else if (inDeg[i] == outDeg[i]) continue;
        else {
            cout << "IMPOSSIBLE";
            return;
        }
    }

    if (cntStart > 1 || cntEnd > 1) {
        cout << "IMPOSSIBLE";
        return;
    }

    if (outDeg[1] - inDeg[1] != 1) {
        cout << "IMPOSSIBLE";
        return;
    }

    if (inDeg[n] - outDeg[n] != 1) {
        cout << "IMPOSSIBLE";
        return;
    }

    dfs(1);

    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE";
        return;
    }

    reverse(path.begin(), path.end());

    for (auto node : path) {
        cout << node << ' ';
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