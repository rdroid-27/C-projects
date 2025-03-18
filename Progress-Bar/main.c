#include <stdio.h>

const int BAR_LENGTH = 50;

typedef struct
{
    int id;
    int progress;
    int speed;
}Task;

void print_bar(int id, int progress);

void main()
{
    int id = 3, progress = 40;
    print_bar(1, 25);
    print_bar(3, 75);
    print_bar(5, 65);
    print_bar(0, 55);
    print_bar(9, 0);
}

void print_bar(int id, int progress)
{

    int bars_to_show = (progress * BAR_LENGTH) / 100;

    printf("Task %d:  [", id);
    for (int i = 0; i < BAR_LENGTH; i++)
    {
        if (i < bars_to_show)
            printf("=");
        else
            printf(" ");
    }
    printf("] %d%%\n", progress);
}