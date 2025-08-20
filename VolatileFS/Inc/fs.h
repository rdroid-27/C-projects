#ifndef __FS_H__
#define __FS_H__

#include <stdio.h>
#include <string.h>

#ifdef DEBUG
#define DEBUG_PRINT(fmt, ...) printf("\033[0;32m[DEBUG] " fmt "\033[0m\n", ##__VA_ARGS__)
#else
#define DEBUG_PRINT(fmt, ...)
#endif



extern Directory *root;
extern Directory *curr;

// Generic Node structure
typedef struct node
{
    void *data;
    struct node *next;

} Node;

// File Structure
typedef struct file_struct
{
    char name[20];
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

#endif //__FS_H__