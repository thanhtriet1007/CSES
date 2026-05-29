/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> ii;

const int N = 1e6 + 7;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;

int n, q;

class Node
{
public:
    int maxValue, sum;

    Node() {}

    Node(int _maxValue, int _sum) {
        maxValue = _maxValue;
        sum = _sum;
    }
};

Node combine(Node a, Node b)
{
    Node res;
    res.maxValue = max(a.maxValue, a.sum + b.maxValue);
    res.sum = a.sum + b.sum;
    return res;
}



Node st[N * 4];

void update(int id, int l, int r, int pos, int val)
{
    if (l > pos || r < pos)
        return;
    if (l == r)
    {
        st[id].maxValue = val;
        st[id].sum = val;
        return;
    }

    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);

    st[id] = combine(st[id * 2], st[id * 2 + 1]);
}

Node get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return Node(0, 0);
    if (l >= u && r <= v) return st[id];    
    int mid = (l + r) >> 1;
    return combine(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void solve()
{
    // World Final when?

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        update(1, 1, n, i, x);
    }

    while (q--) {
        int type, l, r; cin >> type >> l >> r;
        if (type == 1) {
            update(1, 1, n, l, r);
        } else {
            cout << max(0ll, get(1, 1, n, l, r).maxValue) << '\n';
        }
    }
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