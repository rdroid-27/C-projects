#include "myString.h"

/**
@brief  Calculate the length of a null-terminated string.
@param  str  Pointer to the input string.
@return Number of characters before the null terminator.
*/
size_t StrLen(const char *str)
{
    size_t length = 0;
    if (str == NULL)
        return length;
    for (const char *cursor = str; *cursor != '\0'; cursor = cursor + 1)
        length++;
    return length;
}

/**
@brief  Get string length with a maximum limit.
@param  str  Input string
@param  MaxSize  Maximum characters to scan
@return Length up to MaxSize or null terminator
*/
size_t StrLen_Max(const char *str, size_t MaxSize)
{
    size_t length = 0;
    if (MaxSize < 0)
        if (str == NULL)
            return length;

    const char *cursor = str;
    while (*cursor != '\0')
    {
        if (length == MaxSize)
            return MaxSize;
        cursor = cursor + 1;
        length++;
    }
    return length;
}

/**
@brief  Create a heap copy of a string.
@return Pointer to new string or NULL.
*/
char *StrDup(const char *str)
{
    if (str == NULL)
        return NULL;
    char *newStr = malloc(StrLen(str) + 1);
    const char *p = str;
    char *q = newStr;
    while (*p != '\0')
    {
        *q = *p;
        p++;
        q++;
    }
    *q = '\0';
    return newStr;
}

/**
@brief  Copy string from src to dest.
@return Pointer to dest.
*/
char *StrCpy(char *dest, const char *src)
{
    if (src == NULL || dest == NULL)
        return NULL;
    else if (src == dest)
        return (char *)src;
    else
    {
        const char *p = src;
        char *q = dest;
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

/**
@brief  Copy at most n characters from src to dest.
@note   Pads with '\0' if src is shorter than n.
*/
char *StrNCpy(char *dest, const char *src, size_t n)
{
    if (src == NULL || dest == NULL)
        return NULL;
    else if (src == dest)
    {
        return (char *)src;
    }
    else
    {
        size_t srcLen = StrLen(src);
        const char *p = src;
        char *q = dest;
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

/**
@brief  Join two strings into newly allocated memory.
@return Pointer to newly allocated string.
*/
char *StrJoin(const char *str1, const char *str2)
{
    if (str1 == NULL && str2 == NULL)
        return NULL;
    else if (str1 == NULL)
        return StrDup(str2);
    else if (str2 == NULL)
        return StrDup(str1);
    char *newStr = malloc(StrLen(str1) + StrLen(str2) + 1);
    const char *p = str1;
    char *q = newStr;
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

/**
@brief  Append src to end of dest.
@return Pointer to destination.
*/
char *StrCat(char *dest, const char *src)
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

/**
@brief  Compare two strings lexicographically.
@return Difference between first unmatched characters.
*/
int StrCmp(const char *lhs, const char *rhs)
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

/**
@brief  Locate first occurrence of a character in string.
@return Pointer to the character, or NULL if not found.
*/
char *StrChr(const char *str, char c)
{
    if (str == NULL)
        return NULL;
    const char *cursor = str;

    while (*cursor != '\0')
    {
        if (*cursor == c)
            return (char *)cursor;

        cursor++;
    }
    if (*cursor == '\0' && c == '\0')
    {
        return (char *)cursor;
    }
    else
        return NULL;
}

/**
@brief  Split string into array of strings by delimiter.
@return Null-terminated array of strings.
*/
char **StrSplit(const char *str, char dl)
{
    /*Check for NULL input.*/
    if (str == NULL)
        return NULL;

    unsigned long long int token_count = 0;
    unsigned long long int token_index = 0;

    int deLimiter_found = 0;

    /*Count Number of Tokens/Substrings.*/
    for (const char *cursor = str; *cursor != '\0'; cursor++)
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
    const char *start = str;
    const char *end = NULL;

    for (const char *cursor = str; *cursor != '\0'; cursor++)
    {
        if (*cursor == dl)
        {
            end = cursor;
            char *substr = malloc(end - start + 1);
            char *temp_substr = substr;
            for (const char *p = start; p != end; p++)
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
    for (const char *cursor = start; *cursor != '\0'; cursor++)
    {
        *temp_substr = *cursor;
        temp_substr++;
    }
    *temp_substr = '\0';
    split[token_index++] = substr;

    split[token_index] = NULL;

    return split;
}

/**
@brief  Trim leading and trailing spaces.
@return Pointer to new trimmed string allocated in heap.
*/
char *StrTrim(const char *str)
{
    /*Check for NULL string*/
    if (str == NULL)
        return NULL;

    const char *start = NULL;
    const char *end = NULL;

    /*Check for first non space character.*/
    const char *cursor = str;
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

/**
@brief  Reverse a string in-place.
*/
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

/**
@brief  Replace all occurrences of a character.
*/
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

/**
@brief  Convert string to integer (handles +/- sign).
@return Converted int or INT_MAX/INT_MIN on overflow.
*/
long StrToInt(const char *str)
{
    int isPositive = 0;
    long result = 0;

    /*Check for first digit.*/
    const char *cursor = str;
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

/**
@brief  Locate a substring in a string.
@return Pointer to the first match or NULL.
*/
char *StrStr(const char *str, const char *sub)
{
    if (str == NULL || sub == NULL)
        return NULL;
    if (*sub == '\0')
        return (char *)str;

    const char *strFound = NULL;
    const char *cursor = str;

    /*Check for occurence of first character of substring.*/
    while (*cursor != '\0')
    {
        if (*cursor != *sub)
            cursor++;
        else
        {
            /*Substring might be present.*/
            strFound = cursor;
            const char *sub_cursor = sub;
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
                return (char *)strFound;

            cursor++;
        }
    }
    return NULL;
}

/**
@brief  Tokenize string using a delimiter.
@note   Maintains internal static state across calls.
*/
char *StrTok(char *str, char dl)
{
    /*Check for NULL input.*/
    static char *start = NULL;
    if (str != NULL)
        start = str;
    if (start == NULL)
        return NULL;

    // Skip Leading Delimiters
    while (*start == dl)
        start++;

    // Check if input string ends with delimiter, then return NULL.
    if (*start == '\0')
        return NULL;

    char *token = start;

    while (*start != dl && *start != '\0')
        start++;

    if (*start != '\0')
        *(start++) = '\0';

    else
    { // End of string is reached.
        start = NULL;
    }

    return token;
}

/**
@brief  Convert hex string to unsigned integer.
@return Converted value, or UINT_MAX on overflow.
*/
unsigned int StrHexToInt(const char *str)
{
    unsigned int result = 0;
    if (str == NULL)
        return result;

    const char *cursor = str;

    while (*cursor != '\0')
    {
        if (*cursor > '0' && *cursor <= '9')
            break;
        else if (*cursor >= 'A' && *cursor <= 'F')
            break;
        else if (*cursor >= 'a' && *cursor <= 'f')
            break;
        else
            cursor++;
    }

    /*No digits in the string*/
    if (*cursor == '\0')
        return result;

    /*Start converting till the string is valid.*/
    while (*cursor != '\0')
    {
        unsigned int digit;

        if (*cursor >= '0' && *cursor <= '9')
            digit = *cursor - '0';
        else if (*cursor >= 'A' && *cursor <= 'F')
            digit = 10 + (*cursor - 'A');
        else if (*cursor >= 'a' && *cursor <= 'f')
            digit = 10 + (*cursor - 'a');
        else
            break;

        // Overflow check before updating result
        if (result > (UINT_MAX - digit) / 16)
            return UINT_MAX;

        result = result * 16 + digit;
        cursor++;
    }
    return result;
}