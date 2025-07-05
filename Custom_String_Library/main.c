// main.c (Test Framework)
#include <stdio.h>
#include "myString.h"

int main()
{
    printf("--- Testing Custom String Library ---\n\n");

    // StrLen
    printf("StrLen: %zu\n", StrLen("Hello"));

    // StrCpy
    char buffer1[20];
    StrCpy(buffer1, "Test");
    printf("StrCpy: %s\n", buffer1);

    // StrCmp
    printf("StrCmp: %d\n", StrCmp("abc", "abd"));

    // StrChr
    printf("StrChr: %c\n", *StrChr("abc", 'b'));

    // StrDup
    char *dup = StrDup("copy");
    printf("StrDup: %s\n", dup);

    // StrJoin
    char *joined = StrJoin("first", "second");
    printf("StrJoin: %s\n", joined);

    // StrSplit
    char **tokens = StrSplit("a,b,c", ',');
    printf("StrSplit: ");
    for (int i = 0; tokens[i] != NULL; i++)
        printf("[%s] ", tokens[i]);
    printf("\n");

    // StrTrim
    printf("StrTrim: '%s'\n", StrTrim("   hello world  "));

    // StrRev
    char revStr[] = "reverse";
    StrRev(revStr);
    printf("StrRev: %s\n", revStr);

    // StrReplace
    char replStr[] = "abcabc";
    StrReplace(replStr, 'a', 'x');
    printf("StrReplace: %s\n", replStr);

    // StrToInt
    printf("StrToInt: %ld\n", StrToInt("  -123abc"));

    // StrStr
    printf("StrStr: %s\n", StrStr("hello world", "world"));

    // StrNCpy
    char buffer2[10];
    StrNCpy(buffer2, "abcde", 3);
    printf("StrNCpy: %s\n", buffer2);

    // StrTok
    char str[] = "a:b:c";
    char *tok = StrTok(str, ':');
    while (tok)
    {
        printf("StrTok: %s\t", tok);
        tok = StrTok(NULL, ':');
    }
    printf("\n");

    // StrHexToInt
    printf("StrHexToInt: %u\n", StrHexToInt("0xC0FFEE"));

    return 0;
}
