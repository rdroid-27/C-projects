#ifndef __FS_H__
#define __FS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef DEBUG
#define DEBUG_PRINT(fmt, ...) printf("\033[0;32m[DEBUG]\033[0m " fmt "\n", ##__VA_ARGS__)
#else
#define DEBUG_PRINT(fmt, ...)
#endif
#define ERROR_PRINT(fmt, ...) printf("\033[0;31m[ERROR]\033[0m " fmt "\n", ##__VA_ARGS__)
#define WARNING_PRINT(fmt, ...) printf("\033[0;33m[WARNING]\033[0m " fmt "\n", ##__VA_ARGS__)
#define INFO_PRINT(fmt, ...) printf("\033[0;34m" fmt "\033[0m ", ##__VA_ARGS__)

// Generic Node structure
typedef struct node
{
    void *data;
    struct node *next;

} Node;

// File Structure
typedef struct file_struct
{
    char *name;
} File;

// Directory Structure
typedef struct folder_struct
{
    char name[20];
    Node *Files;
    Node *subDir;
    struct folder_struct *parentDir;

} Directory;

// File System Initialization
void Fs_Init(void);
// File Creation
int Fs_CreateFile(const char *name);
// List all Files in the Directoy (ls)
void Fs_ListFiles(void);
// Remove a file (rm)
int Fs_DeleteFile(const char *name);

extern Directory *root;
extern Directory *curr;

#endif //__FS_H__