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

int st[N * 4];

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    if (l == r) {
        st[id] += val;
        return;
    }

    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

struct query {
    int l, r, id;
};

map<int, int>lst;

query Queries[N];
int ans[N];

void solve() {
    //World Final when?
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= q; ++i) {
        cin >> Queries[i].l >> Queries[i].r;
        Queries[i].id = i;  
    }

    sort(Queries + 1, Queries + q + 1, [](query a, query b) {
        return a.r < b.r;
    });

    int j = 0;

    for (int i = 1; i <= n; ++i) {
        if (lst[a[i]] == 0) {
            lst[a[i]] = i;
            update(1, 1, n, i, 1);
        } else {
            update(1, 1, n, lst[a[i]], -1);
            lst[a[i]] = i;
            update(1, 1, n, i, 1);
        }
        while (j + 1 <= q && Queries[j + 1].r == i) {
            ans[Queries[j + 1].id] = get(1, 1, n, Queries[j + 1].l, Queries[j + 1].r);
            j++;
        }
    }

    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << endl;
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