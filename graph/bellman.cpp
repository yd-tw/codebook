#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

#define int long long

vector<tuple<int, int, int>> edge[2005];
int n, m;

void bellman(int s, int t) {
    int dis[2005];
    for (int i = 0; i < 2005; i++) dis[i] = LLONG_MIN;
    dis[s] = 0;

    for (int iter = 1; iter <= n; iter++) {
        vector<int> chang;
        for (int u = 1; u <= n; u++) {
            if (dis[u] == LLONG_MIN) continue;
            for (auto [from, v, w] : edge[u]) {
                if (dis[u] + w > dis[v]) {
                    dis[v] = dis[u] + w;
                    if (iter == n) chang.push_back(v);
                }
            }
        }

        if (iter == n) {
            queue<int> q;
            vector<int> vis(2005);
            for (auto i : chang) q.push(i);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == n) {
                    cout << "inf";
                    exit(0);
                }
                for (auto [u, v, w] : edge[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    cout << dis[n];
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({u, v, w});
    }
    bellman(1, -1);
}
