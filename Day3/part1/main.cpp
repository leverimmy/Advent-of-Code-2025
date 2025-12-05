#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int get_max_val(const string& s) {
    int len = s.length();
    int max_val = -1, current_val = -1;
    for (int i = 0; i < len; i++) {
        if ((current_val == -1 || max_val * 10 + (s[i] - '0') > current_val) && max_val != -1) {
            current_val = max_val * 10 + (s[i] - '0');
        }
        max_val = max(max_val, s[i] - '0');
    }
    return current_val;
}

int main() {
    ifstream infile("../assets/input.txt");
    string line;
    int sum = 0;
    while (getline(infile, line)) {
        sum += get_max_val(line);
    }
    cout << sum << endl;
    return 0;
}

// Answer: 17324
