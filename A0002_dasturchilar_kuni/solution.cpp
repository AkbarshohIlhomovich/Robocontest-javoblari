#include <bits/stdc++.h>

using namespace std;

bool is_leap_year(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int year;
    cin >> year;

    vector<int> days_in_month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (is_leap_year(year)) {
        days_in_month[2] = 29;
    }

    int target_day_of_year = 256; 

    int current_day_sum = 0;
    int day = 0;
    int month = 0;

    for (int m = 1; m <= 12; ++m) {
        if (current_day_sum + days_in_month[m] >= target_day_of_year) {
            month = m;
            day = target_day_of_year - current_day_sum;
            break;
        }
        current_day_sum += days_in_month[m];
    }

    cout << setfill('0') << setw(2) << day << "/"
              << setfill('0') << setw(2) << month << "/"
              << setfill('0') << setw(4) << year << endl;

    return 0;
}
