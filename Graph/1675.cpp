/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, m;
vector<pair<ii, int>>vec;

int par[N], sz[N];

int get(int u) {
    if (u == par[u]) return u;
    return par[u] = get(par[u]);
}

void unite(int u, int v) {
    u = get(u); v = get(v);
    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        vec.push_back({{u, v}, w});
    }

    sort(vec.begin(), vec.end(), [](pair<ii, int>a, pair<ii, int>b){
        return a.second < b.second;
    });

    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        auto [p, w] = vec[i - 1];
        auto [u, v] = p;
        if (get(u) != get(v)) {
            ans += w; 
            unite(u, v);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (sz[get(i)] != n) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    cout << ans;
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