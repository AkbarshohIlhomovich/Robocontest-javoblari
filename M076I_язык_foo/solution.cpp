#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    multiset<long long> a;
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        a.insert(val);
    }

    long long result = 0;

    while (a.size() > 2) {
        long long smallest = *a.begin();
        
        long long second_largest = *prev(a.end(), 2);

        long long x = smallest + second_largest;
        result += x;

        a.erase(a.begin());
        
        a.erase(prev(a.end(), 2));

        a.insert(x);
    }

    long long sum_a_final = 0;
    for (long long val : a) {
        sum_a_final += val;
    }

    cout << sum_a_final + result << endl;

    return 0;
}
