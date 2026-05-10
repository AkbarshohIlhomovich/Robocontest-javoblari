#include <bits/stdc++.h>

using namespace std;

vector<int> read_coordinates() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> coords;
    int val;
    while (iss >> val) {
        coords.push_back(val);
    }
    return coords;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> x_coords = read_coordinates();
    vector<int> y_coords = read_coordinates();

    int n = x_coords.size();

    if (n <= 2) {
        cout << "HA\n";
        return 0;
    }

    long long x0 = x_coords[0];
    long long y0 = y_coords[0];
    long long x1 = x_coords[1];
    long long y1 = y_coords[1];

    for (int i = 2; i < n; ++i) {
        long long xi = x_coords[i];
        long long yi = y_coords[i];

        if ((x1 - x0) * (yi - y0) != (xi - x0) * (y1 - y0)) {
            cout << "YO'Q\n";
            return 0;
        }
    }

    cout << "HA\n";

    return 0;
}
