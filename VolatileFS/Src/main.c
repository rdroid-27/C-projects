#include "fs.h"

int main()
{

    // // 1. Check for init Function
    // Fs_Init();
    // Fs_Init();

    // 2. Check for Create File function
    Fs_Init();

    Fs_CreateFile("test.txt");
    Fs_CreateFile("data.bin");
    Fs_CreateFile("test.txt"); // duplicate check
    Fs_DeleteFile("data.bin");
    Fs_ListFiles();

    return 0;
}
