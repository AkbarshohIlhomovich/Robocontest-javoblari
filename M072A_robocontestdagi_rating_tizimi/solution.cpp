#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int X;
    cin >> X;

    if (X >= 2000) {
        cout << "Master\n";
    } else if (X >= 1800) {
        cout << "Candidate Master\n";
    } else if (X >= 1700) {
        cout << "Expert\n";
    } else if (X >= 1600) {
        cout << "Specialist\n";
    } else {
        cout << "Pupil\n";
    }

    return 0;
}
