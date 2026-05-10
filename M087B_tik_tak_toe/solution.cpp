#include <bits/stdc++.h>

using namespace std;

bool check_win(const string& board) {
    for (int i = 0; i <= (int)board.length() - 3; ++i) {
        if (board[i] == 'x' && board[i+1] == 'x' && board[i+2] == 'x') {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int current_player = 1; // 1 for "Birinchi", 2 for "Ikkinchi"

    while (true) {
        size_t first_o_idx = s.find('o');

        if (first_o_idx == string::npos) {
            // If no 'o's are found, the game cannot proceed or all moves have been made.
            // If no player won by their move, then "Hech kim" (No one).
            cout << "Hech kim\n";
            break;
        }

        // Current player makes a move: replaces the first 'o' with an 'x'.
        s[first_o_idx] = 'x';

        // Check if this move resulted in a win for the current player.
        if (check_win(s)) {
            if (current_player == 1) {
                cout << "Birinchi\n";
            } else { // current_player == 2
                cout << "Ikkinchi\n";
            }
            break; // Game ends, a player has won.
        }

        // Switch to the other player for the next turn.
        current_player = 3 - current_player; // Toggles between 1 and 2.
    }

    return 0;
}
