#include <iostream>
#include <vector>
#include <fstream>

using vecp = std::vector<std::pair<uint64_t, uint64_t>>;

struct Address {
	Address(uint64_t i = 0) : _addr(i) {}

	uint64_t bits(short a, short b) { return _addr << 63 - a >> 63 - a + b; }
	uint64_t get_addr() { return _addr << 12 >> 24 << 12; }
	bool enabled() { return _addr & 1; }
	bool ps() { return _addr >> 7 & 1; }
private:
	uint64_t _addr;
};

uint64_t find(const vecp& v, uint64_t val) {
	for (auto n : v) {
		if (n.first == val)
			return n.second;
	}
	return NULL;
}

int main() {
	std::ifstream is("dataset_44327_15.txt");
	std::ofstream os("out1.txt");
	if (!is.is_open()) return 0;

	int m, q;
	uint64_t r, l;

	is >> m >> q >> r;
	Address root(r);

	vecp v(m);
	for (int i = 0; i < v.size(); ++i)
		is >> v[i].first >> v[i].second;

	while (q-- != 0) {
		is >> l;
		Address l_addr(l);
		Address p3_addr = find(v, root.get_addr() + l_addr.bits(47, 39) * 8);
		if (p3_addr.enabled()) {
			Address p2_addr = find(v, p3_addr.get_addr() + l_addr.bits(38, 30) * 8);
			if (p2_addr.enabled()) {
				Address p1_addr = find(v, p2_addr.get_addr() + l_addr.bits(29, 21) * 8);
				if (p1_addr.enabled()) {
					Address addr = find(v, p1_addr.get_addr() + l_addr.bits(20, 12) * 8);
					if (addr.enabled()) {
						os << addr.get_addr() + l_addr.bits(11, 0) << std::endl;
						continue;
					}
				}
			}
		}
		os << "fault" << std::endl;
	}
}