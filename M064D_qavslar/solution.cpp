#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    vector<char> str_vec;
    vector<int> open_paren_indices_stack; // Stores indices of unmatched '('
    vector<long long> dp; // dp[k] stores the number of good substrings that *end* at index k
    vector<int> paren_match_idx; // paren_match_idx[k] is p if str_vec[k] is ')' and matches str_vec[p]. If str_vec[k] is '(', value is -1.
    long long total_rbs_count = 0;

    for (char command : s) {
        if (command == '(' || command == ')') {
            // Append character
            str_vec.push_back(command);
            int current_idx = str_vec.size() - 1;
            dp.push_back(0); // Initialize dp[current_idx]
            paren_match_idx.push_back(-1); // Default to -1

            if (command == '(') {
                open_paren_indices_stack.push_back(current_idx);
            } else { // command == ')'
                if (!open_paren_indices_stack.empty()) {
                    int match_idx = open_paren_indices_stack.back();
                    open_paren_indices_stack.pop_back();
                    
                    paren_match_idx[current_idx] = match_idx; // Store matching index
                    
                    dp[current_idx] = 1; // S[match_idx...current_idx] is a good string of type (X)
                    if (match_idx > 0) {
                        // Add good strings of type Y(X), where Y is an RBS ending at match_idx - 1
                        dp[current_idx] += dp[match_idx - 1];
                    }
                    total_rbs_count += dp[current_idx];
                }
                // If stack is empty, it's an unmatched ')'. No new good strings can end here, dp[current_idx] remains 0.
            }
        } else { // command == '-'
            // Remove character
            int current_idx = str_vec.size() - 1;
            char removed_char = str_vec[current_idx];

            if (removed_char == '(') {
                open_paren_indices_stack.pop_back(); // Pop the '(' that was at current_idx
            } else { // removed_char == ')'
                // Retrieve the matching '(' index
                int match_idx = paren_match_idx[current_idx];
                
                // If it was a matched ')', we revert the changes made when it was added
                if (match_idx != -1) { 
                    open_paren_indices_stack.push_back(match_idx); // Put the matching '(' back on stack
                    total_rbs_count -= dp[current_idx]; // Decrement total count
                }
            }
            
            str_vec.pop_back();
            dp.pop_back();
            paren_match_idx.pop_back();
        }
        cout << total_rbs_count << "\n";
    }

    return 0;
}
