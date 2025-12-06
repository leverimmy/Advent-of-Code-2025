#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

bool all(int idx, char ch, const vector<string>& lines) {
    for (const string& line : lines) {
        if (line[idx] != ch) {
            return false;
        }
    }
    return true;
}

int getNum(int idx, const vector<string>& lines) {
    int i = 0, num = 0;
    while (i < lines.size() && !isdigit(lines[i][idx])) i++;
    for ( ; i < lines.size() && isdigit(lines[i][idx]); i++) {
        num = num * 10 + (lines[i][idx] - '0');
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
    ll result = 0, buffer = 0;
    char lastOp = ' ';
    for (int i = 0; i < m; i++) {
        if (all(i, ' ', lines)) continue;
        switch (lines[n - 1][i]) {
            case '+':
                result += buffer;
                buffer = 0;
                lastOp = '+';
                break;
            case '*':
                result += buffer;
                buffer = 1;
                lastOp = '*';
                break;
            default:
                break;
        }
        switch (lastOp) {
            case '+':
                buffer += getNum(i, lines);
                break;
            case '*':
                buffer *= getNum(i, lines);
                break;
            default:
                break;
        }
    }
    cout << result + buffer << endl;
    return 0;
}

// Answer: 10603075273949
