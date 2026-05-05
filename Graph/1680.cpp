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

int dp[N];
int deg[N];
int trace[N];

void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        ++deg[v];
    }   

    vector<bool>vis(n + 1, 0);

    queue<int>myQueue;

    for (int i = 1; i <= n; ++i) {
        dp[i] = -INF;
        if (!deg[i]) {
            myQueue.push(i);
            vis[i] = 1;
        }
    }

    dp[1] = 1;

    while (!myQueue.empty()) {
        int u = myQueue.front();
        myQueue.pop();

        //cout << u << endl;

        for (int &v : adj[u]) {
            if (vis[v]) continue;
            --deg[v];
            if (dp[v] < dp[u] + 1) {
                trace[v] = u;
                dp[v] = dp[u] + 1;
            }

            if (!deg[v]) {
                myQueue.push(v);
                vis[v] = 1;
            }
        }
    }

    if (dp[n] <= 0) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << dp[n] << endl;
        vector<int>ans;
        while (n != 0) {
            ans.push_back(n);
            n = trace[n];
        }
        reverse(ans.begin(), ans.end());
        for (auto it : ans) cout << it << ' ';
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