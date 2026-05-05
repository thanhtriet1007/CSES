/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> ii;

const int N = 1e6 + 7;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;

int n, m;
vector<ii> adj[N];

int dist[N], trace[N], cnt[N], inQueue[N];

void spfa()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        inQueue[i] = 1;
        q.push(i);
        dist[i] = INF;
        cnt[i] = 0;
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inQueue[u] = 0;

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                trace[v] = u;
                if (!inQueue[v])
                {
                    q.push(v);
                    inQueue[v] = 1;
                    ++cnt[v];
                    if (cnt[v] > n)
                    {
                        int cur = v;
                        for (int i = 1; i <= n; ++i)
                        {
                            cur = trace[cur];
                        }
                        cout << "YES" << endl;
                        int node = cur;
                        stack<int> st;
                        do
                        {
                            st.push(cur);
                            cur = trace[cur];
                        } while (cur != node);
                        st.push(node);
                        while (!st.empty())
                        {
                            cout << st.top() << ' ';
                            st.pop();
                        }
                        return;
                    }
                }
            }
        }
    }
    cout << "NO";
}

void solve()
{
    // World Final when?
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    spfa();
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