LL pollard_rho(LL n, int c = 1) {
	// c is seed, rand can be replaced by 2, much faster
	LL x = rand() % n, y = x, d = 1;
	while (d == 1) {
		x = mod_mul(x, x, n) + c;
		y = mod_mul(y, y, n) + c;
		y = mod_mul(y, y, n) + c;
		d = gcd(x - y >= 0 ? x - y : y - x, n);
	}
	if (d == n) return pollard_rho(n, c + 1);
	return d;
}
 
void factorize(LL n, vector<LL> &pf) {
	// N^(1/3) + logN*(N^(1/4))
	// For all primes <= N^(1/3)
	for (LL p = 2; p <= (LL)1e6+5; p++) {
		while (n % p == 0) {
			pf.push_back(p);
			n /= p;
		}
	}
	// Use Miller-Rabin pls
	if (n == 1) return;
	else if (is_prime(n)) pf.push_back(n);
	else {
		LL d = pollard_rho(n);
		pf.push_back(d);
		pf.push_back(n / d);
	}
}
