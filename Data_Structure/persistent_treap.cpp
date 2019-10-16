// Once persistent, every op must not change tree struct.
// Also don't free them if any version may be referenced later.
Treap* merge(Treap *a, Treap *b) { // When new, also copy priority
	if (!a || !b) return a ? (new Treap(a)) : (new Treap(b));
	Treap *t;
	if (a->pri > b->pri) {
		t = new Treap(a);
		t->r = merge(t->r, b);
		pull(t);
		return t;
	}
	else {
		t = new Treap(b);
		t->l = merge(a, t->l);
		pull(t);
		return t;
	}
}
void split(Treap *t, int k, Treap *&a, Treap *&b ) {
	// First k numbers <-> in *a
	if (!t) { a = b = NULL; return; }
	t = new Treap(t);
	if (Size(t->l) < k) {
		a = t;
		split(t->r, k - Size(t->l) - 1, a->r, b);
		pull(a);
	}
	else {
		b = t;
		split(t->l, k, a, b->l);
		pull(b);
	}
}
