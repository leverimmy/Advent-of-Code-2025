#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int getNum(int idx, const string& line) {
    while (line[idx] == ' ') idx++;
    int num = 0;
    for (int i = idx; i < line.size() && line[i] != ' '; i++) {
        num = num * 10 + (line[i] - '0');
    }
    return num;
}

int main() {
    ifstream input("../assets/input.txt");
    vector<string> lines;
    string line;
    while (getline(input, line)) {
        lines.push_back(line);
    }
    
    int n = lines.size(), m = lines[0].size();
    ll result = 0;
    for (int i = 0; i < m; i++) {
        if (lines[n - 1][i] == '+') {
            ll sum = 0;
            for (int j = 0; j < n - 1; j++) {
                sum += getNum(i, lines[j]);
            }
            result += sum;
        } else if (lines[n - 1][i] == '*') {
            ll prod = 1;
            for (int j = 0; j < n - 1; j++) {
                prod *= getNum(i, lines[j]);
            }
            result += prod;
        }
    }
    cout << result << endl;
    return 0;
}

// Answer: 6757749566978
