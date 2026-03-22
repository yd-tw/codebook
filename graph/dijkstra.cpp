vector<long long> dijkstra(int n, vector<vector<pair<int,int>>> &g, int s){
    vector<long long> dist(n, 1e18);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;

        for(auto [v, w] : g[u]){
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
