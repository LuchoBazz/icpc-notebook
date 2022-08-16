template<class X>
struct getId {
	map<X, int> ids;
	int operator[](const X &x) {
		auto &v = ids[x];
		if(v == 0) v = (int) ids.size();
		return v;
	}
	int size() { return (int) ids.size(); }
};
// Usage: getId<int> ids;