int get_size(int v, int p) {
	sz[v] = 1;
	for (int to : G[v]) {
		if (to != p && !vis[to]) {
			get_size(to, v);
			sz[v] += sz[to];
		}
	}
	return sz[v];
}
 
void find_cent(int v, int p, int &cent, int S) {
	int big = S - sz[v];
	for (int to : G[v]) {
		if (!vis[to] && to != p) {
			big = max(big, sz[to]);
			find_cent(to, v, cent, S);
		}
	}
	maxs[v] = big;
	if (cent == -1 || big < maxs[cent]) {
		cent = v;
	}
}
 
void dfs(int v, int p, int d, vector<int> &sub) {
	dep[v] = d;
	sub.push_back(v);
	for (int to : G[v]) {
		if (!vis[to] && to != p) {
			dfs(to, v, d + 1, sub);
		}
	}
}

LL solve(int v, int l, int r) {
	// # unordered (x, y), l <= dist(x, y) <= r, in tree of v.
	int S = get_size(v, v), root = -1;
	find_cent(v, v, root, S);
	vis[root] = 1;

	LL res = 0;
	tree.add(0, 1); // ***** tree MUST be 0-based RSQ
	vector<int> all;
	for (int to : G[root]) {
		if (!vis[to]) {
			vector<int> sub;
			dfs(to, root, 1, sub);
			for (int u : sub) {
				all.push_back(u);
				if (r - dep[u] >= 0) {
					res += tree.get(r - dep[u]);
				}
				if (l - 1 - dep[u] >= 0) {
					res -= tree.get(l - 1 - dep[u]);
				}
			}
			for (int u : sub) {
				tree.add(dep[u], 1);
			}
		}
	}

	tree.add(0, -1);
	for (int u : all) {
		tree.add(dep[u], -1);
	}
	all.clear();
	all.shrink_to_fit();
 
	for (int to : G[root]) {
		if (!vis[to]) {
			res += solve(to, l, r);
		}
	}
 
	return res;
}
