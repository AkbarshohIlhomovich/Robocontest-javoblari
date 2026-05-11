#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    queue<long long> q;
    int count = 0;

    q.push(0); // Start with a placeholder '0' to generate initial numbers 5 and 7

    while (!q.empty()) {
        long long current_num = q.front();
        q.pop();

        // Generate a new number by appending '5'
        long long next_num_5 = current_num * 10 + 5;

        // Check if the generated number is within the limit 'n' and is a positive number
        if (next_num_5 <= n && next_num_5 > 0) {
            count++; // Increment count if it's a valid "yoqimli" number
            q.push(next_num_5); // Add it to the queue to generate further numbers
        }

        // Generate a new number by appending '7'
        long long next_num_7 = current_num * 10 + 7;

        // Check if the generated number is within the limit 'n' and is a positive number
        if (next_num_7 <= n && next_num_7 > 0) {
            count++; // Increment count if it's a valid "yoqimli" number
            q.push(next_num_7); // Add it to the queue to generate further numbers
        }
    }

    cout << count << endl;

    return 0;
}
