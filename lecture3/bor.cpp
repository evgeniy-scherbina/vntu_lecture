struct vertex {
	int next[K];
	bool leaf;
};

vertex t[NMAX+1];
int sz;

memset (t[0].next, 255, sizeof t[0].next);
sz = 1;

void add_string (const string & s) {
	int v = 0;
	for (size_t i=0; i<s.length(); ++i) {
		char c = s[i]-'a'; // в зависимости от алфавита
		if (t[v].next[c] == -1) {
			memset (t[sz].next, 255, sizeof t[sz].next);
			t[v].next[c] = sz++;
		}
		v = t[v].next[c];
	}
	t[v].leaf = true;
}