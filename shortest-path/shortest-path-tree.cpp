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