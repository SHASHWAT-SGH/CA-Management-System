#include <stdio.h>
#include <string.h>

void signup()
{
    char username[20];
    char password[10];
    char filePath[50] = "./UserData/";
    printf("\nEnter user name: ");
    fflush(stdin);
    gets(username);
    printf("Enter password: ");
    fflush(stdin);
    gets(password);

    strcat(filePath, username);
    strcat(filePath, ".txt");
    // puts(filePath);
    if (fopen(filePath, "r") == NULL)
    {
        FILE *fp = fopen(filePath, "w");
        fprintf(fp, password);
        fclose(fp);
        puts("\n******** User created. ********\n");
    }
    else
    {
        puts("\n******** User already exists! Change username. ********\n");
    }
}