#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> salaries(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> salaries[i];
    }

    long long current_sum = 0;
    for (int i = 0; i < k; ++i) {
        current_sum += salaries[i];
    }

    long long max_sum = current_sum;

    for (int i = k; i < n; ++i) {
        current_sum = current_sum - salaries[i - k] + salaries[i];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    long double max_average = static_cast<long double>(max_sum) / k;

    // To match the sample output formatting:
    // If the average is an exact integer, print with one decimal place (e.g., 80.0).
    // Otherwise, print with more precision (e.g., 14 decimal places as in sample 2).
    if (max_sum % k == 0) {
        std::cout << std::fixed << std::setprecision(1) << max_average << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(14) << max_average << std::endl;
    }

    return 0;
}
