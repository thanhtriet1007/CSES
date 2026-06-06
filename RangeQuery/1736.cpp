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

struct SegTreeNormal {
    int lz[N * 4];
    int st[N * 4];

    void push(int id, int l, int r) {
        if (lz[id]) {
            st[id] += lz[id] * (r - l + 1);
            if (l != r) {
                lz[id * 2] += lz[id];
                lz[id * 2 + 1] += lz[id];
            }
            lz[id] = 0;
        }
    }

    void build(int id, int l, int r) {
        if (l > r) return;
        if (l == r) {
            st[id] = a[l];
            return;
        }
        
        int mid = (l + r) >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    void update(int id, int l, int r, int u, int v, int val) {
        push(id, l, r);

        if (l > v || r < u) return;
        if (l >= u && r <= v) {
            lz[id] += val;
            push(id, l, r);
            return;
        }        
        
        int mid = (l + r) / 2;
        
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);

        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    int get(int id, int l, int r, int u, int v) {
        push(id, l, r);
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) {
            return st[id];
        }

        int mid = (l + r) >> 1;

        return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
    }
};

struct SpecialSegTree {
    int st[N * 4];
    int lz[N * 4];

    int sumProgression(int l, int r) {
        return (l + r) * (r - l + 1) / 2;
    }

    void push(int id, int l, int r) {
        if (lz[id]) {
            st[id] += lz[id] * sumProgression(l, r);
            if (l != r) {
                lz[id * 2] += lz[id];
                lz[id * 2 + 1] += lz[id];
            }
            lz[id] = 0;
        }   
    }

    void update(int id, int l, int r, int u, int v, int val) {
        push(id, l, r);

        if (l > v || r < u) return;
        if (l >= u && r <= v) {
            lz[id] += val;
            push(id, l, r);
            return;
        }        
        
        int mid = (l + r) / 2;
        
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);

        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    int get(int id, int l, int r, int u, int v) {
        push(id, l, r);
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) {
            return st[id];
        }

        int mid = (l + r) >> 1;

        return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
    }
};

SegTreeNormal segConst;
SpecialSegTree segCnt; 

void solve() {
    //World Final when?
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    segConst.build(1,1,n);

    while (q--) {
        int type, l, r; cin >> type >> l >> r;
        if (type == 1) {
            segConst.update(1,1,n,l,r,-l + 1);
            segCnt.update(1,1,n,l,r,1);
        }
        else {
            cout << segConst.get(1,1,n,l,r) + segCnt.get(1,1,n,l,r) << '\n';
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