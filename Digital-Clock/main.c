#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void get_time(char *, int);
void get_date(char *);
void input_format(int *);
void clear_screen();

void main()
{
    char time[50], date[100];
    int format;
    input_format(&format);

    while (1)
    {
        clear_screen();
        get_time(time, format);
        get_date(date);

        printf("\nCurrent Time: %s\n", time);
        printf("Date        : %s\n", date);
        sleep(1);
    }
}

void input_format(int *format)
{
    printf("\nChoose the time format:");
    printf("\n1. 24 Hour format \n2. 12 Hour Format (Default) \nMake a choice (1/2) ");
    scanf("%d", format);
}

void get_time(char *buffer, int format)
{
    time_t rawTime;
    struct tm *current_time;

    time(&rawTime);
    current_time = localtime(&rawTime);
    if ((format) == 1)
        strftime(buffer, 50, "%H:%M:%S", current_time);
    else
        strftime(buffer, 50, "%I:%M:%S %p", current_time);
}

void get_date(char *buffer)
{
    time_t rawTime;
    struct tm *current_time;

    time(&rawTime);
    current_time = localtime(&rawTime);

    strftime(buffer, 100, "%A %d %B, %Y", current_time);
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}