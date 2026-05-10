#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin, s);

    s.erase(remove(s.begin(), s.end(), ' '), s.end());

    long long num = stoll(s);

    num++;

    cout << num << endl;

    return 0;
}
