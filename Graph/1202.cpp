/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, m;
vector<ii>adj[N];

struct dat {
    int minDist, cntWays, minNum, maxNum, node;

    bool operator < (const dat& other) const {
        if (minDist != other.minDist) return minDist > other.minDist;
        else if (minNum != other.minNum) return minNum > other.minNum;
        else if (maxNum != other.maxNum) return maxNum < other.maxNum;
    }
};

void solve() {
    //World Final when?
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int>minDist(n + 1, INF);
    vector<int>cntWays(n + 1, 0);
    vector<int>minNum(n + 1, INF);
    vector<int>maxNum(n + 1, -INF);

    priority_queue<dat>pq;

    pq.push({0, 1, 0, 0, 1});
    minDist[1] = 0;
    minNum[1] = 0;
    maxNum[1] = 0;
    cntWays[1] = 1;

    while (!pq.empty()) {
        auto [minD, cWays, minN, maxN, u] = pq.top();
        pq.pop(); 

        if (minD > minDist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (minDist[v] > minDist[u] + w) {
                cntWays[v] = cntWays[u];
                cntWays[v] %= MOD;
                minDist[v] = minDist[u] + w; 
                minNum[v] = minNum[u] + 1;
                maxNum[v] = maxNum[u] + 1;
                pq.push({minDist[v], cntWays[v], minNum[v], maxNum[v], v});
            }
            else if (minDist[v] == minDist[u] + w) {
                cntWays[v] += cntWays[u];
                cntWays[v] %= MOD;
                //minDist[v] = minDist[u] + w; 
                minNum[v] = min(minNum[u] + 1, minNum[v]);
                maxNum[v] = max(maxNum[u] + 1, maxNum[v]);
            }
        }
    }  
    cout << minDist[n] << ' ' << cntWays[n] % MOD << ' ' << minNum[n] << ' ' << maxNum[n]; 
     
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