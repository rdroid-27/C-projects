#include <stdio.h>
#include "myString.h"
#include <string.h>
#include <assert.h>

void display(int a, int b)
{
    printf("%d %d \n", a, b);
}

int main()
{
    // char big[1000];
    // memset(big, 'a', 999);
    // big[999] = '\0';
    // char *s = StrJoin(big, "END");
    // printf("%c...%s\n", s[0], s + 996); // Should show aaaa...END

    char **res = StrSplit("a b  c", ' ');
    for (int i = 0; res[i] != NULL; i++)
        printf("[%s]\n", res[i]);

    free(res);
    return 0;
}