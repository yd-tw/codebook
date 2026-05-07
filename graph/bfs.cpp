bool vis[MXN];
void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i:edge[x]){
            if(!vis[i])
                q.push(i),vis[i]=1;
        }
    }
}