#include <stdio.h>
#define RANGE 100

int main() {
    freopen("../assets/input.txt", "r", stdin);
    char op;
    int num, current = 50, result = 0;
    while (scanf("%c%d\n", &op, &num) != EOF) {
        switch (op) {
            case 'L':
                result += current ? (num - current + RANGE) / RANGE : num / RANGE;
                current = ((current - num) % RANGE + RANGE) % RANGE;
                break;
            case 'R':
                result += current ? (num - (RANGE - current) + RANGE) / RANGE : num / RANGE;
                current = (current + num) % RANGE;
                break;
            default:
        }
    }
    printf("%d\n", result);
    return 0;
}

// Answer: 6027
