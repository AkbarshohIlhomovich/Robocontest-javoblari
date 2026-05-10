#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unsigned int n;
    cin >> n;

    unsigned int c = n & -n;
    unsigned int r = n + c;
    unsigned int next = (((n ^ r) >> 2) / c) | r;

    cout << next << endl;

    return 0;
}
