#include <bits/stdc++.h>

using namespace std;

struct Event {
    long long coord;
    int type; // 0: end of interval, 1: start of interval, 2: query point
    long long value; // Contribution for start/end, or original index for query

    // Custom comparator for sorting events.
    // Events are primarily sorted by coordinate.
    // If coordinates are equal, they are sorted by type:
    // 0 (end) -> 1 (start) -> 2 (query).
    // This order ensures:
    // 1. Contributions from intervals ending at `coord - 1` are removed first.
    // 2. Contributions from intervals starting at `coord` are added next.
    // 3. Queries at `coord` are processed last, using the `current_S_sum` that
    //    correctly reflects the state at `coord`.
    bool operator<(const Event& other) const {
        if (coord != other.coord) {
            return coord < other.coord;
        }
        return type < other.type;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Event> events;
    events.reserve(2 * n + m); // Pre-allocate memory to optimize vector growth

    for (int i = 0; i < n; ++i) {
        long long l, r, x;
        cin >> l >> r >> x;

        long long val_contribution = x;
        // (-1)^(l_i) is -1 if l_i is odd, 1 if l_i is even.
        if (l % 2 != 0) {
            val_contribution *= -1;
        }

        // Add a start event for the interval [l, r]
        // Type 1 for start events
        events.push_back({l, 1, val_contribution});

        // Add an end event for the interval [l, r] at r+1
        // The contribution is negated as the interval's effect ends
        // Type 0 for end events
        events.push_back({r + 1, 0, -val_contribution});
    }

    vector<long long> answers(m); // To store results for m queries, indexed by original query order

    for (int i = 0; i < m; ++i) {
        long long q_coord;
        cin >> q_coord;
        // Add a query event
        // Type 2 for query events, value stores the original index `i`
        events.push_back({q_coord, 2, (long long)i});
    }

    // Sort all events according to the custom comparator
    sort(events.begin(), events.end());

    long long current_S_sum = 0; // This accumulates the S(k) value: sum_{i: l_i <= k <= r_i} x_i * (-1)^(l_i)

    for (const auto& event : events) {
        if (event.type == 0) { // End event
            // Remove the contribution of an interval that just ended (at event.coord - 1)
            current_S_sum += event.value; // event.value is already - (original contribution)
        } else if (event.type == 1) { // Start event
            // Add the contribution of an interval that just started (at event.coord)
            current_S_sum += event.value;
        } else { // Query event (type == 2)
            long long q_coord = event.coord;
            int query_index = event.value; // Retrieve the original index of the query

            // The height H(q_coord) = (-1)^(q_coord) * S(q_coord)
            long long H_q = current_S_sum;
            // Multiply by -1 if q_coord is odd
            if (q_coord % 2 != 0) {
                H_q *= -1;
            }
            answers[query_index] = H_q;
        }
    }

    // Output the stored answers in the original query order
    for (int i = 0; i < m; ++i) {
        cout << answers[i] << "\n";
    }

    return 0;
}
