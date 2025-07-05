#ifndef MY_STRING_H
#define MY_STRING_H

#include <stddef.h>
#include <limits.h>
#include <stdlib.h> // for malloc, free

// ===== Basic Operations =====
size_t StrLen(const char *str);
size_t StrLen_Max(const char *str, size_t MaxSize);
char *StrDup(const char *str);
char *StrCpy(char *dest, const char *src);
char *StrNCpy(char *dest, const char *src, size_t n);
char *StrJoin(const char *str1, const char *str2);
char *StrCat(char *dest, const char *src);
int StrCmp(const char *lhs, const char *rhs);
char *StrChr(const char *str, char c);

// ===== Advanced Utilities =====
char **StrSplit(const char *str, char dl);
char *StrTrim(const char *str);
void StrRev(char *str);
void StrReplace(char *str, char oldChar, char newChar);
long StrToInt(const char *str);
char *StrStr(const char *str, const char *sub);
char *StrTok(char *str, char dl);
unsigned int StrHexToInt(const char *str);

#endif // MY_STRING_H
