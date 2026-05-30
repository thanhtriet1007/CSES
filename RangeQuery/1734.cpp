/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, q;
int a[N]; 

set<int>st[N * 4];

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    if (l == r) {
        st[id].insert(val);
        return;
    }

    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    for (auto x : st[id * 2]) st[id].insert(x);
    for (auto x : st[id * 2 + 1]) st[id].insert(x);
}

set<int> get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return {};
    if (l >= u && r <= v) return st[id];
    int mid = (l + r) >> 1;
    set<int> res;
    for (auto x : get(id * 2, l, mid, u, v)) res.insert(x);
    for (auto x : get(id * 2 + 1, mid + 1, r, u, v)) res.insert(x);
    return res;
}

void solve() {
    //World Final when?
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) update(1, 1, n, i, a[i]);

    while (q--) {
        int l, r; cin >> l >> r;
        cout << get(1,1,n,l,r).size() << endl;
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