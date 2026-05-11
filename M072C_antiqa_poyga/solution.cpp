#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int dilshod_rem;
    int friend1_rem;
    int friend2_rem;
    int friend3_rem;

    cin >> dilshod_rem >> friend1_rem >> friend2_rem >> friend3_rem;

    int count_friends_with_more_fives = 0;

    // A student has more '5's if they have fewer '5's remaining until 1000.
    if (friend1_rem < dilshod_rem) {
        count_friends_with_more_fives++;
    }
    if (friend2_rem < dilshod_rem) {
        count_friends_with_more_fives++;
    }
    if (friend3_rem < dilshod_rem) {
        count_friends_with_more_fives++;
    }

    cout << count_friends_with_more_fives << endl;

    return 0;
}
