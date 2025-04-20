#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>

#define MAX_USERS 10
#define CREDENTIALS_LENGTH 30

// User Structure
typedef struct
{
    char username[CREDENTIALS_LENGTH];
    char passwd[CREDENTIALS_LENGTH];
} USER;

USER users[MAX_USERS];
int user_count = 0;

// Function prototypes
void clear_screen();
void fix_fgets_input(char *);
void input_credentials(char *, char *);
void register_user();
int login_user();

int main()
{
    while (1)
    {
        // Basic UI
        printf("!!Hello User!!\n");
        printf("1. Register \n2. Login \n3. Exit\n");
        int choice;
        printf("Select an Option: ");
        scanf("%d", &choice);
        getchar(); // Remove the Enter(\n) from input buffer
        int user_index;

        switch (choice)
        {
        case 1:
            clear_screen();
            register_user();
            break;
        case 2:

            user_index = login_user();
            if (user_index >= 0)
            {
                printf("\nLogin Successfull! Welcome %s!\n", users[user_index].username);
                sleep(2);
                clear_screen();
            }
            else
            {
                printf("Login Failed! Invalid username and password!");
                sleep(1);
                clear_screen();
            }
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            sleep(1);
            clear_screen();
            break;
        }
    }
    return 0;
}

// User Registration
void register_user()
{
    if (user_count == MAX_USERS)
    {
        printf("Maximum %d users are supported, no more registrations allowed!\n");
        return;
    }
    else
    {
        int new_index = user_count;
        printf("Register a new user ==>\n");
        input_credentials(users[new_index].username, users[new_index].passwd);
        printf("\nRegistration Successful!\n");
        user_count++;
        sleep(1);
        clear_screen();
    }
}

// User Login
int login_user()
{
    char username[CREDENTIALS_LENGTH], password[CREDENTIALS_LENGTH];
    printf("Enter Your Credentials ==>\n");
    input_credentials(username, password);

    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].passwd) == 0)
        {
            return i;
        }
    }
    return -1;

    sleep(1);
    clear_screen();
}

// Masked Password
void input_credentials(char *username, char *passwd)
{
    printf("Enter Username: ");
    fgets(username, CREDENTIALS_LENGTH, stdin);
    fix_fgets_input(username);

    printf("Enter Password: ");
    fflush(stdout);

    /* For Linux Based Systems
    // Change terminal Properties
    struct termios old_props, new_props;
    tcgetattr(STDIN_FILENO, &old_props);
    new_props = old_props;
    new_props.c_lflag = ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_props);
    -- Logic --
    tcsetattr(STDIN_FILENO, TCSANOW, &old_props);
    */

    char ch;
    int i = 0;
    while ((ch = _getch()) != '\r')
    {
        if ((ch == '\b' || ch == 127) && i > 0)
        {
            i--;
            printf("\b \b");
        }
        else if (i < CREDENTIALS_LENGTH && ch != '\b' && ch != 127)
        {
            passwd[i++] = ch;
            printf("*");
        }
    }
    passwd[i] = '\0';
}

// fgets() takes Enter or Tab as input and appends it to the string, to solve this problem we will take the \n and replace it with \0.
void fix_fgets_input(char *string)
{
    int index = strcspn(string, "\n");
    string[index] = '\0';
}

// Clear the screen
void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
