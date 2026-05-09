#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<long long> nums(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> nums[i];
    }

    long long total_sum = 0;
    for (long long num : nums) {
        total_sum += num;
    }

    long long min_val = nums[0];
    long long max_val = nums[0];

    for (int i = 1; i < 5; ++i) {
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
    }

    long long min_sum_of_four = total_sum - max_val;
    long long max_sum_of_four = total_sum - min_val;

    std::cout << min_sum_of_four << " " << max_sum_of_four << std::endl;

    return 0;
}
