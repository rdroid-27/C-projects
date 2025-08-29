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

// Create a new File under current Directory
int Fs_CreateFile(const char *name)
{

    if (curr == NULL)
    {
        INFO_PRINT("Directory does not exists!\n");
        return -1;
    }

    // Check for files with same names
    for (Node *crusor = curr->Files; crusor != NULL; crusor = crusor->next)
    {
        File *f = (File *)(crusor->data);
        if (strcmp(f->name, name) == 0)
        {
            ERROR_PRINT("File Already Exists!");
            return -1;
        }
    }

    // Allocate a new File
    File *newFile = malloc(sizeof(File));
    if (!newFile)
    {
        ERROR_PRINT("File cannot be allocated!");
        return -1;
    }
    newFile->name = malloc(strlen(name) + 1);
    if (!newFile->name)
    {
        DEBUG_PRINT("File Name cannot be allocated!");
        ERROR_PRINT("Cannot create a new file!");
        free(newFile);
        return -1;
    }
    strcpy(newFile->name, name);

    // Add the File to directory
    Node *newFileNode = malloc(sizeof(Node));
    newFileNode->data = newFile;
    newFileNode->next = NULL;

    if (!curr->Files)
    {
        // First File of that directory
        curr->Files = newFileNode;
    }
    else
    {
        // Add file to existing directory files
        Node *cursor = curr->Files;
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
        }
        cursor->next = newFileNode;
    }

    DEBUG_PRINT("File '%s' created inside '%s'", name, curr->name);

    return 0;
}

// List all the files of current Directory
void Fs_ListFiles(void)
{
    if (curr == NULL)
    {
        INFO_PRINT("Directory does not exists!\n");
        return;
    }
    if (curr->Files == NULL)
    {
        INFO_PRINT("Directory is empty!\n");
        return;
    }
    INFO_PRINT("%s:\n", curr->name);
    for (Node *cursor = curr->Files; cursor != NULL; cursor = cursor->next)
    {
        File *f = (File *)(cursor->data);
        printf("%s\t", f->name);
    }
    printf("\n");
}

// Delete a File with given Name
int Fs_DeleteFile(const char *name)
{
    if (curr == NULL)
    {
        INFO_PRINT("Directory does not exists!\n");
        return -1;
    }

    if (curr->Files == NULL)
    {
        INFO_PRINT("Directory is empty!\n");
        return -1;
    }

    Node *c = curr->Files;
    Node *p = NULL;

    // Delete the File
    if (!strcmp(((File *)c->data)->name, name))
    {
        if (((Node *)curr->Files)->next)
        {
            curr->Files = ((Node *)curr->Files)->next;
            DEBUG_PRINT("'%s' has been Deleted!", ((File *)c->data)->name);
            free(((File *)c->data)->name);
            free((File *)c->data);
            free(c);
            c = curr->Files;
        }
        else
        {
            DEBUG_PRINT("'%s' has been Deleted!", ((File *)c->data)->name);
            free(((File *)c->data)->name);
            free((File *)c->data);
            free(c);
        }
        return 0;
    }

    while (c->next && strcmp(((File *)c->next)->name, name))
    {
        c = c->next;
    }
    if (!c->next)
    {
        printf("No such File exists!\n");
        DEBUG_PRINT("FILE '%s' does not exists!", name);
        return -1;
    }

    p = c;
    c = c->next;
    if (!c->next)
    {
        p->next = NULL;
        DEBUG_PRINT("'%s' has been Deleted!", ((File *)c->data)->name);
        free(((File *)c->data)->name);
        free((File *)c->data);
        free(c);
        return 0;
    }

    p->next = c->next;
    DEBUG_PRINT("'%s' has been Deleted!", ((File *)c->data)->name);
    free(((File *)c->data)->name);
    free((File *)c->data);
    free(c);
    return 0;
}
