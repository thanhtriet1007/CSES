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

int vis[N], ccId[N], cnt = 0;

stack<int>myStack;

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
   ccId[u] = cnt; 
   for (int &v : rev[u]) {
      if (!vis[v]) {
         dfs2(v);
      }
   }
}

int convert(char c, int u) {
   if (c == '+') return 2 * u;
   else return 2 * u + 1;
}

void solve() {
    //World Final when?
   cin >> m >> n;
   for (int i = 1; i <= m; ++i) {
      int u, v;
      char uu, vv;
      cin >> uu >> u >> vv >> v;
      u = convert(uu, u);
      v = convert(vv, v);


      adj[u ^ 1].push_back(v);
      rev[v].push_back(u ^ 1);

      adj[v ^ 1].push_back(u);
      rev[u].push_back(v ^ 1);

   }

   for (int i = 1; i <= n; ++i) {
      if (!vis[2 * i]) {
         dfs1(2 * i);
      }
      if (!vis[2 * i + 1]) {
         dfs1(2 * i + 1);
      }
   }

   for (int i = 1; i <= n; ++i) {
      vis[i * 2] = vis[i * 2 + 1] = 0;
   }

   while (!myStack.empty()) {
      int u = myStack.top();
      myStack.pop();

      if (!vis[u]) {
         ++cnt;
         dfs2(u);
      }
   }

   for (int i = 1; i <= n; ++i) {
      if (ccId[i * 2] == ccId[i * 2 + 1]) {
         cout << "IMPOSSIBLE";
         return;
      }
   }

   for (int i = 1; i <= n; ++i) {
      if (ccId[i * 2] > ccId[i * 2 + 1]) cout << "+" << ' ';
      else cout << "-" << ' ';
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