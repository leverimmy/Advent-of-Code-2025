#include <stdio.h>
#define RANGE 100

int main() {
    freopen("../assets/input.txt", "r", stdin);
    char op;
    int num, current = 50, result = 0;
    while (scanf("%c%d\n", &op, &num) != EOF) {
        switch (op) {
            case 'L':
                current = (current - num + RANGE) % RANGE;
                break;
            case 'R':
                current = (current + num) % RANGE;
                break;
            default:
        }
        result += current == 0;
    }
    printf("%d\n", result);
    return 0;
}

// Answer: 1040
