/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, m;

multiset<int>s;

int sz[N], par[N];

int get(int u) {
    if (u == par[u]) return u;
    return par[u] = get(par[u]);
}

void unite(int u, int v) {
    u = get(u), v = get(v);

    if (u != v) {
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
}

void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
        s.insert(1);
    }

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        if (get(u) == get(v)) { 
            cout << s.size() << ' ' << *s.rbegin() << endl;
        } 
        else {
            s.erase(s.find(sz[get(u)]));
            s.erase(s.find(sz[get(v)]));

            unite(u, v);

            s.insert(sz[get(u)]);

            cout << s.size() << ' ' << *s.rbegin() << endl;
        }
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