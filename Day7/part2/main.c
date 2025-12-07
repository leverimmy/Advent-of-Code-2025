#include <stdio.h>
#include <string.h>
typedef long long ll;
#define N 142
#define M 142

char grid[N][M];
ll dp[N][M];

int main() {
    freopen("../assets/input.txt", "r", stdin);
    int n = 0;
    while (scanf("%s", grid[n]) != EOF) {
        n++;
    }
    int m = strlen(grid[0]);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            char ch = grid[i][j];
            if (i & 1) {
                if (ch == '|') {
                    char nch = grid[i + 1][j];
                    if (nch == '^') {
                        grid[i + 1][j - 1] = grid[i + 1][j + 1] = '|';
                        dp[i + 1][j - 1] += dp[i][j];
                        dp[i + 1][j + 1] += dp[i][j];
                    } else {
                        grid[i + 1][j] = '|';
                        dp[i + 1][j] += dp[i][j];
                    }
                }
            } else {
                if (ch == 'S') {
                    dp[i][j] = 1;

                    grid[i + 1][j] = '|';
                    dp[i + 1][j] += dp[i][j];
                }
                if (ch == '|') {
                    grid[i + 1][j] = '|';
                    dp[i + 1][j] += dp[i][j];
                }
            }
        }
    }
    ll result = 0;
    for (int j = 0; j < m; j++) {
        result += dp[n - 1][j];
    }
    printf("%lld\n", result);
    return 0;
}

// Answer: 390684413472684
