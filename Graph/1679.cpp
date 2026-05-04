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

int deg[N];

void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        ++deg[v];
    }

    vector<int>ans;
    vector<int>vis(n + 1, 0);

    queue<int>myQueue;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 0) {
            myQueue.push(i);
            vis[i] = 1;
        }
    }
    while (!myQueue.empty()) { 
        int u = myQueue.front();
        myQueue.pop();
        ans.push_back(u);

        for (int &v : adj[u]) {
            if (vis[v] == 1) continue;
            --deg[v]; 
            if (deg[v] == 0) {
                myQueue.push(v);
                vis[v] = 1;
            }
        }
    }
    if (ans.size() != n) {
        cout << "IMPOSSIBLE";
    } else {
        for (int it : ans) {
            cout << it << ' ';
        }
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