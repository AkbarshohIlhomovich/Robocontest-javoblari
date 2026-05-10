#include <bits/stdc++.h>

using namespace std;

// Function to check if a string is a valid Python snake_case variable name
// and convert it to JavaScript camelCase if valid.
optional<string> convert_python_to_js(const string& s) {
    if (s.empty()) {
        return nullopt;
    }

    string result = "";
    bool next_char_upper = false;

    // Rule: Cannot start or end with an underscore.
    if (s[0] == '_' || s.back() == '_') {
        return nullopt;
    }

    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];

        if (c == '_') {
            // Rule: Cannot have consecutive underscores.
            if (i + 1 < s.length() && s[i+1] == '_') {
                return nullopt;
            }
            // Rule: Underscore must be followed by a lowercase letter for valid Python style.
            // And underscore cannot be the last character, which is already handled by s.back() check.
            if (i + 1 >= s.length() || !islower(static_cast<unsigned char>(s[i+1]))) {
                 return nullopt;
            }
            next_char_upper = true;
        } else if (isalpha(static_cast<unsigned char>(c))) {
            // Rule: All letters in a Python name must be lowercase.
            if (isupper(static_cast<unsigned char>(c))) {
                return nullopt; // Python name cannot have uppercase letters
            }
            if (next_char_upper) {
                result += static_cast<char>(toupper(static_cast<unsigned char>(c)));
                next_char_upper = false;
            } else {
                result += c;
            }
        } else {
            // Rule: Only letters and underscores are allowed.
            return nullopt;
        }
    }
    
    return result;
}

// Function to check if a string is a valid JavaScript camelCase variable name
// and convert it to Python snake_case if valid.
optional<string> convert_js_to_python(const string& s) {
    if (s.empty()) {
        return nullopt;
    }

    string result = "";

    // Rule: Cannot contain underscores.
    if (s.find('_') != string::npos) {
        return nullopt;
    }

    // Rule: First letter must be lowercase.
    if (isupper(static_cast<unsigned char>(s[0]))) {
        return nullopt;
    }

    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];

        if (isalpha(static_cast<unsigned char>(c))) {
            if (isupper(static_cast<unsigned char>(c))) {
                result += '_';
                result += static_cast<char>(tolower(static_cast<unsigned char>(c)));
            } else {
                result += c;
            }
        } else {
            // Rule: Only letters are allowed (no underscores, no digits, no other symbols in variable name).
            return nullopt;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string full_line;
    getline(cin, full_line);

    string variable_name_str;
    string assignment_suffix_str = ""; 

    size_t eq_pos = full_line.find('=');
    if (eq_pos != string::npos) {
        // Find the end of the variable name (last non-whitespace character before '=')
        size_t var_name_end_idx = eq_pos;
        while (var_name_end_idx > 0 && isspace(static_cast<unsigned char>(full_line[var_name_end_idx - 1]))) {
            var_name_end_idx--;
        }
        
        variable_name_str = full_line.substr(0, var_name_end_idx);
        assignment_suffix_str = full_line.substr(var_name_end_idx); // This includes the spaces before '=' and the '=' itself, and everything after.
    } else {
        variable_name_str = full_line;
    }

    optional<string> python_to_js_result = convert_python_to_js(variable_name_str);
    optional<string> js_to_python_result = convert_js_to_python(variable_name_str);

    if (python_to_js_result.has_value()) {
        cout << python_to_js_result.value() << assignment_suffix_str << endl;
    } else if (js_to_python_result.has_value()) {
        cout << js_to_python_result.value() << assignment_suffix_str << endl;
    } else {
        cout << "Xatolik" << endl;
    }

    return 0;
}
