#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> memo;

int solve(string s) {
    if (s.empty()) {
        return 0;
    }
    if (memo.count(s)) {
        return memo[s];
    }

    int max_happiness_for_this_state = 0;
    int n = s.length();

    int i = 0;
    while (i < n) {
        int j = i;
        while (j + 1 < n && s[j+1] == s[i]) {
            j++;
        }
        
        int block_len = j - i + 1;

        string next_s = "";
        if (i > 0) {
            next_s += s.substr(0, i);
        }
        if (j + 1 < n) {
            next_s += s.substr(j + 1);
        }
        
        int current_happiness_gain = (block_len == 3) ? 1 : 0;
        
        max_happiness_for_this_state = max(max_happiness_for_this_state, 
                                            current_happiness_gain + solve(next_s));
        
        i = j + 1;
    }

    return memo[s] = max_happiness_for_this_state;
}

void process_test_case() {
    string s;
    cin >> s;

    map<char, char> char_mapping;
    char next_char_alias = 'a';
    for (char c : s) {
        if (char_mapping.find(c) == char_mapping.end()) {
            char_mapping[c] = next_char_alias++;
        }
    }

    for (char &c : s) {
        c = char_mapping[c];
    }

    memo.clear(); 
    
    cout << solve(s) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        process_test_case();
    }

    return 0;
}
