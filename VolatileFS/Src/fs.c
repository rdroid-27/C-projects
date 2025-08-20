#include "fs.h"

Directory *curr = NULL;
Directory *root = NULL;

void Fs_Init(void)
{
    if (root)
    {
        DEBUG_PRINT("File system Already Initialized!");
    }
    else
    {
        root = malloc(sizeof(Directory));
        strcpy(root->name, "/");
        root->parentDir = NULL;
        root->subDir = NULL;
        root->Files = NULL;
        curr = root;
        DEBUG_PRINT("File system initialized at %p", root);
    }
}