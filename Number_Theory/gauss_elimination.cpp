vector<long long> gauss(int N, long long m[MAXN][MAXN+1]) {
    // Find solution of system of N linear equations, N^3.
    // N equations having the form a1x1 + a2x2 + ... + anxn = c.
    for (int i = 0; i < N - 1; i++) {
        int r = i;
        for (int j = i; j < N; j++) {
            if (m[j][i] != 0) {
                r = j;
                break;
            }
        }
        if (m[r][i] == 0) continue; // target column all zeros
        for (int j = 0; j < N + 1; j++) {
            swap(m[i][j], m[r][j]);
        }
        for (r = i + 1; r < N; r++) { // m[r][i] / m[i][i] instead
            long long mul = m[r][i] * get_inv(m[i][i]) % MOD;
            for (int c = 0; c < N + 1; c++) {
                m[r][c] = (m[r][c] - (LL) m[i][c] * mul) % MOD;
            }
        }
    }
 
    vector<long long> sol(N);
    for (int i = N - 1; i >= 0; i--) {
        long long val = m[i][N];
        for (int j = i + 1; j < N; j++) {
            val = (val - m[i][j] * sol[j]) % MOD;
        }
        if (m[i][i] == 0) return vector<long long>(); // no sol or inf sol.
        sol[i] = (val * get_inv(m[i][i]) % MOD + MOD) % MOD;
    }
 
    return sol;
}
