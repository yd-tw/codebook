struct DSU {
    vector<int> p;
    DSU(int n): p(n, -1) {}
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void unite(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return;
        if(p[a] > p[b]) swap(a,b);
        p[a] += p[b];
        p[b] = a;
    }
};
