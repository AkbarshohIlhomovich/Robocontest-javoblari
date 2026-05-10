#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') { // Only empty spots can be considered for new participants
            // Check if the left neighbor is empty or if it's the first spot (no left neighbor)
            bool left_ok = (i == 0 || s[i - 1] == '0');
            
            // Check if the right neighbor is empty or if it's the last spot (no right neighbor)
            bool right_ok = (i == n - 1 || s[i + 1] == '0');

            // If the current spot is empty and both its neighbors (or boundaries) are empty,
            // a new participant can be placed here.
            if (left_ok && right_ok) {
                count++; // Place a participant
                
                // If a participant is placed at index 'i', this spot effectively becomes '1'.
                // According to the rule, a new participant cannot be adjacent to any other participant.
                // This means the spot at 'i+1' can no longer be chosen for a new participant
                // because its left neighbor (index 'i', now occupied) would violate the rule.
                // Therefore, we must skip checking index 'i+1'.
                // By incrementing 'i' here, and then the '++i' in the for loop executes,
                // 'i' will be advanced by 2 in total (i.e., i -> i+1 -> i+2),
                // effectively starting the next check from index 'i+2'.
                i++; 
            }
        }
    }

    cout << count << endl;

    return 0;
}
