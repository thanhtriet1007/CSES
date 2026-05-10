/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, m;
multiset<int>adj[N]; 

int deg[N];
vector<int>vec;

void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        ++deg[u];
        ++deg[v];
    }

    for (int i = 1; i <= n; ++i) {
        if (deg[i] & 1) {
            cout << "IMPOSSIBLE";
            return;
        }
    }

    stack<int>st;
    st.push(1);

    while (!st.empty()) { 
        int u = st.top(); 
        if (adj[u].empty()) {
            st.pop();
            vec.push_back(u);
            continue;
        }

        int v = *adj[u].begin();
        adj[u].erase(adj[u].find(v));
        adj[v].erase(adj[v].find(u));

        st.push(v);
    }

    if (vec.size() != m + 1) {
        cout << "IMPOSSIBLE";
        return;
    }

    for (int &it : vec) {
        cout << it << ' ';
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