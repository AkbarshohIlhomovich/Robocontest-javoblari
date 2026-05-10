#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
vector<tuple<int, int, int, int>> queries;
vector<int> current_A;
long long max_score = 0;

void solve(int index, int prev_val) {
    if (index == N) {
        long long current_score = 0;
        for (const auto& q_tuple : queries) {
            int a = get<0>(q_tuple);
            int b = get<1>(q_tuple);
            int c = get<2>(q_tuple);
            int d = get<3>(q_tuple);

            if (current_A[b - 1] - current_A[a - 1] == c) {
                current_score += d;
            }
        }
        max_score = max(max_score, current_score);
        return;
    }

    for (int val = prev_val; val <= M; ++val) {
        current_A[index] = val;
        solve(index + 1, val);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> Q;

    current_A.resize(N);
    queries.reserve(Q);

    for (int i = 0; i < Q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        queries.emplace_back(a, b, c, d);
    }

    solve(0, 1);

    cout << max_score << endl;

    return 0;
}
