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
