#include <stdio.h>

int main(void)
{
    int h, w, n, test;
    scanf("%d", &test);
    while (test--) {
        scanf("%d %d %d", &h, &w, &n);

        printf("%d%02d\n", (n - 1) % h + 1, (n - 1) / h + 1);
    }
    return 0;
}