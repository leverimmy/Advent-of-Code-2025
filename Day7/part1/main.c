#include <stdio.h>
#include <string.h>
#define N 142
#define M 142

char grid[N][M];

int main() {
    freopen("../assets/input.txt", "r", stdin);
    int n = 0;
    while (scanf("%s", grid[n]) != EOF) {
        n++;
    }
    int m = strlen(grid[0]), result = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            char ch = grid[i][j];
            if (i & 1) {
                if (ch == '|') {
                    char nch = grid[i + 1][j];
                    if (nch == '^') {
                        grid[i + 1][j - 1] = grid[i + 1][j + 1] = '|';
                        result++;
                    } else {
                        grid[i + 1][j] = '|';
                    }
                }
            } else {
                if (ch == 'S') {
                    grid[i + 1][j] = '|';
                }
                if (ch == '|') {
                    grid[i + 1][j] = '|';
                }
            }
        }
    }
    printf("%d\n", result);
    return 0;
}

// Answer: 1687
