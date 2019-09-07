vector<int> lps; // longest prefix suffix, 0-based
int match(const string &text, const string &pat) {
	/* Init is included */
	lps.resize(pat.size());	
	/* DP */
	lps[0]=0;
	for (int i=1; i<pat.size(); i++) {
		int len=lps[i - 1];
		while(len>0 && pat[len]!=pat[i]) len=lps[len - 1];
		lps[i] = pat[len]==pat[i] ? len+1 : 0;
	}	
	/* Match */
	int i = 0, j = 0;
	while (i < text.size() && j < pat.size()) {
		if (text[i] == pat[j]) i++, j++;
		else if (j == 0) i++;
		else j = lps[j - 1];
	}
	if (j >= pat.size()) return i - j;
	return -1;
}
