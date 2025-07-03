#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Return the size of String till first NULL character that appears (excluding the NULL Character).
size_t StrLen(char *str)
{
    size_t length = 0;
    if (str == NULL)
        return length;
    for (char *cursor = str; *cursor != '\0'; cursor = cursor + 1)
        length++;
    return length;
}

// Return the size of String till first NULL character that appears or if no NULL character is found then return the Max Size.
size_t StrLen_Max(char *str, size_t MaxSize)
{
    size_t length = 0;
    if (MaxSize < 0)
        if (str == NULL)
            return length;

    char *cursor = str;
    while (*cursor != '\0')
    {
        if (length == MaxSize)
            return MaxSize;
        cursor = cursor + 1;
        length++;
    }
    return length;
}

// Copy the String from Source to Destination
char *StrCpy(char *dest, char *src)
{
    if (src == NULL || dest == NULL)
        return NULL;
    else if (src == dest)
        return src;
    else
    {
        char *p = src, *q = dest;
        while (*p != '\0')
        {
            *q = *p;
            p++;
            q++;
        }
        *q = '\0';

        return dest;
    }
}

// Copy String from Source to Destination with fixed length. Safer version of StrCpy. Strict size copy with no NULL termination (in some cases where source lenght is equal to n).
char *StrNCpy(char *dest, char *src, size_t n)
{
    if (src == NULL || dest == NULL)
        return NULL;
    else if (src == dest)
    {
        //
    }
    else
    {
        size_t srcLen = StrLen(src);
        char *p = src, *q = dest;
        while (*p != '\0' && n > 0)
        {
            *q = *p;
            p++;
            q++;
            n--;
        }
        if (n != 0)
        {
            while (n > 0)
            {
                *q = '\0';
                q++;
                n--;
            }
        }
        return dest;
    }
}

