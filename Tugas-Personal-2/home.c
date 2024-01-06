#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For system function

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

struct User
{
    char username[50];
    char password[50];
    char role[10]; // New field for user role
};

void clearScreen()
{
    system(CLEAR);
}

void registerUser(struct User *users, int *userCount)
{
    do
    {
        printf("Enter username: ");
        scanf("%s", users[*userCount].username);

        // Check if the username already exists
        int usernameExists = 0;
        for (int i = 0; i < *userCount; i++)
        {
            if (strcmp(users[i].username, users[*userCount].username) == 0)
            {
                printf("Username already in use. Please choose a different username.\n");
                usernameExists = 1;
                break; // Exit the loop to allow the user to retry
            }
        }

        if (!usernameExists)
            break; // Exit the loop if the username is unique

    } while (1); // Loop until a unique username is entered

    printf("Enter password: ");
    scanf("%s", users[*userCount].password);

    strcpy(users[*userCount].role, "user"); // Default role is "user"

    (*userCount)++;

    FILE *file = fopen("users.txt", "a");
    if (file != NULL)
    {
        fprintf(file, "%s %s %s\n", users[*userCount - 1].username, users[*userCount - 1].password, users[*userCount - 1].role);
        fclose(file);
        printf("Registration successful!\n");
    }
    else
    {
        printf("Error opening file for writing.\n");
    }
}

int authenticateUser(struct User *users, int userCount, char *username, char *password, char *role)
{
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            strcpy(role, users[i].role);
            return 1; // Authentication successful
        }
    }
    return 0; // Authentication failed
}

void performUserActions()
{
    clearScreen();
    printf("Selamat Datang Pada Sistem Laporan Keungan Toko BSC\n");
    printf("Harap meminta role admin kepada Admin untuk melihat laporan. Untuk pengetesan, Gunakan\n");
    printf("\nusername : admin\npassword : admin\nuntuk mengubah role anda.\n\n");
    printf("Press any key to continue...\n");
    getchar(); // Waits for a key press
    getchar(); // Consumes the newline character
}

void performAdminActions(struct User *users, int userCount)
{
    int choice;
    do
    {
        clearScreen();
        printf("==========================\n");
        printf("Welcome! Your role is Admin\n");
        printf("==========================\n\n");
        printf("1. Lihat Laporan Laba Rugi\n");
        printf("2. Lihat Laporan Perubahan Modal\n");
        printf("3. Lihat Laporan Neraca\n");
        printf("4. Ganti Role Pengguna\n");
        printf("5. Logout\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            char tempChoice;
            do
            {
                clearScreen();
                printf("\nThis is Laporan Laba Rugi Page\n\n");
                printf("Go Back (Y/N)? ");
                scanf(" %c", &tempChoice);
            } while (tempChoice != 'Y' && tempChoice != 'y');
            break;
        }
        case 2:
        {
            char tempChoice;
            do
            {
                clearScreen();
                printf("\nThis is Laporan Perubahan Modal Page\n\n");
                printf("Go Back (Y/N)? ");
                scanf(" %c", &tempChoice);
            } while (tempChoice != 'Y' && tempChoice != 'y');
            break;
        }
        case 3:
        {
            char tempChoice;
            do
            {
                clearScreen();
                printf("\nThis is Laporan Neraca Page\n\n");
                printf("Go Back (Y/N)? ");
                scanf(" %c", &tempChoice);
            } while (tempChoice != 'Y' && tempChoice != 'y');
            break;
        }
        case 4:
        {
            clearScreen();
            char username[50];
            printf("Enter the username to change role: ");
            scanf("%s", username);

            int userIndex = -1;
            for (int i = 0; i < userCount; i++)
            {
                if (strcmp(users[i].username, username) == 0)
                {
                    userIndex = i;
                    break;
                }
            }

            if (userIndex != -1)
            {
                printf("Current Role: %s\n", users[userIndex].role);
                printf("Enter the new role (user/admin): ");
                scanf("%s", users[userIndex].role);
                printf("Role changed successfully!\n");

                // Write the updated user information back to the file
                FILE *file = fopen("users.txt", "w");
                if (file != NULL)
                {
                    for (int i = 0; i < userCount; i++)
                    {
                        fprintf(file, "%s %s %s\n", users[i].username, users[i].password, users[i].role);
                    }
                    fclose(file);
                }
                else
                {
                    printf("Error opening file for writing.\n");
                }
            }
            else
            {
                printf("User not found.\n");
            }
            break;
        }
        case 5:
        {
            printf("Logout Success\n");
            break;
        }
        default:
        {
            printf("Invalid choice! Please input the corresponding choice that is available.\n");
        }
        }
    } while (choice != 5);
}

void processUserActions(char *role, struct User *users, int userCount)
{
    if (strcmp(role, "user") == 0)
    {
        performUserActions();
    }
    else if (strcmp(role, "admin") == 0)
    {
        performAdminActions(users, userCount);
    }
    else
    {
        printf("Unknown role.\n");
    }
}

void loadUsersFromFile(struct User *users, int *userCount)
{
    FILE *file = fopen("users.txt", "r");
    if (file != NULL)
    {
        while (fscanf(file, "%s %s %s", users[*userCount].username, users[*userCount].password, users[*userCount].role) == 3)
        {
            (*userCount)++;
        }
        fclose(file);
    }
    else
    {
        printf("Error opening file for reading.\n");
    }
}

int main()
{
    struct User users[100];
    int userCount = 0;

    loadUsersFromFile(users, &userCount);

    int choice;
    char username[50];
    char password[50];
    char role[10];

    do
    {
        clearScreen();
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            clearScreen();
            registerUser(users, &userCount);
            break;
        case 2:
            printf("Enter username: ");
            scanf("%s", username);

            printf("Enter password: ");
            scanf("%s", password);

            if (authenticateUser(users, userCount, username, password, role))
            {
                processUserActions(role, users, userCount);
                clearScreen();
            }
            else
            {
                printf("Login failed. Invalid username or password.\n");
            }
            break;
        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
