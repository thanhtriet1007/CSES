/* Author : Triet Do Thanh - FPT University */
 
#include <bits/stdc++.h>
 
#define int            long long
 
using namespace        std;
 
typedef pair<int, int> ii;
 
const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;
 
int n, m;
 
int dp[1 << 21][22];
 
int g[22][22];
 
void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        g[u][v]++;
    }
 
    dp[1][(1 << 0)] = 1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (mask != (1 << n) - 1 && (mask >> (n - 1)) & 1) continue;
        for (int i = 1; i < n; ++i) {
            if (mask & (1 << (i - 1))) {
                if (dp[mask][i] == 0) continue;
                for (int j = 1; j <= n; ++j) {
                    if (!(mask & (1 << (j - 1))) && g[i][j]) {
                        (dp[mask | (1 << (j - 1))][j] += dp[mask][i] * g[i][j]);
                        while (dp[mask | (1 << (j - 1))][j] >= MOD) {
                            dp[mask | (1 << (j - 1))][j] -= MOD;
                        }
                    }
                }
            }
        }
    }
 
    cout << dp[(1 << n) - 1][n];
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