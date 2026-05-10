#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    int minimum = min({a1, a2, a3});
    int maximum = max({a1, a2, a3});

    int result = maximum - minimum;

    cout << result << endl;

    return 0;
}
