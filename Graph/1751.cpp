/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, cnt = 0;

vector<int>adj[N];
vector<int>rev[N];
vector<int>dag[N];
vector<int>revDag[N];

int vis[N], cc[N], a[N], deg[N], sz[N];
stack<int>SCCStack;

int ans[N];

void dfs1(int u) {
    vis[u] = 1;
    for (int &v : adj[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    SCCStack.push(u);
}

void dfs2(int u) {
    cc[u] = cnt;
    sz[cnt]++;
    vis[u] = 1;
    for (int &v : rev[u]) {
        if (!vis[v]) {
            dfs2(v);
        }
    }
}

vector<int>topo;

void solve() {
    //World Final when?
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int node; cin >> node; 
        a[i] = node;
        adj[i].push_back(node);
        rev[node].push_back(i);

        if (i == a[i]) {
            ans[i] = 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs1(i);
    }

    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
    }

    while (!SCCStack.empty()) {
        int u = SCCStack.top();
        SCCStack.pop(); 

        if (!vis[u]) {
            ++cnt;
            dfs2(u);
        }
    }

    vector<int>dist(n + 1, INF);
    priority_queue<ii, vector<ii>, greater<ii>>pq;

    for (int i = 1; i <= n; ++i) {
        if (cc[i] != cc[a[i]]) {
            revDag[cc[a[i]]].push_back(cc[i]);
            //++deg[cc[a[i]]];
            //cout << cc[i] << ' ' << cc[a[i]] << endl;
        } else if (i == a[i]) {
            dist[cc[i]] = 1;
            pq.push({1, cc[i]});
        }
    }


    for (int i = 1; i <= cnt; ++i) {
        if (sz[i] > 1) {
            dist[i] = sz[i];
            pq.push({sz[i], i});
        }
    }

    while (!pq.empty()) {   
        auto [du, u] = pq.top();
        pq.pop(); 

        if (du != dist[u]) {
            continue;
        }
        for (int &v : revDag[u]) {
            if (dist[v] > dist[u] + sz[v]) {
                dist[v] = dist[u] + sz[v];
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dist[cc[i]] == INF) cout << sz[cc[i]] << ' ';
        else cout << dist[cc[i]] << ' ';
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