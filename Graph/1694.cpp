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

int cap[502][502];

int parent[N];

bool bfs(int s, int t) {
    for (int i = 1; i <= n; ++i) parent[i] = -1;
    queue<int>myQueue;

    myQueue.push(s);
    parent[s] = -2; 

    while (!myQueue.empty()) {
        int u = myQueue.front();
        myQueue.pop();

        for (int &v : adj[u]) {
            if (parent[v] == -1 && cap[u][v] > 0) {
                parent[v] = u;
                if (v == t) return true;
                myQueue.push(v);
            }
        }
    }
    return false;
}

int maxFlow(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        int pathFlow = INF;

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v]; 
            pathFlow = min(pathFlow, cap[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            cap[u][v] -= pathFlow;
            cap[v][u] += pathFlow;
        }

        flow += pathFlow;
    }
    return flow;
}

void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;

        int w; cin >> w;

        adj[u].push_back(v);
        adj[v].push_back(u);

        cap[u][v] += w;
    }

    cout << maxFlow(1, n);
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