#include <iostream>
#include <vector>
#include <algorithm>
#include <set> // Using std::set for its O(log N) operations and better constant factors compared to generic segment trees for some competitive programming judges.

struct Package {
    int l, r;
    int id; // Original index to maintain identity if needed, though not strictly required for this problem.
};

// Custom comparison function for sorting packages
// Sort primarily by right endpoint (r), then by left endpoint (l)
// This greedy choice helps in "earliest deadline first" strategy.
bool comparePackages(const Package& a, const Package& b) {
    if (a.r != b.r) {
        return a.r < b.r;
    }
    return a.l < b.l;
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<Package> packages(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> packages[i].l >> packages[i].r;
        packages[i].id = i;
    }

    // Sort packages based on the greedy strategy: earliest deadline first.
    std::sort(packages.begin(), packages.end(), comparePackages);

    // `uncollected_indices` will store the indices (0 to n-1) of packages
    // that have not yet been picked up. `std::set` keeps them sorted by index
    // and allows efficient insertion, deletion, and finding elements.
    std::set<int> uncollected_indices;
    for (int i = 0; i < n; ++i) {
        uncollected_indices.insert(i);
    }

    int trips = 0; // Counter for the number of trips Sunnat makes.

    // Iterate through the sorted packages.
    // If `packages[i]` is still uncollected, it means we need to make a trip for it
    // because it has the earliest deadline among uncollected packages.
    for (int i = 0; i < n; ++i) {
        // If this package has already been collected in a previous trip, skip it.
        if (uncollected_indices.find(i) == uncollected_indices.end()) {
            continue;
        }

        trips++; // Start a new trip.

        // The collection day for this trip is the deadline of the current package (packages[i].r).
        // This maximizes the collection window for other packages.
        int current_collection_day = packages[i].r;
        int collected_in_this_trip = 0;

        // Iterate through the `uncollected_indices` set, starting from the current package's index `i`.
        // We look for up to `k` packages that can be collected on `current_collection_day`.
        // Since `uncollected_indices` stores original sorted indices, iterating it
        // from `lower_bound(i)` ensures we consider packages in increasing order of `r` (and then `l`).
        auto it = uncollected_indices.lower_bound(i);
        while (it != uncollected_indices.end() && collected_in_this_trip < k) {
            int current_package_idx = *it;
            
            // Check if the package can be collected on `current_collection_day`.
            // Condition: `l_j <= current_collection_day`.
            // The condition `r_j >= current_collection_day` is implicitly handled because
            // packages are sorted by `r_j`, and `current_collection_day` is `packages[i].r`,
            // so any package `j` with `j >= i` will have `packages[j].r >= packages[i].r`.
            if (packages[current_package_idx].l <= current_collection_day) {
                // If collectable, remove it from the set and increment count.
                // `std::set::erase(iterator)` returns an iterator to the element
                // following the one removed, allowing continuous iteration.
                it = uncollected_indices.erase(it);
                collected_in_this_trip++;
            } else {
                // If not collectable (its `l_j` is too late), move to the next package.
                ++it;
            }
        }
    }

    std::cout << trips << std::endl;
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t; // Read the number of test cases.
    while (t--) {
        solve(); // Solve each test case.
    }

    return 0;
}
