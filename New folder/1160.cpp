/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, m;
int a[N], val[N];

vector<int>adj[N];
vector<int>rev[N];
vector<int>dag[N];

int vis[N], deg[N];
stack<int>myStack;

int cnt = 0, sccId[N];

void dfs1(int u) {
    vis[u] = 1; 
    for (int &v : adj[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    myStack.push(u);
}

void dfs2(int u) {
    vis[u] = 1;
    sccId[u] = cnt;
    for (int &v : rev[u]) {
        if (!vis[v]) dfs2(v);
    }
}

void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs1(i);
    }

    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
    }
    while (!myStack.empty()) {
        int u = myStack.top();
        myStack.pop();

        if (!vis[u]) {
            ++cnt;
            dfs2(u);
        }
    }

    for (int i = 1; i <= n; ++i) val[sccId[i]] += a[i];

    for (int i = 1; i <= n; ++i) {
        int node = sccId[i];
        for (int &v : adj[i]) {
            if (node == sccId[v]) continue;
            dag[node].push_back(sccId[v]);
            deg[sccId[v]]++;
        }
    }

    queue<int>myQueue;
    vector<int>dp(cnt + 1, 0);

    for (int i = 1; i <= cnt; ++i) vis[i] = 0;

    for (int i = 1; i <= cnt; ++i) {
        if (!deg[i]) {
            myQueue.push(i);
            dp[i] = val[i];
            vis[i] = 1;
        }
    }
    while (!myQueue.empty()) {
        int u = myQueue.front();
        myQueue.pop();

        //cout << u << endl;

        for (int &v : dag[u]) {
            if (vis[v]) continue;
            dp[v] = max(dp[v], dp[u] + val[v]);
            --deg[v];

            if (deg[v] == 0) {
                myQueue.push(v);
                vis[v] = 1;
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());
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