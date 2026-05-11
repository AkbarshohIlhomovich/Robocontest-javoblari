#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_input;
    cin >> n_input;

    long long n = n_input;

    int count = 0;
    queue<long long> q;

    q.push(1);

    while (!q.empty()) {
        long long current_num = q.front();
        q.pop();

        count++;

        long long next_num_0 = current_num * 10;
        if (next_num_0 <= n) {
            q.push(next_num_0);
        }

        long long next_num_1 = current_num * 10 + 1;
        if (next_num_1 <= n) {
            q.push(next_num_1);
        }
    }

    cout << count << endl;

    return 0;
}
