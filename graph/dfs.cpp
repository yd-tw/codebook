void dfs(int x){
    vis[x]=1;
    for(int i:edge[x]){
        if(!vis[i])
            dfs(i);
    }
}