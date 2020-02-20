#define ULL unsigned long long 
const ULL BASE = 307;
// 0-based, xpw[i]: BASE^i
// hval[i]: sum of str[j] * xpw[j - i]
vector<ULL> xpw, hval;

void hash_init(const string &str){
	int len = str.size();
	xpw.resize(len + 1);
	hval.resize(len + 1);
	for (int i = 1; i <= len; i++) {
		xp[i] = xp[i - 1] * BASE;
	}
	hval[len] = 0;
	for (int i = len - 1; i >= 0; i--) {
		hval[i] = hval[i + 1] * BASE + (ULL) str[i];
	}
}

ULL get_hash(int l, int r) { // [0, len - 1]
	return hval[l] - hval[r + 1] * xpw[r - l + 1];
}
