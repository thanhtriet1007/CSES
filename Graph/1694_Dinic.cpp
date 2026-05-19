/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> ii;

const int N = 1e6 + 7;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;

int n, m;

int cap[502][502];

int level[N], ptr[N];

struct Edge {
   int v, cap, flow;
   
   int rev;
   
   Edge(int _v, int _cap, int _rev) {
      v = _v;
      cap = _cap;
      flow = 0;
      rev = _rev;
   }
};

vector<Edge> adj[N];
void addEdge(int u, int v, int cap) {
   adj[u].push_back(Edge(v, cap, adj[v].size()));
   adj[v].push_back(Edge(u, 0, adj[u].size() - 1));
}

bool bfs(int s) {
   for (int i = 1; i <= n; ++i) level[i] = -1;
   level[s] = 1;
   queue<int>myQueue;   
   myQueue.push(s);

   while (!myQueue.empty()) {
      int u = myQueue.front();
      myQueue.pop();

      for (auto [v, cap, flow, rev] : adj[u]) {
         if (cap - flow > 0 && level[v] == -1) {
            level[v] = level[u] + 1;
            myQueue.push(v);
         }
      }
   }
   return (level[n] != -1);
}

int dfs(int u, int curDelta) {
   if (curDelta <= 0) return 0;
   if (u == n) return curDelta;


   for (int cid = ptr[u]; cid < adj[u].size(); ++cid) {
      ptr[u] = cid;
      auto &[v, cap, flow, rev] = adj[u][cid];
      
      if (level[u] + 1 != level[v] || cap - flow <= 0) continue;

      int trPush = dfs(v, min(curDelta, cap - flow));

      if (trPush <= 0) continue;

      flow += trPush;

      adj[v][rev].flow -= trPush;

      return trPush;
   }
   return 0;
}

int dinic(int s) {
   int flow = 0;
   while (bfs(s)) {
      for (int i = 1; i <= n; ++i) ptr[i] = 0;
      int pushed;
      while (pushed = dfs(s, INF)) {
         flow += pushed;
      }
   }
   return flow;
}

void solve()
{
   // World Final when?
   cin >> n >> m;

   for (int i = 1; i <= m; ++i)
   {
      int u, v;
      cin >> u >> v;
      cin >> cap[u][v];

      addEdge(u, v, cap[u][v]);
   }


   cout << dinic(1);
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