// To use it, call init_HLD
// In this template value is on the vertex, everything is 1-based
int n, qn, wei[MAXN];
vector<int> G[MAXN];
 
// Preprocess info, setup in dfs1
int heavy[MAXN], sz[MAXN];
int pa[MAXN], dep[MAXN]; // Which node record edge i.
 
// HLD info, setup in build, 1-based
// pos: position of node i in seg tree.
// head: For NODE i, points to head of the chain. Head will have smallest pos[v] in the chain.
int chain_no, border, pos[MAXN], head[MAXN];
 
void dfs1(int v, int p) {
    pa[v] = p;
    sz[v] = 1;
    dep[v] = dep[p] + 1;
    heavy[v] = -1;
    
    for (const int to : G[v]) {
        if (to == p) continue;
        dfs1(to, v);
        sz[v] += sz[to];
        if (heavy[v] == -1 || sz[to] > sz[heavy[v]]) {
            heavy[v] = to;
        }
    }
}
 
void build(int v, int chain_head) {
    pos[v] = ++border;
    head[v] = chain_head;
    tree.update(pos[v], pos[v], wei[v], 1, n, 1);
    
    if (heavy[v] != -1) build(heavy[v], chain_head);
    for (int to : G[v]) {
        if (to == pa[v] || to == heavy[v]) continue;
        build(to, to);
    }
}
 
int query_up(int a, int b) {
    int ans = 0;
    while (head[a] != head[b]) {
    	if (dep[head[a]] < dep[head[b]]) swap(a, b);
    	ans = max((LL)ans, tree.query(pos[head[a]], pos[a], 1, n, 1).val);
    	a = pa[head[a]];
	}
	
	// Change this section when weights are on edges.
	// If a == b, do nothing. otherwise, range is [pos[a]+1, pos[b]].
    if (dep[a] > dep[b]) swap(a, b);
    ans = max((LL)ans, tree.query(pos[a], pos[b], 1, n, 1).val);
    return ans;
}
 
void init_HLD(int n) { 
	// Assumes the graph G is already setup.
	tree.init(1, n, 1); // Optional
    border = dep[1] = 0;
    dfs1(1, 1);
    build(1, 1);
}
