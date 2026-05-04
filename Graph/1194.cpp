/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> ii;

const int N = 1e6 + 7;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;

int n, m;
char a[1002][1002];

queue<ii> monsterQueue;
queue<ii> myQueue;

int monsterMinDist[1002][1002];
int myMinDist[1002][1002];

int vis[1002][1002][2];
ii trace[1002][1002];

int mx[] = {-1, 1, 0, 0};
int my[] = {0, 0, -1, 1};

bool valid(int i, int j, int id)
{
    return (i >= 1 && j >= 1 && i <= n && j <= m && a[i][j] != '#' && vis[i][j][id] == 0);
}

char move(int i, int j, int ni, int nj) {
    if (ni == i + 1) return 'D';
    if (ni == i - 1) return 'U';
    if (nj == j + 1) return 'R';
    if (nj == j - 1) return 'L';
}

void track(int i, int j) {
    vector<ii>tmp;
    while (trace[i][j] != make_pair(0ll, 0ll)) {
        //cout << i << ' ' << j << ' ' << trace[i][j].first << ' ' << trace[i][j].second << endl;
        tmp.push_back({i, j});
        int u = i, v = j;
        i = trace[u][v].first;
        j = trace[u][v].second;
        //cout << i << ' ' << j << endl;
    }

    tmp.push_back({i, j});

    cout << "YES" << endl;
    cout << tmp.size() - 1 << endl;

    reverse(tmp.begin(), tmp.end());
    for (int i = 0; i < tmp.size() - 1; ++i) {
        auto [u, v] = tmp[i];
        //cout << u << ' ' << v << endl;
        auto [nu, nv] = tmp[i + 1];

        cout << move(u, v, nu, nv);
    }
}

void solve()
{
    // World Final when?
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            myMinDist[i][j] = monsterMinDist[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                myQueue.push({i, j});
                myMinDist[i][j] = 0;
                vis[i][j][0] = 1;
            }
            else if (a[i][j] == 'M')
            {
                monsterQueue.push({i, j});
                monsterMinDist[i][j] = 0;
                vis[i][j][1] = 1;
            }
        }
    }

    while (myQueue.size())
    {
        auto [u, v] = myQueue.front();
        myQueue.pop();

        for (int _ = 0; _ < 4; ++_)
        {
            int newU = mx[_] + u;
            int newV = my[_] + v;
            if (valid(newU, newV, 0))
            {
                vis[newU][newV][0] = 1;
                myQueue.push({newU, newV});
                trace[newU][newV] = {u, v};
                myMinDist[newU][newV] = myMinDist[u][v] + 1;
            }
        }
    }

    
    //for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) vis[i][j][1] = 0;
    
    while (monsterQueue.size())
    {
        auto [u, v] = monsterQueue.front();
        monsterQueue.pop();
        
        for (int _ = 0; _ < 4; ++_)
        {
            int newU = mx[_] + u;
            int newV = my[_] + v;
            if (valid(newU, newV, 1))
            {
                vis[newU][newV][1] = 1;
                monsterQueue.push({newU, newV});
                // trace[newU][newV] = {u, v};
                monsterMinDist[newU][newV] = monsterMinDist[u][v] + 1;
            }
        }
    }
    //cout << trace[3][7].first << ' '<< trace[2]

    for (int i = 1; i <= n; ++i) {
        if (myMinDist[i][1] < monsterMinDist[i][1]) {
            track(i, 1);
            return;
        }
        if (myMinDist[i][m] < monsterMinDist[i][m]) {
            track(i, m);
            return;
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (myMinDist[1][i] < monsterMinDist[1][i]) {
            track(1, i);
            return;
        }
        if (myMinDist[n][i] < monsterMinDist[n][i]) {
            track(n, i);
            return;
        }
    }

    cout << "NO" << endl;
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