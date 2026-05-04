/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> ii;

const int N = 1e6 + 7;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;

int n, m;
vector<int> adj[N];

int cl[N];
int trace[N];

int d[N];


void dfs(int u, int p, int cnt) {
   cl[u] = 1;
   d[u] = cnt;
   //cout << u << ' ' << cnt << endl;
   for (int &v : adj[u]) {
      if (cl[v] == 2 || v == p) continue;
      else if (cl[v] == 1) {
         if (cnt >= 3) {
            int node = u;
            vector<int>ans;
            ans.push_back(v);
            //cout << v << endl;
            while (node != v) {
               ans.push_back(node);
               node = trace[node];
            }
            ans.push_back(v);

            cout << ans.size() << endl;
            for (int it : ans) cout << it << ' ';
            exit(0);
         }
      }
      else {
         trace[v] = u;
         dfs(v, u, cnt + 1);
      }
   }   
   cl[u] = 2;
}

void solve()
{
   // World Final when?
   cin >> n >> m;
   for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   for (int i = 1; i <= n; ++i) {
      if (!cl[i]) dfs(i, 0, 1);
   }
   cout << "IMPOSSIBLE";
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