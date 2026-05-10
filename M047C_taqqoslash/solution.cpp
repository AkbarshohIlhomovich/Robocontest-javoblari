#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    set<int> distinct_numbers;
    distinct_numbers.insert(a);
    distinct_numbers.insert(b);
    distinct_numbers.insert(c);

    cout << distinct_numbers.size() << endl;

    return 0;
}
