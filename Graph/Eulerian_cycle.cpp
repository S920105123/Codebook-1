// The cycle will be output in reverse order
// if you want eulerian "path",
// Add one edge, find cycle, transform to path
void dfs(int v) {
	while(!g[v].empty()) {
		int u = g[v].back();
		g[v].pop_back();
		dfs(u);
		output(Edge(v, u)); // v to u
	}
}
