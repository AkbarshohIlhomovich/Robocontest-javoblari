#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int M, K, N;
    cin >> M >> K >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> next_occurrence(N);
    vector<int> last_seen(M + 1, N); 

    for (int i = N - 1; i >= 0; --i) {
        next_occurrence[i] = last_seen[A[i]];
        last_seen[A[i]] = i;
    }

    int trips = 0;
    set<pair<int, int>> active_guns;
    vector<int> current_gun_next_occurrence(M + 1, N); 

    for (int i = 0; i < N; ++i) {
        int current_gun_type = A[i];
        int next_use_for_current_gun = next_occurrence[i];

        if (current_gun_next_occurrence[current_gun_type] != N) { 
            active_guns.erase({current_gun_next_occurrence[current_gun_type], current_gun_type});
            active_guns.insert({next_use_for_current_gun, current_gun_type});
            current_gun_next_occurrence[current_gun_type] = next_use_for_current_gun;
        } else { 
            trips++;

            if (active_guns.size() < K) { 
                active_guns.insert({next_use_for_current_gun, current_gun_type});
                current_gun_next_occurrence[current_gun_type] = next_use_for_current_gun;
            } else { 
                pair<int, int> gun_to_evict = *active_guns.rbegin();
                
                active_guns.erase(gun_to_evict);
                current_gun_next_occurrence[gun_to_evict.second] = N; 

                active_guns.insert({next_use_for_current_gun, current_gun_type});
                current_gun_next_occurrence[current_gun_type] = next_use_for_current_gun;
            }
        }
    }

    cout << trips << endl;

    return 0;
}
