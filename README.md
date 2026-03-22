# Codebook

## STL

## 演算法

### BIT

```cpp
struct Binary_Indexed_Tree{
    int n;
    vector<long long> bit;
    int lowbit(int x){
        return x&-x;
    }
    void init(int _n){
        n = _n+1;
        bit = vector<long long>(n,0);
    }
    void update(int x,int v){
        for(; x<n; x+=lowbit(x)){
            bit[x] += v;
        }
    }
    long long query(int x){
        long long ret = 0;
        for(; x>0; x-=lowbit(x)){
            ret += bit[x];
        }
        return ret;
    }
}BIT;
```

#### 我隊友寫的 BIT

```cpp
#include <bits/stdc++.h>
using namespace std;
struct BIT{
    int n;
    vector<int> bit;
    void init(int a){
      n = a + 1;
      // n = (this->n)+1;
      // bit.resize(n);
      // fill(bit.begin(),bit.begin(),0);
      bit = vector<int> (n,0);
    }
    int lowbit(int x){
      if(x == 0){
        cerr << "you suck\n";
      }
      else return ((-x)&(x));
    }
}BIT;
int main() {

}
```

### Dijkstra

```cpp
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define pii pair<int,int>
#define INF 1e18
#define int long long

vector<pii> vec[100005];
vector<int> vis(100005);

int n, m;

void dijkstra(int s,int t){//起點，終點
    int dis[100005];
    for(int i=0;i<100005;i++){//初始化
        dis[i]=INF;//值要設為比可能的最短路徑權重還要大的值
    }
    dis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;//以小到大排序
    pq.push({dis[s],s});
    while(pq.empty()==0){
        int u=pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u]=1;

        for (int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i].first;
            int w = vec[u][i].second;
            if(dis[u]+w < dis[v]){//鬆弛
                dis[v] = dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
}

main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
    }

    dijkstra(1, -1);
}
```

### Bellman-Ford

```cpp
	struct edge {
    int v, w;
};
int s, n; // 起點 點數量
vector<edge> E[MXN];
vector<int> dis(MXN, INF), cnt(MXN), inq(MXN);
// cnt記錄最短路經過幾條邊
// inq記錄節點是否在queue裡面
queue<int> Q;
dis[s] = 0; Q.push(s); inq[s] = 1;
while (Q.size()) {
    int u = Q.front(); Q.pop();
    inq[u] = 0;
    for (auto [v, w] : E[u]) {
        if (dis[v] > dis[u] + w) {
            dis[v] = dis[u] + w;
            cnt[v] = cnt[u] + 1;
            if (cnt[v] >= n) {
                // 有負環 因為一般最短路只會經過 n - 1 條邊
            }
            if (!inq[v]) Q.push(v), inq[v] = 1;
        }
    }
}
```

### 圖

> 這裡沒有東西


## 範例

### 最短路徑樹

```cpp
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;

#define pii pair<int,int>
#define INF 1e18
#define int long long

vector<tuple<int, int, int>> vec[200005];
vector<int> vis(200005);
vector<int> path(200005);

int n, m;

void dijkstra(int s,int t){//起點，終點
    int dis[200005];
    for(int i=0;i<200005;i++){//初始化
        dis[i]=INF;//值要設為比可能的最短路徑權重還要大的值
    }
    dis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;//以小到大排序
    pq.push({dis[s],s});
    while(pq.empty()==0){
        int u=pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u]=1;

        for (auto [v, w, i] : vec[u]) {
            if(dis[u]+w < dis[v]){//鬆弛
                dis[v] = dis[u]+w;
                pq.push({dis[v],v});
                path[v] = i;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << path[i] << " ";
    }
}

main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c, i});
        vec[b].push_back({a, c, i});
    }

    dijkstra(1, -1);
}
```

### 最長bellMAN路徑

```
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
```