// Compare two strings in lexicographical order.
int StrCmp(char *lhs, char *rhs)
{
    if (lhs == NULL || rhs == NULL)
        return 0;
    while (*lhs != '\0' && *rhs != '\0')
    {
        if (*lhs - *rhs != 0)
            return *lhs - *rhs;

        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

// Return pointer to the first occurence of a given character in a given string.
char *StrChr(char *str, char c)
{
    if (str == NULL)
        return NULL;
    char *cursor = str;
    while (*cursor != '\0')
    {
        if (*cursor == c)
            return cursor;

        cursor++;
    }
    if (*cursor == '\0' && c == '\0')
        return cursor;
    else
        return NULL;
}

// Allocate new memory and copy the given string and return the pointer to this newly copied string.
char *StrDup(char *str)
{
    if (str == NULL)
        return NULL;
    char *newStr = malloc(StrLen(str) + 1);
    char *p = str, *q = newStr;
    while (*p != '\0')
    {
        *q = *p;
        p++;
        q++;
    }
    *q = '\0';
    return newStr;
}

// Join two strings in a newly allocated memory and return its pointer.
char *StrJoin(char *str1, char *str2)
{
    if (str1 == NULL && str2 == NULL)
        return NULL;
    else if (str1 == NULL)
        return StrDup(str2);
    else if (str2 == NULL)
        return StrDup(str1);
    char *newStr = malloc(StrLen(str1) + StrLen(str2) + 1);
    char *p = str1, *q = newStr;
    while (*p != '\0')
    {
        *q = *p;
        q++;
        p++;
    }
    p = str2;
    while (*p != '\0')
    {
        *q = *p;
        q++;
        p++;
    }
    *q = '\0';
    return newStr;
}

// Split the String into Character Array by a Delimiter
char **StrSplit(char *str, char dl)
{
    /*Check for NULL input.*/
    if (str == NULL)
        return NULL;

    unsigned long long int token_count = 0;
    unsigned long long int token_index = 0;

    int deLimiter_found = 0;

    /*Count Number of Tokens/Substrings.*/
    for (char *cursor = str; *cursor != '\0'; cursor++)
    {
        if (*cursor == dl)
        {
            deLimiter_found = 1;
            token_count++;
        }
    }
    token_count++;

    /*Allocate Space for Array of Strings.*/
    char **split = malloc((token_count + 1) * sizeof(char *));

    /*Check for Empty String*/
    if (*str == '\0')
    {
        split[0] = NULL;
        return split;
    }

    /*Check for no Delimiters in the string.*/
    if (!deLimiter_found)
    {
        split[0] = malloc(StrLen(str) + 1);
        StrCpy(split[0], str);
        split[1] = NULL;
        return split;
    }

    /*Start with splitting the String.*/
    char *start = str, *end = NULL;

    for (char *cursor = str; *cursor != '\0'; cursor++)
    {
        if (*cursor == dl)
        {
            end = cursor;
            char *substr = malloc(end - start + 1);
            char *temp_substr = substr;
            for (char *p = start; p != end; p++)
            {
                *temp_substr = *p;
                temp_substr++;
            }
            *temp_substr = '\0';
            split[token_index++] = substr;
            start = end + 1;
        }
    }
    end = str + StrLen(str);

    /*Copy the Remaining String after the last delimiter*/
    char *substr = malloc(end - start + 1);
    char *temp_substr = substr;
    for (char *cursor = start; *cursor != '\0'; cursor++)
    {
        *temp_substr = *cursor;
        temp_substr++;
    }
    *temp_substr = '\0';
    split[token_index++] = substr;

    split[token_index] = NULL;

    return split;
}

// Trim the given String by removing leading and trailing spaces from a string.

char *StrTrim(char *str)
{
    /*Check for NULL string*/
    if (str == NULL)
        return NULL;

    char *start = NULL, *end = NULL;

    /*Check for first non space character.*/
    char *cursor = str;
    while (*cursor != '\0' && *cursor == ' ')
        cursor++;

    /*If string don't have non space characters.*/
    if (*cursor == '\0')
    {
        char *trim = malloc(1);
        trim[0] = '\0';
        return trim;
    }

    start = cursor;

    /*Check for last non space character. Go to end of string and traverse in reverse till non space character is found.*/
    while (*cursor != '\0')
        cursor++;

    end = cursor - 1;

    while (*end == ' ')
        end--;

    char *trim = malloc(end - start + 1 + 1);
    char *trim_temp = trim;

    /*Copy the string without spaces.*/
    while (start <= end)
    {
        *trim_temp++ = *start++;
    }
    *trim_temp = '\0';

    return trim;
}

// Reverse the string in its place. No extra memory used.
void StrRev(char *str)
{
    if (str == NULL)
        return;

    char *start = str, *end = NULL;

    /*Find the end of string*/
    while (*start != '\0')
        start++;

    end = start - 1;
    start = str;

    char temp;
    /*Swap start and end, till the whole string is reversed.*/
    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Replace an occurance of a character with another input character.
void StrReplace(char *str, char oldChar, char newChar)
{
    if (oldChar == newChar)
        return;
    else if (str == NULL)
        return;
    char *cursor = str;
    while (*cursor != '\0')
    {
        if (*cursor == oldChar)
        {
            *cursor = newChar;
        }
        cursor++;
    }
}

// Convert input string to Integer. Parse Digits from Left to Right till a non-digit character is found.
int StrToInt(char *str)
{
    int isPositive = 0;
    int result = 0;

    /*Check for first digit.*/
    char *cursor = str;
    while (*cursor != '\0' && *cursor != '-' && *cursor != '+' && (*cursor < '0' || *cursor > '9'))
    {

        cursor++;
    }

    if (*cursor == '-')
    {
        cursor++;
        isPositive = -1;
    }
    else if (*cursor == '+')
    {
        isPositive = 1;
        cursor++;
    }
    else
        isPositive = 1;

    /*Start with the conversion to integer.*/
    while (*cursor >= '0' && *cursor <= '9')
    {
        /*Check for Overflow*/
        int digit = *cursor - '0';
        if (isPositive == 1 && result > (INT_MAX - digit) / 10)
            return INT_MAX;

        if (isPositive == -1 && result > (-(INT_MIN + digit)) / 10)
            return INT_MIN;

        result = (result * 10) + (digit);
        cursor++;
    }

    return (result * isPositive);
}

// Find substring in a string.
char *StrStr(char *str, char *sub)
{
    if (str == NULL || sub == NULL)
        return NULL;
    if (*sub == '\0')
        return str;

    char *strFound = NULL;
    char *cursor = str;

    /*Check for occurence of first character of substring.*/
    while (*cursor != '\0')
    {
        if (*cursor != *sub)
            cursor++;
        else
        {
            /*Substring might be present.*/
            strFound = cursor;
            char *sub_cursor = sub;
            while (*sub_cursor != '\0')
            {
                if (*cursor == *sub_cursor)
                {
                    cursor++;
                    sub_cursor++;
                }
                else
                    break;
            }
            cursor = strFound;
            /*SubString Found!*/
            if (*sub_cursor == '\0')
                return strFound;

            cursor++;
        }
    }
    return NULL;
}

// Concatinate two strings
char *StrCat(char *dest, char *src)
{
    if (src == NULL || dest == NULL)
        return NULL;

    char *cursorD = dest;
    // char *cursorS = src;

    while (*cursorD != '\0')
        cursorD++;

    while (*src != '\0')
    {
        *cursorD++ = *src++;
    }
    *cursorD = '\0';

    return dest;
}