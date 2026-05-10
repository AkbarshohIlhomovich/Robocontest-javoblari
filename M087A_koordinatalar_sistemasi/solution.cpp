#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    set<int> ali_coords;
    set<int> vali_coords;
    set<int> gani_coords;

    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        ali_coords.insert(x);
        vali_coords.insert(y);
        gani_coords.insert(z);
    }

    int ali_score = ali_coords.size();
    int vali_score = vali_coords.size();
    int gani_score = gani_coords.size();

    int max_score = 0;
    max_score = max(max_score, ali_score);
    max_score = max(max_score, vali_score);
    max_score = max(max_score, gani_score);

    if (ali_score == max_score) {
        cout << "Ali\n";
    }
    if (vali_score == max_score) {
        cout << "Vali\n";
    }
    if (gani_score == max_score) {
        cout << "G'ani\n";
    }

    return 0;
}
