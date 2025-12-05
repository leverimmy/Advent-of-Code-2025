#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int LEN = 12;

ll get_max_val(const string& s) {
    int n = s.length();
    vector<vector<ll>> dp(n, vector<ll>(LEN + 1, 0));
    for (int i = 0; i < n; i++) {
        dp[i][1] = s[i] - '0';
    }
    for (int len = 2; len <= LEN; len++) {
        for (int i = 0; i < n; i++) {
            for (int j = len - 2; j < i; j++) {
                dp[i][len] = max(dp[i][len], dp[j][len - 1] * 10 + (s[i] - '0'));
            }
        }
    }
    ll max_val = 0;
    for (int i = 0; i < n; i++) {
        max_val = max(max_val, dp[i][LEN]);
    }
    return max_val;
}

int main() {
    ifstream infile("../assets/input.txt");
    string line;
    ll sum = 0;
    while (getline(infile, line)) {
        sum += get_max_val(line);
    }
    cout << sum << endl;
    return 0;
}

// Answer: 171846613143331
