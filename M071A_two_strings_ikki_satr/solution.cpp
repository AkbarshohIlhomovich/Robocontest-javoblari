#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;

    vector<int> freqS(26, 0);
    vector<int> freqT(26, 0);

    for (char c : S) {
        freqS[c - 'a']++;
    }

    for (char c : T) {
        freqT[c - 'a']++;
    }

    int total_matches = 0;
    for (int i = 0; i < 26; ++i) {
        total_matches += min(freqS[i], freqT[i]);
    }

    cout << total_matches << endl;

    return 0;
}
