#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> dims1(3);
    for (int i = 0; i < 3; ++i) {
        cin >> dims1[i];
    }
    sort(dims1.begin(), dims1.end());

    vector<int> dims2(3);
    for (int i = 0; i < 3; ++i) {
        cin >> dims2[i];
    }
    sort(dims2.begin(), dims2.end());

    bool box2_fits_in_box1 = (dims2[0] <= dims1[0] && dims2[1] <= dims1[1] && dims2[2] <= dims1[2]);
    bool box1_fits_in_box2 = (dims1[0] <= dims2[0] && dims1[1] <= dims2[1] && dims1[2] <= dims2[2]);

    if (box1_fits_in_box2 && box2_fits_in_box1) {
        cout << "Qutilar o'zaro teng" << endl;
    } else if (box2_fits_in_box1) {
        cout << "Birinchi quti ikkinchisidan katta" << endl;
    } else if (box1_fits_in_box2) {
        cout << "Birinchi quti ikkinchisidan kichik" << endl;
    } else {
        cout << "Qutilarni solishtirib bo'lmaydi" << endl;
    }

    return 0;
}
