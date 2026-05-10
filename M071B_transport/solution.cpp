#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    vector<long long> C(4); 
    cin >> N >> C[0] >> C[1] >> C[2] >> C[3];

    vector<vector<long long>> A(4, vector<long long>(N));
    for (int t = 0; t < 4; ++t) {
        for (int i = 0; i < N; ++i) {
            cin >> A[t][i];
        }
    }

    long long min_overall_cost = numeric_limits<long long>::max();

    for (int mask = 0; mask < (1 << 4); ++mask) {
        long long current_total_cost = 0;
        bool possible_path = true;

        for (int t = 0; t < 4; ++t) {
            if ((mask >> t) & 1) { 
                current_total_cost += C[t];
            }
        }

        for (int i = 0; i < N; ++i) { 
            long long min_segment_cost = numeric_limits<long long>::max();
            bool segment_possible = false;

            for (int t = 0; t < 4; ++t) { 
                long long segment_cost = A[t][i];

                if (segment_cost == -1) { 
                    continue;
                }

                if ((mask >> t) & 1) { 
                    segment_cost = 0; 
                }

                min_segment_cost = min(min_segment_cost, segment_cost);
                segment_possible = true;
            }

            if (!segment_possible) { 
                possible_path = false;
                break;
            }
            current_total_cost += min_segment_cost;
        }

        if (possible_path) {
            min_overall_cost = min(min_overall_cost, current_total_cost);
        }
    }

    cout << min_overall_cost << endl;

    return 0;
}
