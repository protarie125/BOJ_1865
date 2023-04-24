#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

constexpr auto inf = int{ 987'654'321 };

bool checkNegativePath(int n, const vector<tuple<int, int, int>>& es) {
	auto dist = vi(n, inf);
	dist[0] = 0;

	for (auto v = 1; v < n; ++v) {
		for (const auto& xyz : es) {
			const auto& x = get<0>(xyz);
			const auto& y = get<1>(xyz);
			const auto& z = get<2>(xyz);

			const auto& newDist = dist[x] + z;
			if (newDist < dist[y]) {
				dist[y] = newDist;
			}
		}
	}

	for (const auto& xyz : es) {
		const auto& x = get<0>(xyz);
		const auto& y = get<1>(xyz);
		const auto& z = get<2>(xyz);

		const auto& newDist = dist[x] + z;
		if (newDist < dist[y]) {
			return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (0 < (t--)) {
		int n, m, w;
		cin >> n >> m >> w;

		auto es = vector<tuple<int, int, int>>{};
		es.reserve(2 * m + w);

		for (auto i = 0; i < m; ++i) {
			int x, y, z;
			cin >> x >> y >> z;

			es.push_back({ x - 1, y - 1, z });
			es.push_back({ y - 1, x - 1, z });
		}

		for (auto i = 0; i < w; ++i) {
			int x, y, z;
			cin >> x >> y >> z;

			es.push_back({ x - 1, y - 1, -z });
		}

		const auto& hasNp = checkNegativePath(n, es);

		if (hasNp) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}