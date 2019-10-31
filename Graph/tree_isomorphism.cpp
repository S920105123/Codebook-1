// Hash the parenthesis tuple given by AHU algorithm. O(nlgn)
// If you want exact, discretize the sorted euler tour layer by layer.
// The input should be a rooted tree, for unrooted, find centroid or center then do something.
#define ULL unsigned long long
static const ULL BASE = 7;
int sz[MAXN];
ULL dfs(int v, int p, vector<int> adj[]) {
	ULL res = 1;
	vector<pair<ULL, int>> h;
	sz[v] = 1;
	for (int to : adj[v]) {
		if (to == p) continue;
		h.push_back({dfs(to, v, adj), sz[to]});
		sz[v] += sz[to];
	}
	
	sort(h.begin(), h.end());
	for (auto it : h) {
		res *= qpow(BASE, it.second);
		res += it.first;
	}
	return res;
}
ULL get_hash(int root, vector<int> adj[]) {
	return dfs(root, root, adj);
}
