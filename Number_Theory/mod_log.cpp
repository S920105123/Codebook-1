const LL SQRT = 10005;
pair<LL, LL> bs[SQRT];
// O(sqrt(n)log(n))
LL baby_giant(LL a, LL b, LL m) {
	// Solve a^x = b (mod m) for x, gcd(a, m) = 1
	bs[0] = {1, 0};
	for (int i = 1; i < SQRT; i++) {
		bs[i] = {bs[i - 1].first * a % m, i};
	}
	
	LL cur = b, inv = mod_inv(bs[SQRT - 1].first * a % m, m); // inv of G.S.
	sort(bs, bs + SQRT);
	for (int i = 0; i < m; i += SQRT) {
		auto it = upper_bound(bs, bs + SQRT, make_pair(cur, (LL)-1));
		if (it != bs + SQRT && it->first == cur) {
			return i + it->second;
		}
		cur = cur * inv % m;
	}
	return -1; // no solution
}
