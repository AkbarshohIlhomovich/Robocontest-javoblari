#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> sz;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(w, u, v);
    }

    sort(edges.begin(), edges.end());

    parent.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (const auto& edge : edges) {
        int w = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);

        unite_sets(u, v);

        if (find_set(s) == find_set(t)) {
            cout << w << endl;
            return 0;
        }
    }

    return 0;
}
