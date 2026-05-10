#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long X;
    cin >> X;

    long long balance = 100;
    int years = 0;

    while (balance < X) {
        long long interest = balance / 100;
        balance += interest;
        years++;
    }

    cout << years << endl;

    return 0;
}
