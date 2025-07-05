# 📘 Function Reference: Custom String Library

This document summarizes the purpose and usage of each function implemented in `myString.c`.

---

## 🔤 Basic String Operations

### `size_t StrLen(const char *str)`

Returns the length of a null-terminated string.

### `size_t StrLen_Max(const char *str, size_t MaxSize)`

Returns string length but stops scanning after `MaxSize` characters.

### `char *StrDup(const char *str)`

Allocates new memory and duplicates the string.

### `char *StrCpy(char *dest, const char *src)`

Copies `src` string into `dest`. Assumes enough space.

### `char *StrNCpy(char *dest, const char *src, size_t n)`

Copies at most `n` characters from `src` to `dest`, padding with `\0` if needed.

### `char *StrJoin(const char *str1, const char *str2)`

Returns a newly allocated string that is the concatenation of `str1` and `str2`.

### `char *StrCat(char *dest, const char *src)`

Appends `src` at the end of `dest`. `dest` must have enough space.

### `int StrCmp(const char *lhs, const char *rhs)`

Compares two strings lexicographically. Returns difference between first mismatched characters.

### `char *StrChr(const char *str, char c)`

Returns pointer to first occurrence of character `c` in `str`, or `NULL`.

---

## 🧩 Advanced Utilities

### `char **StrSplit(const char *str, char dl)`

Splits `str` by delimiter `dl` into a NULL-terminated array of strings.

### `char *StrTrim(const char *str)`

Trims leading and trailing whitespace. Returns a newly allocated trimmed string.

### `void StrRev(char *str)`

Reverses the string in-place.

### `void StrReplace(char *str, char oldChar, char newChar)`

Replaces every occurrence of `oldChar` with `newChar` in-place.

### `long StrToInt(const char *str)`

Converts string to signed integer. Handles optional whitespace, signs, and stops at invalid input.

### `char *StrStr(const char *str, const char *sub)`

Returns a pointer to the first occurrence of substring `sub` inside `str`. Returns `NULL` if not found.

### `char *StrTok(char *str, char dl)`

Tokenizes a string using `dl` as delimiter. Mimics `strtok()` with static internal pointer.

### `unsigned int StrHexToInt(const char *str)`

Converts a hex string (e.g., `"0x1A"`, `"FF"`) to unsigned integer. Skips invalid prefix characters and handles overflow.

---

> 🧠 Tip: All memory-allocating functions should be paired with appropriate `free()` calls by the user.

---

This library is suitable for bare-metal, embedded, or minimal libc environments.
