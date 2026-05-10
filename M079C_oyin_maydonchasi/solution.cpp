#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool check(long long L, const std::vector<int>& A) {
    if (L == 0) {
        return false;
    }
    long long total_pieces = 0;
    for (int length_i : A) {
        total_pieces += length_i / L;
        if (total_pieces >= 4) {
            return true;
        }
    }
    return total_pieces >= 4;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    long long low = 1;
    long long high = 1000000000; // Maximum possible length of a single plank is 10^9
    long long ans_L = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, A)) {
            ans_L = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    std::cout << ans_L * ans_L << std::endl;

    return 0;
}
