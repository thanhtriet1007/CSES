/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

//#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 2e5 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, q;
vector<int>adj[N];   

int nxt[N][40];

void solve() {
   //World Final when?
   cin >> n >> q;
   for (int i = 1; i <= n; ++i) {
      int node; cin >> node;
      nxt[i][0] = node;
   }   

   for (int j = 1; (1ll << j) <= 1e9; ++j) {
      for (int i = 1; i <= n; ++i) {
         nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
      }
   }

   while (q--) {
      int node, k; cin >> node >> k;
      for (int i = 31; i >= 0; --i) {
         if ((1ll << i) <= k) {
            node = nxt[node][i];
            k -= (1ll << i);
         }
      }
      cout << node << endl;
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