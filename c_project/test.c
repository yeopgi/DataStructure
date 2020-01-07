#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *ptr = (char*)malloc(11);
    scanf("%s", ptr);

    printf("%s\n", ptr);
    free(ptr);
    return 0;
}